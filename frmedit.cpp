#include <QtWidgets>
#include "frmedit.h"
#include "ui_frmedit.h"

frmEdit::frmEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmEdit)
{
    ui->setupUi(this);

    m_tableSize = 20;
    base_url = "http://labbola-new.wiradipa.com/application/";
    initializeTable();

//    ui->tableView->setModel(&m_model);

    //ui->tableView->verticalHeader()->hide();

    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickTable(QModelIndex)));
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(on_tableSelect(QModelIndex)));
    connect(ui->moveUpButton,SIGNAL(clicked()),this,SLOT(moveUp()));
    connect(ui->moveDownButton,SIGNAL(clicked()),this,SLOT(moveDown()));
    connect(ui->colorTeamButton,SIGNAL(clicked()),this,SLOT(changeColorTeam()));

    connect(this,SIGNAL(siapAccept()), this, SLOT(accept()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    m_colorTeam = QColor(255,255,254,255);
}

frmEdit::~frmEdit()
{
    delete ui;
}

void frmEdit::initializeTable()
{
    m_model.setColumnCount(4);
    m_model.setRowCount(0);
    m_model.setHeaderData(0, Qt::Horizontal, QObject::tr("Number"));
    m_model.setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    m_model.setHeaderData(2, Qt::Horizontal, QObject::tr("Team"));
//    m_model.setHeaderData(3, Qt::Horizontal, QObject::tr("Position"));
    m_model.setHeaderData(3, Qt::Horizontal, QObject::tr("MOP"));

    for (int i=0; i<m_tableSize; i++){
        m_model.insertRow(i);
        m_model.setData(m_model.index(i, 0), QString::number(i+1));
        m_model.setData(m_model.index(i, 1), (QString("Player")+QString::number(i+1)));
        m_model.setData(m_model.index(i, 2), "");
//        m_model.setData(m_model.index(i, 3), "none");
        if(i<11){
            m_model.setData(m_model.index(i, 3), "90");
        } else {
            m_model.setData(m_model.index(i, 3), "0");
        }
    }

    QStandardItemModel m_model2;
    m_model2.setColumnCount(4);
    m_model2.setRowCount(0);
    m_model2.setHeaderData(0, Qt::Horizontal, QObject::tr("Number"));
    m_model2.setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    m_model2.setHeaderData(2, Qt::Horizontal, QObject::tr("Team"));
//    m_model2.setHeaderData(3, Qt::Horizontal, QObject::tr("Position"));
    m_model2.setHeaderData(3, Qt::Horizontal, QObject::tr("MOP"));

    for (int i=0; i<m_tableSize; i++){
        m_model2.insertRow(i);
        m_model2.setData(m_model2.index(i, 0), QString::number(i+1));
        m_model2.setData(m_model2.index(i, 1), (QString("Player")+QString::number(i+1)));
        m_model2.setData(m_model2.index(i, 2), "");
//        m_model2.setData(m_model2.index(i, 3), "none");
        if(i<11){
            m_model2.setData(m_model2.index(i, 3), "90");
        }else {
            m_model2.setData(m_model2.index(i, 3), "0");
        }
//        if (i<11)
//                m_model.setData(m_model.)
    }
    ui->tableView->setModel(&m_model);
}

void frmEdit::on_tableSelect(QModelIndex ind)
{
    int selectedRow = ind.row();
//    ui->label->setText(QString::number(selectedRow));
    ui->tableView->selectRow(selectedRow);
}

void frmEdit::moveUp()
{
/* pindahin row ke atas */
    QModelIndexList idSelect = ui->tableView->selectionModel()->selectedIndexes();
    int row = idSelect.at(0).row();


    if (idSelect.count()<=0 || row == 0)
        return;

    playerStruct playerRow;
    playerRow.nomor = ui->tableView->model()->index(row-1,0).data().toInt();
    playerRow.nama  = ui->tableView->model()->index(row-1,1).data().toString();
//    playerRow.posisi= ui->tableView->model()->index(row-1,3).data().toString();
    playerRow.mop   = ui->tableView->model()->index(row-1,3).data().toString();

    m_model.setData(m_model.index(row-1, 0), ui->tableView->model()->index(row,0).data().toString().toStdString().c_str());
    m_model.setData(m_model.index(row-1, 1), ui->tableView->model()->index(row,1).data().toString());
//    m_model.setData(m_model.index(row-1, 3), ui->tableView->model()->index(row,3).data().toString());
    m_model.setData(m_model.index(row-1, 3), ui->tableView->model()->index(row,3).data().toString());
    m_model.setData(m_model.index(row, 0), QString::number(playerRow.nomor));
    m_model.setData(m_model.index(row, 1), playerRow.nama);
//    m_model.setData(m_model.index(row, 3), playerRow.posisi);
    m_model.setData(m_model.index(row, 3), playerRow.mop);

    //selection ikut pindah ke atas
    ui->tableView->selectRow(row-1);

    //ui->label->setText(QString::number(idSelect.at(0).row()));

}

void frmEdit::moveDown()
{
    QModelIndexList idSelect = ui->tableView->selectionModel()->selectedIndexes();
    int row = idSelect.at(0).row();

    if (idSelect.count()<=0 || row == m_model.rowCount()-1)
        return;

    playerStruct playerRow;
    playerRow.nomor = ui->tableView->model()->index(row+1,0).data().toInt();
    playerRow.nama  = ui->tableView->model()->index(row+1,1).data().toString();
//    playerRow.posisi= ui->tableView->model()->index(row+1,3).data().toString();
    playerRow.mop   = ui->tableView->model()->index(row+1,3).data().toString();

    m_model.setData(m_model.index(row+1, 0), ui->tableView->model()->index(row,0).data().toString().toStdString().c_str());
    m_model.setData(m_model.index(row+1, 1), ui->tableView->model()->index(row,1).data().toString());
//    m_model.setData(m_model.index(row+1, 3), ui->tableView->model()->index(row,3).data().toString());
    m_model.setData(m_model.index(row+1, 3), ui->tableView->model()->index(row,3).data().toString());
    m_model.setData(m_model.index(row, 0), QString::number(playerRow.nomor));
    m_model.setData(m_model.index(row, 1), playerRow.nama);
//    m_model.setData(m_model.index(row, 3), playerRow.posisi);
    m_model.setData(m_model.index(row, 3), playerRow.mop);

    //selection ikut pindah ke atas
    ui->tableView->selectRow(row+1);
}

void frmEdit::changeColorTeam()
{
    m_colorTeam = QColorDialog::getColor(m_colorTeam, this);

    if (m_colorTeam.isValid()) {
//        colorLabel->setText(color.name());
//        colorLabel->setPalette(QPalette(color));
        ui->colorTeamButton->setPalette(QPalette(m_colorTeam));  //setAutoFillBackground(true);
    }
}

int frmEdit::getPlayerNumber(int tombol)
{
    int tempno = ui->tableView->model()->index(tombol,0).data().toInt();
    return tempno;
}

QString frmEdit::getPlayerNumString(int tombol)
{
    QString tempno = ui->tableView->model()->index(tombol,0).data().toString();
    return tempno;
}

QString frmEdit::getPlayerPosition(int tombol)
{
    QString tempno = ui->tableView->model()->index(tombol,3).data().toString();
    return "none";
}

QString frmEdit::getPlayerMop(int tombol)
{
    QString tempno = ui->tableView->model()->index(tombol,3).data().toString();
    return tempno;
}

QString frmEdit::getPlayerTeam(int tombol)
{
    QString tempno = ui->tableView->model()->index(tombol,2).data().toString();
    return tempno;
}

QString frmEdit::getPlayerName(int tombol)
{
    QString tempno = ui->tableView->model()->index(tombol,1).data().toString();
    return tempno;
}

QString frmEdit::getTeamName()
{
    return m_nameTeam;
}

QString frmEdit::getTeamID()
{
    return m_idTeam;
}

QString frmEdit::getMacthID()
{
    return m_idMatch;
}

QColor frmEdit::getTeamColor()
{
    //qDebug(QString::number(m_colorTeam.rgba()).toLatin1());
    return m_colorTeam;
}

void frmEdit::on_nameTeamEdit_textChanged(QString )
{
    m_nameTeam = ui->nameTeamEdit->text();
}

void frmEdit::on_idTeamEdit_textChanged(QString ){
    m_idTeam = ui->idTeamEdit->text();
}
void frmEdit::on_idMatchEdit_textChanged(QString ){
    m_idMatch = ui->idMatchEdit->text();
}

void frmEdit::on_buttonBox_accepted()
{
    int cekEmptyCell = 0;
    for (int row=0; row < 11; row++) {
        for(int col=0; col<2; col++) {
            if (ui->tableView->model()->index(row, col).data().toString().size()<=0) {
//                qDebug("row %d col %d",row,col);
                cekEmptyCell += 1;
            }
        }
    }
    if ((m_colorTeam == QColor(255,255,254,255)) || ui->nameTeamEdit->text().count() <= 0 || ui->idTeamEdit->text().count() <= 0 || ui->idMatchEdit->text().count() <= 0)
    {
        qDebug("color atw name kosong");
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(this, tr("Alert"), tr("color box or name box is empty"));
        return;
    }
    else if(cekEmptyCell >=1)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Are you sure?"),
                                        tr("name of main player is empty,are you sure you want to continue with this?"),
                                        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if (reply == QMessageBox::Yes)
            emit siapAccept();
        else if (reply == QMessageBox::No)
            return;
        else
            return;
    }
    else
    {
        for (int i=0; i<m_tableSize; i++){

            m_model.setData(m_model.index(i, 0), ui->tableView->model()->index(i,0).data().toString().toStdString().c_str());
            m_model.setData(m_model.index(i, 1), ui->tableView->model()->index(i,1).data().toString());
            m_model.setData(m_model.index(i, 2), m_nameTeam);
//            m_model.setData(m_model.index(i, 3), ui->tableView->model()->index(i,3).data().toString());
            m_model.setData(m_model.index(i, 3), ui->tableView->model()->index(i,3).data().toString());
        }
        ui->tableView->setModel(&m_model);
        emit siapAccept();
    }

}


void frmEdit::doubleClickTable(QModelIndex val){
    int col = val.column();
    int row = val.row();
    bool ok;
    int i;
    QString str;
    QStringList items;
    items << tr("none") << tr("GK") << tr("CB") << tr("LB") << tr("RB") << tr("CM") << tr("LM") << tr("RM")<< tr("SS") << tr("CF") << tr("Striker");

    if (col == 0){
        i = QInputDialog::getInt(this, tr("Insert number"), tr(""), 1, 1, 100, 1, &ok);
        if (ok)
            m_model.setData(m_model.index(row,col), QString::number(i));
        else
            m_model.setData(m_model.index(row,col),ui->tableView->model()->index(row,col).data().toString());
    }
    else if (col == 1){
        str = QInputDialog::getText(this, tr("Insert Name"), tr("Name:"), QLineEdit::Normal, ui->tableView->model()->index(row,col).data().toString(), &ok);
        if (ok)
            m_model.setData(m_model.index(row,col), str);
        else
            m_model.setData(m_model.index(row,col),ui->tableView->model()->index(row,col).data().toString());
    }
//    else if (col == 3){
//        str = QInputDialog::getItem(this, tr("Insert Position"), tr("Position:"), items, 0, false, &ok);
//        if (ok && !str.isEmpty())
//            m_model.setData(m_model.index(row,col), str);
//        else
//            m_model.setData(m_model.index(row,col),ui->tableView->model()->index(row,col).data().toString());
//    }
    else if (col == 3){
        i = QInputDialog::getInt(this, tr("Insert mop"), tr(""), 90, 1, 90, 1, &ok);
        if (ok)
            m_model.setData(m_model.index(row,col), QString::number(i));
        else
            m_model.setData(m_model.index(row,col),ui->tableView->model()->index(row,col).data().toString());
    }
//    ui->tableView->setModel(&m_model);

}


int frmEdit::substitute(int mainNumber, int subsNumber){
    /* substitusi nomer list dari pemain inti dengan nomer inti di kursi cadangan (bukan nomer punggung) */
    // index ngikutin substitusi combobox
    QStandardItemModel tempModel;
    qDebug("main%d and subs%d %d dan %d",
           mainNumber,subsNumber,
           m_model.index(mainNumber,0).data().toInt(),
           m_model.index(subsNumber,0).data().toInt());
    tempModel.insertRow(0,m_model.takeRow(mainNumber));
    qDebug("substituteModel %d ",tempModel.index(0,0).data().toInt());
    qDebug("with %d ",m_model.index(subsNumber-1,0).data().toInt());
    m_model.insertRow(mainNumber,m_model.takeRow(subsNumber-1));

    m_model.insertRow(subsNumber, tempModel.takeRow(0));
    ui->tableView->setModel(&m_model);


    return mainNumber;
}

int frmEdit::getSizePlayer(){
    int baris = m_model.rowCount();
    bool out = false;
    int i = 12;
    while(!(out || i>baris)){
        if (m_model.index(i-1,0).data().isNull() || m_model.index(i-1,1).data().isNull())
            out = true;
        i++;
    }
    return i-1;
}

void frmEdit::on_loadButton_released()
{
    loadProfile();
}

void frmEdit::on_saveButton_released()
{
    saveProfile();
}

int frmEdit::saveProfile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("*.csv"));
    if (fileName.isEmpty())
        return 0;


    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly)) {
        QString textnya="";
        textnya = "" + m_nameTeam + ",c"+ QString::number(m_colorTeam.rgba()) +"\n";// + m_colorTeam.rgb() + "\n";
        file.write(textnya.toStdString().c_str());

        for(int row = 0; row < m_model.rowCount(); row ++) {
            textnya = "";
            for(int col = 0; col < m_model.columnCount(); col ++) {
                if(col > 0){

                    textnya = textnya + "," + m_model.item(row, col)->text() + "";
                }
                else
                    textnya = m_model.item(row, col)->text();
            }
            textnya = textnya + "\n";
            file.write(textnya.toStdString().c_str());
        }
        file.close();
    }
}

void frmEdit::loadProfile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load File"), "", tr("*.csv;;*.profil"));
    if (fileName.isEmpty())
        return;


    QStandardItemModel m_model2;
    QColor colorTeam;
    QString nameTeam;

    QFile file(fileName);

    if(file.open(QFile::ReadOnly)) {
//        QStandardItemModel modelTemp;
//        modelTemp.clear();
//        modelTemp.setColumnCount(3);
//        modelTemp.setRowCount(0);
//        modelTemp.setHeaderData(0, Qt::Horizontal, QObject::tr("Number"));
//        modelTemp.setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
//        modelTemp.setHeaderData(2, Qt::Horizontal, QObject::tr("Team"));
//        modelTemp.setHeaderData(3, Qt::Horizontal, QObject::tr("Position"));
//        m_model.removeRows(0,20);
        //colorTeam = QColor::fromRgba(0);
        nameTeam = "";

//        m_model2.setColumnCount(3);
//        m_model2.setRowCount(0);
//        m_model2.setHeaderData(0, Qt::Horizontal, QObject::tr("Number"));
//        m_model2.setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
//        m_model2.setHeaderData(2, Qt::Horizontal, QObject::tr("Team"));
//        m_model2.setHeaderData(3, Qt::Horizontal, QObject::tr("Position"));
//        m_model2.insertRows(0,20);

        //read process here
        QTextStream stream(&file);
        QString line;

        int baris = 0;

        while(!stream.atEnd())  {

            line = stream.readLine();
            QStringList signtemp = line.split(QRegExp(",\\s?")); //ambil per koma
            QStringList::Iterator iterasi = signtemp.begin();

            if(baris < 1)
            {
                if(signtemp.size() != 1) {
                    if(signtemp.size()==2)
                    {
                        QString warna = signtemp.at(1);
                        qDebug(warna.toLatin1());
                        if (warna.at(0) == 'c')
                            m_colorTeam = QColor::fromRgba(warna.mid(1).toUInt());
                        else
                        {
                            file.close();
                            QMessageBox msg;
                            msg.setInformativeText("File not supported. Color");
                            msg.exec();

                            return;
                        }
                    }
                    else {
                        file.close();
                        QMessageBox msg;
                        msg.setInformativeText("File not supported. Format File");
                        msg.exec();

                        return;
                    }
                }

                if(baris == 0)
                    nameTeam = signtemp.at(0);
//                else
                    //m_colorTeam.fromRgba(QString(signtemp.at(0)));

                baris++;
            }
            else{
                if(signtemp.size() < 3){
                    file.close();
                    QMessageBox msg;
                    msg.setInformativeText("File not supported. signtemp size");
                    msg.exec();
                    return;
                }




                for (int i=0; i<signtemp.size(); i++)
                {
                    m_model.setData(m_model.index(baris-1, i), signtemp.at(i));

                }

                baris++;

            }
            file.close();
//            m_model = modelTemp;
            ui->tableView->setModel(&m_model);
            ui->nameTeamEdit->setText(nameTeam);
            ui->colorTeamButton->setPalette(QPalette(m_colorTeam));
        }


    }

}

void frmEdit::commitChange()
{
    m_nameTeam = ui->nameTeamEdit->text();
//    m_colorTeam = ui->colorTeamButton->palette();

}

void frmEdit::on_saveMopButton_released()
{
    postServer();
}

void frmEdit::setBaseUrl(QString url){
    base_url = url;
}

void frmEdit::setSizePlayer(int size){
    if(m_tableSize != size){
        m_tableSize = size;
        initializeTable();
    }
}

void frmEdit::postServer(){
    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onGetResult(QNetworkReply*)));
    connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));
    QString param_mop = "";
    for (int i=0; i<m_tableSize; i++){
        if(i>0)param_mop=param_mop+",";
        param_mop = param_mop+getPlayerNumString(i)+":"+getPlayerMop(i);
    }
    QString url = base_url+"update_player_mop?match_id="+m_idMatch+"&team_id="+m_idTeam+"&mops="+param_mop;
    mgr->get(QNetworkRequest(QUrl(url)));
}

void frmEdit::onGetResult(QNetworkReply *rep){
    QByteArray bts = rep->readAll();
    QString str(bts);
    QMessageBox msgBox;
    if(str=="OK"){
        msgBox.setText("MOP was successfully saved.");
        msgBox.setStandardButtons(QMessageBox::Ok);
    } else {
        msgBox.setText("Error Connection to Server.");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Retry);
    }
    int ret = msgBox.exec();
    if(ret==QMessageBox::Retry){
        postServer();
    }
}
