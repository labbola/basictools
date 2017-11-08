#include "frmsql.h"
#include "ui_frmsql.h"

frmSQL::frmSQL(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmSQL)
{
    ui->setupUi(this);
}

frmSQL::~frmSQL()
{
    delete ui;
}
