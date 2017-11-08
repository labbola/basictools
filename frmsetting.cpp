#include "frmsetting.h"
#include "ui_frmsetting.h"

frmSetting::frmSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmSetting)
{
    ui->setupUi(this);
    m_jumlahpemain = 11;
    m_totalpemain = 20;
    m_stage = "1st Half";
    m_baseURL = "http://labbola-new.wiradipa.com";
    ui->line_baseURL->setText(m_baseURL);
    ui->spin_totalpemain->setValue(m_totalpemain);
}

frmSetting::~frmSetting()
{
    delete ui;
}

//void frmSetting::on_combo_jumlahpemain_currentIndexChanged(int index)
//{

//}

void frmSetting::on_combo_jumlahpemain_currentIndexChanged(QString n )
{
    m_jumlahpemain = n.toInt();
}

void frmSetting::on_combo_stage_currentIndexChanged(QString s){
    m_stage = s;
}

void frmSetting::on_line_baseURL_textChanged(QString ){
    m_baseURL = ui->line_baseURL->text();
}

void frmSetting::on_spin_totalpemain_valueChanged(int arg1)
{
    m_totalpemain = arg1;
}

int frmSetting::getNumPlayer()
{
    return m_jumlahpemain;
}

int frmSetting::getTotalPlayer()
{
    return m_totalpemain;
}

QString frmSetting::getStage()
{
    return m_stage;
}

QString frmSetting::getbaseURL()
{
    return m_baseURL;
}
