#ifndef LOADWARNINGBOX_H
#define LOADWARNINGBOX_H

#include <QDialog>

namespace Ui {
    class loadWarningBox;
}

class loadWarningBox : public QDialog
{
    Q_OBJECT

public:
    explicit loadWarningBox(QWidget *parent = 0);
    ~loadWarningBox();

private:
    Ui::loadWarningBox *ui;
};

#endif // LOADWARNINGBOX_H
