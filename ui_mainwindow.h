/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 9. Jun 17:29:50 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionZamknij;
    QAction *actionO_programie;
    QAction *actionCreateDatabase;
    QAction *actionO_Qt;
    QAction *actionNowy_komiks;
    QWidget *centralWidget;
    QTableView *tableView;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuPlik;
    QMenu *menuOpcje;
    QMenu *menuPomoc;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(374, 437);
        actionZamknij = new QAction(MainWindow);
        actionZamknij->setObjectName(QString::fromUtf8("actionZamknij"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/menu/ico/system-log-out.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZamknij->setIcon(icon);
        actionO_programie = new QAction(MainWindow);
        actionO_programie->setObjectName(QString::fromUtf8("actionO_programie"));
        actionCreateDatabase = new QAction(MainWindow);
        actionCreateDatabase->setObjectName(QString::fromUtf8("actionCreateDatabase"));
        actionO_Qt = new QAction(MainWindow);
        actionO_Qt->setObjectName(QString::fromUtf8("actionO_Qt"));
        actionNowy_komiks = new QAction(MainWindow);
        actionNowy_komiks->setObjectName(QString::fromUtf8("actionNowy_komiks"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/menu/ico/document-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNowy_komiks->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 351, 141));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 160, 351, 142));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 310, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 374, 18));
        menuPlik = new QMenu(menuBar);
        menuPlik->setObjectName(QString::fromUtf8("menuPlik"));
        menuOpcje = new QMenu(menuBar);
        menuOpcje->setObjectName(QString::fromUtf8("menuOpcje"));
        menuPomoc = new QMenu(menuBar);
        menuPomoc->setObjectName(QString::fromUtf8("menuPomoc"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPlik->menuAction());
        menuBar->addAction(menuOpcje->menuAction());
        menuBar->addAction(menuPomoc->menuAction());
        menuPlik->addAction(actionZamknij);
        menuPlik->addAction(actionNowy_komiks);
        menuOpcje->addAction(actionCreateDatabase);
        menuPomoc->addAction(actionO_programie);
        menuPomoc->addAction(actionO_Qt);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionZamknij);

        retranslateUi(MainWindow);
        QObject::connect(actionZamknij, SIGNAL(triggered(bool)), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionZamknij->setText(QApplication::translate("MainWindow", "Zamknij", 0, QApplication::UnicodeUTF8));
        actionO_programie->setText(QApplication::translate("MainWindow", "O programie", 0, QApplication::UnicodeUTF8));
        actionCreateDatabase->setText(QApplication::translate("MainWindow", "Stw\303\263rz baz\304\231", 0, QApplication::UnicodeUTF8));
        actionO_Qt->setText(QApplication::translate("MainWindow", "O Qt", 0, QApplication::UnicodeUTF8));
        actionNowy_komiks->setText(QApplication::translate("MainWindow", "Nowy komiks", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        menuPlik->setTitle(QApplication::translate("MainWindow", "Plik", 0, QApplication::UnicodeUTF8));
        menuOpcje->setTitle(QApplication::translate("MainWindow", "Opcje", 0, QApplication::UnicodeUTF8));
        menuPomoc->setTitle(QApplication::translate("MainWindow", "Pomoc", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
