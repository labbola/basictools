#include <QtGui>

#include "frmsubstitute.h"
#include "ui_frmsubstitute.h"

frmSubstitute::frmSubstitute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmSubstitute)
{
    m_totalsubs = 9;
    m_totalsubinit = 9;
    ui->setupUi(this);
    ui->comboBox->clear();
    ui->comboBox_2->clear();

    ui->comboBox->hide();
    ui->comboBox_2->hide();
    ui->groupBox->hide();
    ui->buttonBox->hide();

//    ui->pushButton_s1->hide();
//    ui->pushButton_s2->hide();
//    ui->pushButton_s3->hide();
//    ui->pushButton_s4->hide();
//    ui->pushButton_s5->hide();
//    ui->pushButton_s6->hide();
//    ui->pushButton_s7->hide();
//    ui->pushButton_s8->hide();
//    ui->pushButton_s9->hide();

    m_selected = 0;
    m_selectedSubs = 0;

    for (int i = 0; i < 11; ++i) {
        buttons[i] = new QPushButton();
        connect(buttons[i], SIGNAL(clicked()), this, SLOT(digitClicked()));
//        buttons[i]->setStyleSheet(QString("QPushButton:pressed{background-color: rgb(255,0,0); color: rgb(255,255,255)}"));
    }

    for (int i = 0; i < m_totalsubs; ++i) {
        subsBu[i] = new QPushButton();
        connect(subsBu[i], SIGNAL(clicked()), this, SLOT(subsdigitClicked()));        
    }

    createInit();

//    subsBu[0]->setStyleSheet(QString("background-color: rgb(255,0,0); color: rgb(255,255,255)"));
}

frmSubstitute::~frmSubstitute()
{
    delete ui;
}

void frmSubstitute::addCombo(QString no, QString name){
    QString player;
    player = "(" + no + ") " + name;
    ui->comboBox->addItem(no);

    ui->comboBox->setItemText(ui->comboBox->count()-1,no);


//    qDebug(no.toStdString().c_str());
//    qDebug(ui->comboBox->itemText(ui->comboBox->count()-1).toStdString().c_str());
    //ui->listView->addAction();
}

void frmSubstitute::clearCombo(){
    ui->comboBox->clear();
}

void frmSubstitute::addCombo2(QString no, QString name){
    QString player;
    player = "(" + no + ") " + name;
    ui->comboBox_2->addItem(player);
}

void frmSubstitute::clearCombo2(){
    ui->comboBox_2->clear();
}

void frmSubstitute::on_buttonBox_accepted()
{
//    m_selected = ui->comboBox->currentIndex();
//    m_selectedSubs = ui->comboBox_2->currentIndex();
//    buttons[m_selected]->setStyleSheet(QString("background-color: none"));
//    subsBu[m_selectedSubs]->setStyleSheet(QString("background-color: none"));

    accept();
}

int frmSubstitute::getSubsPlayer1(){
    return m_selected;
}

int frmSubstitute::getSubsPlayer2(){
    return m_selectedSubs;
}

void frmSubstitute::createMain()
{

    QVBoxLayout *layout = new QVBoxLayout;

    if(ui->comboBox->count() == 5)
    {
        for (int i = 5; i<11; i++)
        {
            buttons[i]->hide();
        }
    }
    else if(ui->comboBox->count() == 11)
    {
        //qDebug(QString::number(ui->comboBox->count()).toStdString());
        for (int i = 5; i<11; i++)
        {
            //qDebug("masuk");
            if(buttons[i]->isHidden())
            {
                //qDebug("Show");
                buttons[i]->show();
            }
        }
    }


    for (int i = 0; i < ui->comboBox->count(); i++) {
        //qDebug("createmain");
        buttons[i]->setText(ui->comboBox->itemText(i));
        layout->addWidget(buttons[i]);
    }
    ui->groupBox->setLayout(layout);

}

void frmSubstitute::createInit()
{
    QVBoxLayout *layout = new QVBoxLayout;
    for (int i = 0; i < 11; ++i) {
        buttons[i]->setText("");
        layout->addWidget(buttons[i]);
    }

    ui->groupBox->setLayout(layout);

    QVBoxLayout *layout2 = new QVBoxLayout;
    for (int i = 0; i < m_totalsubs; ++i) {
        subsBu[i]->setText("");
        layout2->addWidget(subsBu[i]);
    }

    ui->groupBox_2->setLayout(layout2);
}

void frmSubstitute::createSubs()
{

//    QVBoxLayout *layout = new QVBoxLayout;

//    int limit = ui->comboBox_2->count();
//    if(limit>9)
//        limit = 9;

    for (int i = 0; i < m_totalsubs; i++) {
//        qDebug(ui->comboBox_2->itemText(i).toStdString().c_str());
        subsBu[i]->setText(ui->comboBox_2->itemText(i));
//        layout->addWidget(subsBu[i]);
    }

//    ui->groupBox_2->setLayout(layout);

}

void frmSubstitute::digitClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    buttons[m_selected]->setStyleSheet(QString("background-color: none"));
    clickedButton->setStyleSheet(QString("background-color: rgb(255,0,0); color: rgb(255,255,255)"));

    QString value = clickedButton->text();

//    qDebug(value.toStdString().c_str());
    m_selected = ui->comboBox->findText(value);
}

void frmSubstitute::subsdigitClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
//    subsBu[m_selectedSubs]->setStyleSheet(QString("background-color: none"));
//    clickedButton->setStyleSheet(QString("background-color: rgb(255,0,0); color: rgb(255,255,255)"));

    QString value = clickedButton->text();

//    qDebug(QString("pressed: " + value).toStdString().c_str());
    m_selectedSubs = ui->comboBox_2->findText(value);

    on_buttonBox_accepted();

}

void frmSubstitute::aturButton(int size)
{
    Q_UNUSED(size);
//    ui->pushButton_s1->setText(ui->comboBox_2->itemText(1));
//    ui->pushButton_s2->setText(ui->comboBox_2->itemText(2));
//    ui->pushButton_s3->setText(ui->comboBox_2->itemText(3));
//    ui->pushButton_s4->setText(ui->comboBox_2->itemText(4));
//    ui->pushButton_s5->setText(ui->comboBox_2->itemText(5));
//    ui->pushButton_s6->setText(ui->comboBox_2->itemText(6));
//    ui->pushButton_s7->setText(ui->comboBox_2->itemText(7));
//    ui->pushButton_s8->setText(ui->comboBox_2->itemText(8));
//    ui->pushButton_s9->setText(ui->comboBox_2->itemText(9));
}

int frmSubstitute::getPlayerindex(QString num)
{
    //qDebug(QString("getindex: " + num).toStdString().c_str());
    int res = ui->comboBox->findText(num);
    return res;
}

void frmSubstitute::on_pushButton_clicked()
{
    reject();
}

void frmSubstitute::setSizeSubs(int size){
    if(m_totalsubs<size){
        for (int i = m_totalsubs; i < size; ++i) {
            if(m_totalsubinit>i){
                subsBu[i]->show();
            } else {
                subsBu[i] = new QPushButton();
                connect(subsBu[i], SIGNAL(clicked()), this, SLOT(subsdigitClicked()));
            }
            ui->groupBox_2->layout()->addWidget(subsBu[i]);
        }
        m_totalsubinit=size;
    }
    if(m_totalsubs>size){
        for (int i = size; i < m_totalsubs; ++i) {
            ui->groupBox_2->layout()->removeWidget(subsBu[i]);
            subsBu[i]->hide();
        }
    }
    m_totalsubs=size;
}
