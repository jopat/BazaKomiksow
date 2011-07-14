#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_firststartwizard.h"
#include "SqLiteMaper.h"

#include <QMessageBox>
#include <QWizard>


/** @file mainwindow.cpp
 * @brief GUI main window source file.
 *
 * A more extensive description of filename.ext.
 */

//=============================================================
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);

    //zaczytanie konfiguracji
    string fileName = "config.conf";
    config = new ConfigManager(fileName);

    //je¿eli konfiguracja istnieje
    if (config -> ReadConfigFile() == ConfigManager::ACTION_OK)
    {
        // SprawdŸ czy istnieje baza
        sqLiteMaper = new SqLiteMaper(config -> configDictionary["DbName"]);

        if (sqLiteMaper -> CheckDatabase())
        {
            if(sqLiteMaper -> Connect())
            {
                // baza danych istnieje i mo¿na nawi¹zaæ po³¹czenie
                ui -> textEdit -> append("Nawi¹za³em po³¹czenie !");
            }
        }
        else
        {
            // baza danych nie istnieje
            // utwórz now¹ bazê danych
            ui -> textEdit -> append(QString::fromStdString(sqLiteMaper -> lastError));
            sqLiteMaper -> CreateDatabase("create.sql");

            // wyœwietl treœæ zapytañ
            for(vector<string>::iterator it = sqLiteMaper->sqlList.begin(); it != sqLiteMaper->sqlList.end(); it++)
            {
                ui -> textEdit -> append(QString::fromStdString(*it));
            }
        }
    }
    // konfiguracja nie istnieje
    else
    {
        QWizard wizard;
        Ui::FirstStartWizard wizardFirstStart;
        wizardFirstStart.setupUi(&wizard);

        if (wizard.exec() == QWizard::Accepted)
        {

        }

        //stwórz domyœln¹ konfiguracjê
        //QMessageBox::warning(this, "Ostrze¿enie", "B³¹d otwierania pliku konfiguracyjnego");
        map<string, string> defaultDeictionary;
        defaultDeictionary["DbName"] = "comics.db";
        config -> SetDefaultConfig(defaultDeictionary);
        config -> SaveConfigFile();
    }
}

//=============================================================
MainWindow::~MainWindow()
{
    delete ui;
    delete config;
    if (sqLiteMaper)
        delete sqLiteMaper;
}

//=============================================================
void MainWindow::on_actionCreateDatabase_triggered()
{
//    QDialog dialog;
//    Ui::CreateDatabase createDatabase;
//    createDatabase.setupUi (&dialog);
//    if (dialog.exec() == QDialog::Accepted)
//    {
//        sqLitemapper = new SqLiteMaper(this, createDatabase.lineEdit -> text());
//    }
}

//=============================================================
void MainWindow::on_actionO_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

//=============================================================
void MainWindow::on_pushButton_clicked()
{

}
