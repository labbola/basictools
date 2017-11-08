#include "loadwarningbox.h"
#include "ui_loadwarningbox.h"

loadWarningBox::loadWarningBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loadWarningBox)
{
    ui->setupUi(this);
}

loadWarningBox::~loadWarningBox()
{
    delete ui;
}
