/********************************************************************************
** Form generated from reading UI file 'createdatabase.ui'
**
** Created: Thu 9. Jun 17:29:50 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEDATABASE_H
#define UI_CREATEDATABASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateDatabase
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateDatabase)
    {
        if (CreateDatabase->objectName().isEmpty())
            CreateDatabase->setObjectName(QString::fromUtf8("CreateDatabase"));
        CreateDatabase->resize(372, 76);
        CreateDatabase->setSizeGripEnabled(false);
        CreateDatabase->setModal(false);
        layoutWidget = new QWidget(CreateDatabase);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 12, 351, 55));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CreateDatabase);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateDatabase, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateDatabase, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateDatabase);
    } // setupUi

    void retranslateUi(QDialog *CreateDatabase)
    {
        CreateDatabase->setWindowTitle(QApplication::translate("CreateDatabase", "Stw\303\263rz now\304\205 baz\304\231", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateDatabase", "Nazwa bazy", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("CreateDatabase", "baza_komiksow.db", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateDatabase: public Ui_CreateDatabase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDATABASE_H
