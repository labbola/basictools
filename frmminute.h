#ifndef FRMMINUTE_H
#define FRMMINUTE_H

#include <QDialog>

namespace Ui {
class frmMinute;
}

class frmMinute : public QDialog
{
    Q_OBJECT

public:
    explicit frmMinute(QWidget *parent = 0);
    ~frmMinute();
    int getMinute();

private:
    Ui::frmMinute *ui;
    int minute;

private slots:
    void on_minuteEdit_textChanged(int );
};

#endif // FRMMINUTE_H
