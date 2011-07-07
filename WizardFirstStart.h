#ifndef WIZARDFIRSTSTART_H
#define WIZARDFIRSTSTART_H

#include <QWizard>

namespace Ui {
    class WizardFirstStart;
}

class WizardFirstStart : public QWizard
{
    Q_OBJECT

public:
    explicit WizardFirstStart(QWidget *parent = 0);
    ~WizardFirstStart();

private:
    Ui::WizardFirstStart *ui;
};

#endif // WIZARDFIRSTSTART_H
