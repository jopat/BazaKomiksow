#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_createdatabase.h"
#include "SqLiteMaper.h"
#include <QMessageBox>

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

    //je�eli konfiguracja istnieje
    if (config -> ReadConfigFile() == ConfigManager::FILE_OK)
    {
        // wy�wietl zaczytan� konfiguracj� - do usuni�cia
        map<string, string>::iterator it;
        for(it = config -> configDictionary.begin(); it != config -> configDictionary.end(); it++)
        {
            ui -> textEdit -> append(QString::fromStdString(it -> first + " = " + it -> second));
        }

        // Sprawd� czy istnieje baza
        sqLiteMaper = new SqLiteMaper(config -> configDictionary["DbName"]);
        if (sqLiteMaper -> CheckDatabase())
        {
            // baza danych istnieje i mo�na nawi�za� po��czenie
            if (sqLiteMaper -> Connect())
            {
                ui -> textEdit -> append("Nawi�za�em po��czenie !");
            }
        }
        else
        {
            // baza danych nie istnieje
            // utw�rz now� baz� danych
            ui -> textEdit -> append(QString::fromStdString(sqLiteMaper -> lastError));
            sqLiteMaper -> CreateDatabase("create.sql");

            // wy�wietl tre�� zapyta�
            for(vector<string>::iterator it = sqLiteMaper->sqlList.begin(); it != sqLiteMaper->sqlList.end(); it++)
            {
                ui -> textEdit -> append(QString::fromStdString(*it));
            }

        }
    }
    // konfiguracja nie istnieje
    else
    {
        //stw�rz domy�ln� konfiguracj�
        QMessageBox::warning(this, "Ostrze�enie", "B��d otwierania pliku konfiguracyjnego");
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
