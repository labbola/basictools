#include "dialogsave.h"
#include "ui_dialogsave.h"

DialogSave::DialogSave(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSave)
{
    ui->setupUi(this);
}

DialogSave::~DialogSave()
{
    delete ui;
}

void DialogSave::showEvent(QShowEvent *){
    ui->lineEdit->setText(".csv");
}

QString DialogSave::getName(){
    return ui->lineEdit->text();
}
