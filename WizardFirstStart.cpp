#include "WizardFirstStart.h"
#include "ui_WizardFirstStart.h"

WizardFirstStart::WizardFirstStart(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::WizardFirstStart)
{
    ui->setupUi(this);
}

WizardFirstStart::~WizardFirstStart()
{
    delete ui;
}
