#include "frmminute.h"
#include "ui_frmminute.h"

frmMinute::frmMinute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmMinute)
{
    ui->setupUi(this);
    minute = 0;
    ui->minuteEdit->setValue(minute);
}

frmMinute::~frmMinute()
{
    delete ui;
}

void frmMinute::on_minuteEdit_textChanged(int ){
    minute = ui->minuteEdit->value();
}

int frmMinute::getMinute()
{
    return minute;
}
