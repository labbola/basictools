#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "simplecrypt.h"
#include <QTime>
#include <QTimer>
#include <QSqlQuery>
#include <QSqlError>
#include <QNetworkInterface>

int MainWindow::mjudul = 1;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    baseURL = "http://labbola-new.wiradipa.com/application/";
    minute = 0;
    siapAct = 0;
    curPlayer = 0;
    isPassing = false;
    isGoal = false;
    sizeUndo = 0;
    startUndo = 0;
    m_jumlahpemain = 11;
    m_totalpemain = 20;
    m_num = "NO";
    stage = "1st half";
    // about keyboard
    m_ctrl = false;
    m_shft = false;
    isChanged = false;
    m_space = false;
    m_idMatch = QString("0");
    m_team1 = QString("team 1");
    m_team2 = QString("team 2");
    m_passingteam = m_team1;
    m_passingfrom = m_team1;
    m_passingto   = m_team1;
    mode = MODE_PLAY;
    undomodel.clear();
    //QMenu *fileMenu = new QMenu(tr("&File"),this);
    //QAction *saveAction = ui->menuFile->addAction(tr("&Save"));
    //saveAction->setShortcuts(QKeySequence::Save);
    // Menu File
    QAction *newAction = ui->menuFile->addAction(tr("&New"));
    QAction *loadAction = ui->menuFile->addAction(tr("&Load"));
    ui->menuFile->addSeparator();
    QAction *quitAction = ui->menuFile->addAction(tr("E&xit"));
    quitAction->setShortcuts(QKeySequence::Quit);
    initialize();
    //    int mjudul = getnumjudul();
    m_appsTitle = "BasicStats v1.0.2";
    QString judul = m_appsTitle + " - Untitled (" + QString::number(MainWindow::mjudul) + ")";
    setWindowTitle(judul);
    connect(this,SIGNAL(tulis(QString)),this,SLOT(on_tulis(QString)));
    //menuBar()->addMenu(fileMenu);
    // Menu Option
    QMenu *optionMenu = new QMenu(tr("&Option"),this);
    QAction *editPlayer = optionMenu->addAction(tr("Edit Team 1"));
    QAction *editPlayer2 = optionMenu->addAction(tr("Edit Team 2"));
    optionMenu->addSeparator();
    QAction *optionSetting = optionMenu->addAction(tr("Preferences"));
    ui->menuBar->addMenu(optionMenu);
    connect(ui->actionSaveCSV,SIGNAL(triggered()),this,SLOT(saveFile()));
    //connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(loadAction, SIGNAL(triggered()), this, SLOT(loadFile()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(editPlayer,SIGNAL(triggered()), this,SLOT(editTeam()));
    connect(editPlayer2,SIGNAL(triggered()), this,SLOT(editTeam2()));
    connect(optionSetting, SIGNAL(triggered()), this, SLOT(preferences()));
    statusBar();
    initPlayer();
    //ui->unDribbleButton->hide();
    ui->penaltyButton->hide();
    ui->StopButton->setDisabled(1);
    ui->PauseButton->setDisabled(1);
    ui->StopButton_2->setDisabled(1);
    ui->PauseButton_2->setDisabled(1);

    time = new QTime;
    time->setHMS(0,0,0);
    QString text = time->toString("hh:mm:ss");
    ui->lcdNumber->display(text);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Filled);
    ui->lcdNumber->setStyleSheet("* { background-color:rgb(199,147,88);color:rgb(255,255,255); padding: 7px}}");

    i=0;
    start = ui->StartButton;
    stop = ui->StopButton;
    pause = ui->PauseButton;
    setminute = ui->SetButton;
    connect(start,SIGNAL(clicked()),this,SLOT(mulai()));
    connect(stop,SIGNAL(clicked()),this,SLOT(berhenti()));
    connect(pause,SIGNAL(clicked()),this,SLOT(tunda()));
    connect(setminute,SIGNAL(clicked()),this,SLOT(ubahmenit()));

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));

    time2 = new QTime;
    time2->setHMS(0,0,0);
    QString injurt = time2->toString("hh:mm:ss");
    ui->lcdNumber_3->display(injurt);
    ui->lcdNumber_3->setStyleSheet("* { background-color:rgb(199,147,88);color:rgb(255,255,255); padding: 7px}}");

    j=0;
    start2 = ui->StartButton_2;
    stop2 = ui->StopButton_2;
    pause2 = ui->PauseButton_2;
    setminute2 = ui->SetButton_2;
    connect (start2,SIGNAL(clicked()),this,SLOT(mulai2()));
    connect (stop2,SIGNAL(clicked()),this,SLOT(berhenti2()));
    connect (pause2,SIGNAL(clicked()),this,SLOT(tunda2()));
    connect(setminute2,SIGNAL(clicked()),this,SLOT(ubahmenit2()));
    timer2 = new QTimer(this);
    connect (timer2,SIGNAL(timeout()),this,SLOT(showTime2()));
    ui->penaltyButton->setVisible(true);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initialize(){
    //m_model = new QStandardItemModel(0,3,this);
    m_model.setColumnCount(8);
    m_model.setRowCount(0);
    m_model.setHeaderData(0,Qt::Horizontal, QObject::tr("No."));
    m_model.setHeaderData(1, Qt::Horizontal, QObject::tr("Jersey\nNumber"));
    m_model.setHeaderData(2, Qt::Horizontal, QObject::tr("Player Name"));
    m_model.setHeaderData(3, Qt::Horizontal, QObject::tr("Team"));
    m_model.setHeaderData(4, Qt::Horizontal, QObject::tr("Action"));
    m_model.setHeaderData(5, Qt::Horizontal, QObject::tr("Num"));
    m_model.setHeaderData(6, Qt::Horizontal, QObject::tr("Player Name "));
    m_model.setHeaderData(7, Qt::Horizontal, QObject::tr("Information"));
    ui->tableView->setModel(&m_model);
    ui->tableView->setColumnWidth(0,30);
    ui->tableView->setColumnWidth(1,53);
    ui->tableView->setColumnWidth(2,150);
    ui->tableView->setColumnWidth(5,40);
    ui->tableView->setColumnWidth(6,150);
    //ui->tableView->resizeColumnsToContents();
    //    item3->setData(0, qVariantFromValue(2));

}
void MainWindow::initPlayer(){
    m_playerList1.clear();
    m_playerList2.clear();
    playerStruct playerlist;
    formSubs1.clearCombo();
    formSubs2.clearCombo();
    int size1 = formEditPlayer.getSizePlayer();
    int size2 = formEditPlayer2.getSizePlayer();
    for (int i = 0; i<m_jumlahpemain; i++){
        playerlist.nomor = formEditPlayer.getPlayerNumber(i);
        playerlist.nama  = formEditPlayer.getPlayerName(i);
        playerlist.team  = m_team1;
        playerlist.posisi= formEditPlayer.getPlayerPosition(i);
        m_playerList1.append(playerlist);
        formSubs1.addCombo(QString::number(playerlist.nomor), playerlist.nama);
        playerlist.nomor = formEditPlayer2.getPlayerNumber(i);
        playerlist.nama  = formEditPlayer2.getPlayerName(i);
        playerlist.team  = m_team2;
        playerlist.posisi= formEditPlayer2.getPlayerPosition(i);
        m_playerList2.append(playerlist);
        formSubs2.addCombo(QString::number(playerlist.nomor), playerlist.nama);
    }
    for(int i=0; i < size1-m_jumlahpemain; i++){
        formSubs1.addCombo2(QString::number(formEditPlayer.getPlayerNumber(i+m_jumlahpemain)),
                            formEditPlayer.getPlayerName(i+m_jumlahpemain));
    }
    for(int i=0; i < size2-m_jumlahpemain; i++){
        formSubs2.addCombo2(QString::number(formEditPlayer2.getPlayerNumber(i+m_jumlahpemain)),
                            formEditPlayer2.getPlayerName(i+m_jumlahpemain));
    }
    //    formSubs1.createMain();
    formSubs1.createSubs();
    //    formSubs2.createMain();
    formSubs2.createSubs();
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox msgBox;
    if(isChanged)
    {
        // kasih warn mau save dulu ga
        msgBox.setText("Quit.");
        msgBox.setInformativeText("Do you want to save?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::No | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret) {
        case QMessageBox::Save:
            if(saveFileOnExit())
                close();
            else
                event->ignore();
            break;
        case QMessageBox::Cancel:
            // Cancel nothing happens
            event->ignore();
            break;
        case QMessageBox::No:
            close();
            break;
        }
    }
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "key " << event->text();
    if (event->key() == Qt::Key_Control)
    {
        m_ctrl = true;
        ui->dribbleButton->setText("Undribble\nCAPS");
        ui->crossButton->setText("Cross Failed\nA");
        ui->headButton->setText("Head Failed\nS");
        ui->tackleButton->setText("Tackle Failed\nD");
        ui->passButton->setText("Pass Failed\nF");
        ui->throwinButton->setText("KickedIn + Pass \nFailed - W");
        ui->freeKickButton->setText("Penalty Missed\n4");
        ui->interceptButton->setText("Intercept Failed\nR");
        ui->assistButton->setText("Fantasy Assist\n2");
        ui->penaltyButton->setText("Saved Penalty\nU");
        ui->goalButton->setText("Goal Header\n3");
    }
    if (event->key() == Qt::Key_Shift)
        m_shft = true;
}
void MainWindow::keyReleaseEvent(QKeyEvent *event){
    // semua keyshortcut action di sini :)
    //    if(event->key()!=Qt::Key_3 && event->key()!=Qt::Key_E && event->key()!=Qt::Key_D)
    //    {
    //        isGoal = false;
    //    }
    if(mode == MODE_PLAY)
    {
        if(!(m_shft || m_ctrl))
        {
            if(event->key()==Qt::Key_A){
                //qDebug("tombol A = cross");
                on_crossButton_released();
            }else if(event->key()==Qt::Key_S){
                //qDebug("tombol S = head");
                on_headButton_released();
            }else if(event->key()==Qt::Key_D){
                if(!isGoal)
                    //qDebug("tombol D = tackle");
                    on_tackleButton_released();
                else
                    goalSet("Penalty");
            }else if(event->key()==Qt::Key_F){
                //qDebug("tombol F = pass");
                on_passButton_pressed();
            }else if(event->key()==Qt::Key_G){
                //qDebug("tombol A = shoot");
                on_shootonButton_released();
            }
            else if(event->key()==Qt::Key_H){
                on_shootblockedButton_released();
            }
            else if(event->key()==Qt::Key_Z){
                on_crossBlockedButton_released();
            }else if(event->key()==Qt::Key_X){
                on_bodyChButton_released();
            }else if(event->key()==Qt::Key_C){
                on_blockCrossButton_released();
            }else if(event->key()==Qt::Key_V){
                on_looseBallButton_released();
            }else if(event->key()==Qt::Key_B){
                //qDebug("tombol B = shootff");
                on_shootoffButton_released();
            }
            else if(event->key()==Qt::Key_Q){
                on_cornerButton_released();
            }else if(event->key()==Qt::Key_W){
                on_throwinButton_released();
            }else if(event->key()==Qt::Key_E){
                if(!isGoal)
                    on_clearenceButton_released();
                else goalSet("Set piece");
            }else if(event->key()==Qt::Key_R){
                on_interceptButton_released();
            }else if(event->key()==Qt::Key_T){
                on_saveKeeperButton_released();
            }else if(event->key()==Qt::Key_Y){
                on_offsideButton_released();
            }
            else if(event->key()==Qt::Key_1){
                on_fouledButton_released();
            }else if(event->key()==Qt::Key_2){
                on_assistButton_released();
            }else if(event->key()==Qt::Key_3){
                on_goalButton_released();
            }else if(event->key()==Qt::Key_4){
                on_freeKickButton_released();
            }else if(event->key()==Qt::Key_5){
                on_foulButton_released();
            }else if(event->key()==Qt::Key_6){
                on_k6Button_released();
            }else if(event->key()==Qt::Key_7){
                on_k7Button_released();
            }
            else if(event->key()==Qt::Key_Tab){
                on_unDribbleButton_released();
            }else if(event->key()==Qt::Key_8){
                on_chanceButton_released();
            }
            else if(event->key()==Qt::Key_CapsLock){
                on_dribbleButton_clicked();
            }
            else if(event->key()==Qt::Key_N){
                on_blockButton_released();
            }
            else if(event->key()==Qt::Key_J)
            {
                on_chanceButton_released();
            }
            else if(event->key()==Qt::Key_U)
            {
                on_penaltyButton_released();
            }
        }
        else
        {
            if(m_ctrl)
            {
                if(event->key()==Qt::Key_Z){
                    if(m_shft)
                        on_redoButton_clicked();
                    else
                        on_UndoButton_released();
                }
                else if(event->key()==Qt::Key_A){
                    on_crossfButton_released();
                }else if(event->key()==Qt::Key_S){
                    on_headfButton_released();
                }else if(event->key()==Qt::Key_D){
                    on_tacklefButton_released();
                }else if(event->key()==Qt::Key_F){
                    on_passfButton_released();
                }else if(event->key()==Qt::Key_R){
                    on_interceptfButton_released();
                }else if(event->key()==Qt::Key_CapsLock){
                    on_unDribbleButton_released();
                }else if(event->key()==Qt::Key_4){
                    on_penMissedButton_released();
                }else if(event->key()==Qt::Key_9){
                    conceedTeam1();
                }else if(event->key()==Qt::Key_0){
                    conceedTeam2();
                }else if(event->key()==Qt::Key_2){
                    on_fantasyAssistButton_released();
                }else if(event->key()==Qt::Key_U){
                    on_savedPenaltyButton_released();
                }else if(event->key()==Qt::Key_3){
                    on_goalHeaderButton_released();
                }
            }
        }
        if(event->key() == Qt::Key_Control )
        {
            m_ctrl = false;
            ui->dribbleButton->setText("Dribble\nCAPS");
            ui->crossButton->setText("Cross\nA");
            ui->headButton->setText("Head\nS");
            ui->tackleButton->setText("Tackle\nD");
            ui->passButton->setText("Pass\nF");
            ui->interceptButton->setText("Intercept\nR");
            ui->freeKickButton->setText("Free Kick\n4");
            ui->throwinButton->setText("Throw In\nW");
            ui->assistButton->setText("Assist\n2");
            ui->penaltyButton->setText("Penalty\nU");
            ui->goalButton->setText("Goal\n3");
        }
        if(event->key() == Qt::Key_Shift)
            m_shft = false;
        if(event->key() == Qt::Key_Minus)
            on_player_subs_clicked();
        if(event->key() == Qt::Key_Equal)
            on_player2_subs_clicked();
    }

}
void MainWindow::on_tulis(QString str){
    Q_UNUSED(str);
}
void MainWindow::newFile()
{
    QMessageBox msgBox;
    if(isChanged)
    {
        // kasih warn mau save dulu ga
        msgBox.setText("Begin new file.");
        msgBox.setInformativeText("Do you want to save?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::No | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret) {
        case QMessageBox::Save:
            if(saveFileOnExit())
            {
                initialize();
                initPlayer();
                MainWindow::mjudul++;
                QString judul = "Tak berjudul (" + QString::number(MainWindow::mjudul) + ")";
                setWindowTitle(judul);
            }
            break;
        case QMessageBox::Cancel:
            // Cancel nothing happens
            break;
        case QMessageBox::No:
            initialize();
            initPlayer();
            int mjudul = getnumjudul();
            QString judul = "Untitled (" + QString::number(mjudul) + ")";
            setWindowTitle(judul);
            break;
        }
    }
    else
    {
        initialize();
        initPlayer();
        int mjudul = getnumjudul();
        QString judul = "Untitled (" + QString::number(mjudul) + ")";
        setWindowTitle(judul);
    }
}
void MainWindow::saveFile(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("*.csv"));
    if (fileName.isEmpty())
        return;
    saveAsFile(fileName);
}
int MainWindow::saveFileOnExit()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("*.csv"));
    if (fileName.isEmpty())
        return 0;
    saveAsFile(fileName);
    return 1;
}
void MainWindow::saveAsFile(QString filename)
{
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly)) {
        for(int row = 0; row < m_model.rowCount(); row ++) {
            QString textnya="";
            for(int col = 0; col < m_model.columnCount(); col ++) {
                if(col > 0){
                    //                        if(m_model.item(row,col)->text().isEmpty())
                    textnya = textnya + "," + m_model.item(row, col)->text();
                }
                else
                    textnya = m_model.item(row, col)->text();
            }
            textnya = textnya + "\n";
            file.write(textnya.toStdString().c_str());
        }
        file.close();
        isChanged = false;
    }
    setWindowTitle(filename);
}
void MainWindow::saveAsFile(){
    if(saveBox.exec() == QDialog::Accepted) {
        QFile file(saveBox.getName());
        if(file.open(QIODevice::WriteOnly)) {
            for(int row = 0; row < m_model.rowCount(); row ++) {
                QString textnya="";
                for(int col = 0; col < m_model.columnCount(); col ++) {
                    if(col > 0){
                        //                        if(m_model.item(row,col)->text().isEmpty())
                        textnya = textnya + "," + m_model.item(row, col)->text();
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
}
void MainWindow::loadFile()
{
    QMessageBox msgBox;
    if(isChanged)
    {
        msgBox.setText("Table has been modified.");
        msgBox.setInformativeText("Do you want to save before load?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret) {
        case QMessageBox::Save:
            saveFile();
            loadFileExtended();
            break;
        case QMessageBox::Cancel:
            // Cancel nothing happens
            break;
        case QMessageBox::Discard:
            loadFileExtended();
            break;
        }
    }
    else
        loadFileExtended();
}
void MainWindow::loadFileExtended()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load File"), "", tr("*.csv"));
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if(file.open(QFile::ReadOnly)) {
        //        m_model.clear();
        QStandardItemModel modelTemp;
        modelTemp.clear();
        initialize();
        modelTemp.setColumnCount(8);
        modelTemp.setRowCount(0);

        //read process here
        QTextStream stream(&file);
        QString line;
        int baris = 0;
        while(!stream.atEnd())  {
            line = stream.readLine();
            QStringList signtemp = line.split(QRegExp(",\\s?")); //ambil per koma
            QStringList::Iterator iterasi = signtemp.begin();
            //qDebug() << signtemp.size();
            if(signtemp.size() != 8){
                file.close();
                QMessageBox msg;
                if (signtemp.size() == 6 || signtemp.size() == 7)
                {
                    msg.setInformativeText("File not supported. \nIf this generated from this apps, try older version.");
                }
                else
                    msg.setInformativeText("File not supported.");
                msg.exec();
                return;
            }
            modelTemp.insertRow(baris);
            for (int i=0; i<signtemp.size(); i++)
            {
                modelTemp.setData(modelTemp.index(baris, i), signtemp.at(i));
            }
            baris++;
        }
        file.close();
        m_model.removeRows(1,m_model.rowCount());
        for(int j=0; j<baris; j++)
        {
            m_model.insertRow(j);
            for(int i=0; i<modelTemp.columnCount(); i++)
            {
                m_model.setData(m_model.index(j,i), modelTemp.item(j,i)->text());
                //                qDebug() << m_model.item(j,i)->text() << " " << modelTemp.item(j,i)->text();
            }
        }
        ui->tableView->setModel(&m_model);
        sizeUndo = 0;
        undomodel.clear();
        startUndo = m_model.rowCount();
        isChanged = false;
        setWindowTitle(QString(m_appsTitle + " - " + fileName));
    }
}
void MainWindow::preferences(){
    if(formSetting.exec())
    {
        m_jumlahpemain = formSetting.getNumPlayer();
        m_totalpemain = formSetting.getTotalPlayer();
        stage = formSetting.getStage();
        baseURL = formSetting.getbaseURL()+"/application/";
        ui->label->setText(baseURL);
        formEditPlayer.setSizePlayer(m_totalpemain);
        formEditPlayer.setBaseUrl(baseURL);
        formEditPlayer2.setSizePlayer(m_totalpemain);
        formEditPlayer2.setBaseUrl(baseURL);
        int subs = m_totalpemain-m_jumlahpemain;
        if(subs>16)subs=16;
        formSubs1.setSizeSubs(subs);
        formSubs2.setSizeSubs(subs);
        changeNumPlayer(m_jumlahpemain);
    }
}
void MainWindow::editTeam(){
    /* edit player1 di sini */
    if (formEditPlayer.exec()) {
        ui->label->setText("edit player team 1 berhasil");
        m_team1 = formEditPlayer.getTeamName();
        m_color1 = formEditPlayer.getTeamColor();
        m_idTeam1 = formEditPlayer.getTeamID();
        m_idMatch = formEditPlayer.getMacthID();
        ui->groupBox->setTitle(m_team1);
        ui->groupBox->setStyleSheet("QGroupBox#groupBox {border: 2px solid rgb(" + QString::number(m_color1.red())+
                                    ","+ QString::number(m_color1.green())+","+QString::number(m_color1.blue())+ ")}");
        refreshPlayer1();
    }
}
void MainWindow::refreshPlayer1(){
    m_playerList1.clear();
    formSubs1.clearCombo();
    formSubs1.clearCombo2();
    int size1 = formEditPlayer.getSizePlayer();
    playerStruct playerlist;
    for (int i = 0; i<m_jumlahpemain; i++){
        playerlist.nomor = formEditPlayer.getPlayerNumber(i);
        playerlist.nama  = formEditPlayer.getPlayerName(i);
        playerlist.team  = m_team1;
        playerlist.posisi= formEditPlayer.getPlayerPosition(i);
        m_playerList1.append(playerlist);
        formSubs1.addCombo(QString::number(playerlist.nomor), playerlist.nama);
    }
    for(int i=0; i < size1-m_jumlahpemain; i++){
        formSubs1.addCombo2(QString::number(formEditPlayer.getPlayerNumber(i+m_jumlahpemain)),
                            formEditPlayer.getPlayerName(i+m_jumlahpemain));
    }
    //    formSubs1.createMain();
    formSubs1.createSubs();
    buttonChangeName(ui->player_1, m_playerList1.at(0).nomor, m_playerList1.at(0).nama);
    buttonChangeName(ui->player_2, m_playerList1.at(1).nomor, m_playerList1.at(1).nama);
    buttonChangeName(ui->player_3, m_playerList1.at(2).nomor, m_playerList1.at(2).nama);
    buttonChangeName(ui->player_4, m_playerList1.at(3).nomor, m_playerList1.at(3).nama);
    buttonChangeName(ui->player_5, m_playerList1.at(4).nomor, m_playerList1.at(4).nama);
    if(m_jumlahpemain == 11){
        buttonChangeName(ui->player_6, m_playerList1.at(5).nomor, m_playerList1.at(5).nama);
        buttonChangeName(ui->player_7, m_playerList1.at(6).nomor, m_playerList1.at(6).nama);
        buttonChangeName(ui->player_8, m_playerList1.at(7).nomor, m_playerList1.at(7).nama);
        buttonChangeName(ui->player_9, m_playerList1.at(8).nomor, m_playerList1.at(8).nama);
        buttonChangeName(ui->player_10, m_playerList1.at(9).nomor, m_playerList1.at(9).nama);
        buttonChangeName(ui->player_11, m_playerList1.at(10).nomor, m_playerList1.at(10).nama);
    }
}
void MainWindow::editTeam2(){
    /* edit player2 di sini */
    //=====================//
    if (formEditPlayer2.exec()) {
        ui->label->setText("edit player team "+m_idTeam2+" berhasil");
        m_team2 = formEditPlayer2.getTeamName();
        m_color2 = formEditPlayer2.getTeamColor();
        m_idTeam2 = formEditPlayer2.getTeamID();
        m_idMatch = formEditPlayer2.getMacthID();
        ui->groupBox_3->setTitle(m_team2);
        //            QString style;
        //            style = "QGroupBox#groupBox_3 {border: 2px solid rgb(" + QString::number(m_color2.red())+
        //                    ","+ QString::number(m_color2.green())+","+QString::number(m_color2.blue())+
        //                    QString::number(m_color2.alpha()) + ")}";
        ui->groupBox_3->setStyleSheet("QGroupBox#groupBox_3 {border: 2px solid rgb(" + QString::number(m_color2.red())+
                                      ","+ QString::number(m_color2.green())+","+QString::number(m_color2.blue())+ ")}");
        refreshPlayer2();
    }
}
void MainWindow::refreshPlayer2(){
    m_playerList2.clear();
    formSubs2.clearCombo();
    formSubs2.clearCombo2();
    int size2 = formEditPlayer2.getSizePlayer();
    playerStruct playerlist;
    for (int i = 0; i<m_jumlahpemain; i++){
        playerlist.nomor = formEditPlayer2.getPlayerNumber(i);
        playerlist.nama  = formEditPlayer2.getPlayerName(i);
        playerlist.team  = m_team2;
        playerlist.posisi= formEditPlayer2.getPlayerPosition(i);
        m_playerList2.append(playerlist);
        formSubs2.addCombo(QString::number(playerlist.nomor), playerlist.nama);
    }
    for(int i=0; i < size2-m_jumlahpemain; i++){
        formSubs2.addCombo2(QString::number(formEditPlayer2.getPlayerNumber(i+m_jumlahpemain)),
                            formEditPlayer2.getPlayerName(i+m_jumlahpemain));
    }
    //    formSubs2.createMain();
    formSubs2.createSubs();
    //ganti teks tombol
    buttonChangeName(ui->player2_1, m_playerList2.at(0).nomor, m_playerList2.at(0).nama);
    buttonChangeName(ui->player2_2, m_playerList2.at(1).nomor, m_playerList2.at(1).nama);
    buttonChangeName(ui->player2_3, m_playerList2.at(2).nomor, m_playerList2.at(2).nama);
    buttonChangeName(ui->player2_4, m_playerList2.at(3).nomor, m_playerList2.at(3).nama);
    buttonChangeName(ui->player2_5, m_playerList2.at(4).nomor, m_playerList2.at(4).nama);
    if(m_jumlahpemain == 11)
    {
        buttonChangeName(ui->player2_6, m_playerList2.at(5).nomor, m_playerList2.at(5).nama);
        buttonChangeName(ui->player2_7, m_playerList2.at(6).nomor, m_playerList2.at(6).nama);
        buttonChangeName(ui->player2_8, m_playerList2.at(7).nomor, m_playerList2.at(7).nama);
        buttonChangeName(ui->player2_9, m_playerList2.at(8).nomor, m_playerList2.at(8).nama);
        buttonChangeName(ui->player2_10, m_playerList2.at(9).nomor, m_playerList2.at(9).nama);
        buttonChangeName(ui->player2_11, m_playerList2.at(10).nomor, m_playerList2.at(10).nama);
    }
}
void MainWindow::buttonChangeName(QPushButton *button, int noPlayer, QString namaPlayer){
    int ind = namaPlayer.indexOf(" ");
    if(ind == -1)
        ind = namaPlayer.length();
    if (ind >= 8)
        ind = 8;
    namaPlayer.truncate(ind);
    button->setText("(" + QString::number(noPlayer) +") " + namaPlayer);
}
void MainWindow::addResult(QAbstractItemModel *model, int line, const QString num, const QString name, const QString team, const QString act){
    int baris = model->rowCount();
    model->insertRow(line);
    model->setData(model->index(line, 0), baris);
    model->setData(model->index(line, 1), num);
    model->setData(model->index(line, 2), name);
    model->setData(model->index(line, 3), team);
    model->setData(model->index(line, 4), act);
    model->setData(model->index(line, 5), "");
    model->setData(model->index(line, 6), "");
    model->setData(model->index(line, 7), "");
    isChanged = true;
    sizeUndo = 0;
    QString m_stage = "1st%20half";
    if(stage == "1st stage"){
        m_stage = "1st%20half";
    } else if(stage == "2nd half"){
        m_stage = "2nd%20half";
    } else if(stage == "1ex half"){
        m_stage = "1ex%20half";
    } else if(stage == "2ex half"){
        m_stage = "2ex%20half";
    }
    postServer(m_idMatch, getTeamIDbyName(team), num, act, m_stage);
}
//NEW IN JANUARY 2017
void MainWindow::addResult(QAbstractItemModel *model, int line, const QString num, const QString name, const QString team, const QString act, const QString act2){
    int baris = model->rowCount();
    model->insertRow(line);
    model->setData(model->index(line, 0), baris);
    model->setData(model->index(line, 1), num);
    model->setData(model->index(line, 2), name);
    model->setData(model->index(line, 3), team);
    model->setData(model->index(line, 4), act);
    model->setData(model->index(line, 5), "");
    model->setData(model->index(line, 6), "");
    model->setData(model->index(line, 7), act2);
    isChanged = true;
    sizeUndo = 0;
    QString m_stage = "1st%20half";
    if(stage == "1st stage"){
        m_stage = "1st%20half";
    } else if(stage == "2nd half"){
        m_stage = "2nd%20half";
    } else if(stage == "1ex half"){
        m_stage = "1ex%20half";
    } else if(stage == "2ex half"){
        m_stage = "2ex%20half";
    }
    postServer(m_idMatch, getTeamIDbyName(team), num, act, m_stage, "0","0", act2);
}
void MainWindow::addResultPassing(QAbstractItemModel *model, int line, const QString num, const QString name, const QString team, const QString act, const QString tonum, const QString toname){
    int baris = model->rowCount();
    model->insertRow(line);
    model->setData(model->index(line, 0), baris);
    model->setData(model->index(line, 1), num);
    model->setData(model->index(line, 2), name);
    model->setData(model->index(line, 3), team);
    model->setData(model->index(line, 4), act);
    model->setData(model->index(line, 5), tonum);
    model->setData(model->index(line, 6), toname);
    model->setData(model->index(line, 7), "");
    isChanged = true;
    sizeUndo = 0;
    QString m_stage = "1st%20half";
    if(stage == "1st stage"){
        m_stage = "1st%20half";
    } else if(stage == "2nd half"){
        m_stage = "2nd%20half";
    } else if(stage == "1ex half"){
        m_stage = "1ex%20half";
    } else if(stage == "2ex half"){
        m_stage = "2ex%20half";
    }
    postServer(m_idMatch, getTeamIDbyName(team), num, act, m_stage, tonum, "0");
}
//NEW IN JANUARY 2017
void MainWindow::addResultPassing(QAbstractItemModel *model, int line, const QString num, const QString name, const QString team, const QString act, const QString tonum, const QString toname, const QString act2){
    int baris = model->rowCount();
    model->insertRow(line);
    model->setData(model->index(line, 0), baris);
    model->setData(model->index(line, 1), num);
    model->setData(model->index(line, 2), name);
    model->setData(model->index(line, 3), team);
    model->setData(model->index(line, 4), act);
    model->setData(model->index(line, 5), tonum);
    model->setData(model->index(line, 6), toname);
    model->setData(model->index(line, 7), act2);
    isChanged = true;
    sizeUndo = 0;
    QString m_stage = "1st%20half";
    if(stage == "1st stage"){
        m_stage = "1st%20half";
    } else if(stage == "2nd half"){
        m_stage = "2nd%20half";
    } else if(stage == "1ex half"){
        m_stage = "1ex%20half";
    } else if(stage == "2ex half"){
        m_stage = "2ex%20half";
    }
    postServer(m_idMatch, getTeamIDbyName(team), num, act, m_stage, tonum, "0",act2);
}

void MainWindow::generateLicense(const QString &license) {
    SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023));
    QString encryptedLicense = crypto.encryptToString(license);

    QString filename="license.txt";
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << encryptedLicense << endl;
    }
}

bool MainWindow::macAddressDefined(const QString &settingsPath) {
    QString thisMacAddress = getMacAddress();
    SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023));
    bool macAddressFound = false;

    QFile file(settingsPath);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QString decryptedLicense = crypto.decryptToString(line);

        if (decryptedLicense == thisMacAddress) {
            macAddressFound = true;
        }
    }

    file.close();
    return macAddressFound;
}

bool MainWindow::licenseFileExist() {
    QString fileName("./license.txt");
    if (QFileInfo::exists(fileName)) {
        return true;
    }

    return false;
}

bool MainWindow::connectDatabase() {
    QString thisMacAddress = getMacAddress();

    m_db.setHostName("128.199.182.1");
    m_db.setUserName("capture_tools");
    m_db.setPassword("Labbola1234*");
    m_db.setDatabaseName("labbola_production");

    if(m_db.open()) {
        qDebug() << "Connected " << m_db.hostName();
        QSqlQuery query;
        query.exec("SELECT license FROM licenses");

        while (query.next()) {
            QString license = query.value(0).toString();
            qDebug() << "licenses:: " << license;
            if (thisMacAddress == license) {
                generateLicense(license);
                return true;
            } else {
                return false;
            }
        }
    } else {
        QMessageBox msgBox;
        msgBox.setText("Database connection failed!");
        msgBox.exec();
        qDebug() << "Connection FAILED." << m_db.lastError();
        return false;
    }
}

QString MainWindow::getMacAddress() {
    foreach(QNetworkInterface netInterface, QNetworkInterface::allInterfaces())
    {
        // Return only the first non-loopback MAC Address
        if (!(netInterface.flags() & QNetworkInterface::IsLoopBack))
            return netInterface.hardwareAddress();
    }
    return QString();
}

void MainWindow::tombolAct(){
    //qDebug("%s action 1", m_name.toStdString().c_str());
    if(!isPassing){
        //        qDebug("notpassing");
        addResult(&m_model, 0, m_num, m_name, m_team, m_act);
        ui->tableView->setModel(&m_model);
        siapAct = 0;                            //action beres, no undo
        changeColorButton(curPlayer,false);     //matiin warna tombol yg aktif
    }
    else
    {
        //        qDebug("passing");
        addResult(&m_model, 0, m_num, m_name, m_team, m_act);
        ui->tableView->setModel(&m_model);
        siapAct = 0;                            //action beres, no undo
        changeColorButton(curPlayer,false);     //matiin warna tombol yg aktif
        qApp->setStyleSheet("QGroupBox#groupBox {background-color: none;}");
        qApp->setStyleSheet("QGroupBox#groupBox_3 {background-color: none;}");
        isPassing = false;
    }
}
void MainWindow::tombolAct(QString information){
    //qDebug("%s action 1", m_name.toStdString().c_str());
    //        qDebug("notpassing info");

    //old addresult
    //addResult(&m_model, 0, m_num, m_name, m_team, m_act);
    //m_model.setData(m_model.index(0, 7), information);
    //new addresult
    addResult(&m_model, 0, m_num, m_name, m_team, m_act,information);
    ui->tableView->setModel(&m_model);
    siapAct = 0;                            //action beres, no undo
    changeColorButton(curPlayer,false);     //matiin warna tombol yg aktif
    if(isPassing){
        isPassing = false;
        qApp->setStyleSheet("QGroupBox#groupBox {background-color: none;}");
        qApp->setStyleSheet("QGroupBox#groupBox_3 {background-color: none;}");
    }
}
void MainWindow::colorFromTo(int from, int to){
    changeColorButton(from,false);
    curPlayer = to;
    changeColorButton(curPlayer, true);
    if (isPassing && m_name!=m_passingfrom){                // action passing tidak boleh passing ke diri sndiri
        /* matikan warna warning passing */
        qApp->setStyleSheet("QGroupBox#groupBox {background-color: none;}");
        qApp->setStyleSheet("QGroupBox#groupBox_3 {background-color: none;}");
        if(m_passingteam == m_team){
            /* masukkan ke tabel dan tampilkan */
            addResultPassing(&m_model, 0, m_numpass, m_passingfrom, m_passingteam, m_act, m_num, m_name);
            ui->tableView->setModel(&m_model);
        }
        else {
            addResult(&m_model, 0, m_numpass, m_passingfrom, m_passingteam, "intercept");
            ui->tableView->setModel(&m_model);
        }
        //        siapAct = 0;
        //        changeColorButton(curPlayer,false);
        isPassing = false;
    }
}
void MainWindow::buttonProp(QPushButton *button, bool berwarna){
    if(berwarna){
        button->setStyleSheet("background-color: rgb(255,0,0); color: rgb(255,255,255)");
    }else
        button->setStyleSheet("background-color: none");
}
void MainWindow::changeColorButton(int player, bool clickedColor){
    //* fungsi mengganti warna tombol player
    // clickedColor = true, tombol menjadi warna merah. false adalah warna default sistem
    //------------------------------------------------------------
    if(player == 1){
        if (!clickedColor){
            ui->player_1->setStyleSheet("background-color: none");
        }else
            ui->player_1->setStyleSheet("background-color: rgb(255,0,0); color: rgb(255,255,255)");
    }
    else if(player == 2){
        if (!clickedColor){
            ui->player_2->setStyleSheet("background-color: none");
        }else
            ui->player_2->setStyleSheet("background-color: rgb(255,0,0); color: rgb(255,255,255)");
    }
    else if(player == 3){
        if (!clickedColor){
            ui->player_3->setStyleSheet("background-color: none");
        }else
            ui->player_3->setStyleSheet("background-color: rgb(255,0,0); color: rgb(255,255,255)");
    }
    else if(player == 4){
        if (!clickedColor){
            ui->player_4->setStyleSheet("background-color: none");
        }else
            ui->player_4->setStyleSheet("background-color: rgb(255,0,0); color: rgb(255,255,255)");
    }
    else if(player == 5){
        if (!clickedColor){
            ui->player_5->setStyleSheet("background-color: none");
        }else
            ui->player_5->setStyleSheet("background-color: rgb(255,0,0); color: rgb(255,255,255)");
    }
    else if(player == 6){
        if (!clickedColor){
            ui->player_6->setStyleSheet("background-color: none");
        }else
            ui->player_6->setStyleSheet("background-color: rgb(255,0,0); color: rgb(255,255,255)");
    }
    else if(player == 7){
        if (!clickedColor){
            ui->player_7->setStyleSheet("background-color: none");
        }else
            ui->player_7->setStyleSheet("background-color: rgb(255,0,0); color: rgb(255,255,255)");
    }
    else if(player == 8){
        if (!clickedColor){
            ui->player_8->setStyleSheet("background-color: none");
        }else
            ui->player_8->setStyleSheet("background-color: rgb(255,0,0); color: rgb(255,255,255)");
    }
    else if(player == 9){
        if (!clickedColor){
            ui->player_9->setStyleSheet("background-color: none");
        }else
            ui->player_9->setStyleSheet("background-color: rgb(255,0,0); color: rgb(255,255,255)");
    }
    else if(player == 10){
        if (!clickedColor){
            ui->player_10->setStyleSheet("background-color: none");
        }else
            ui->player_10->setStyleSheet("background-color: rgb(255,0,0); color: rgb(255,255,255)");
    }
    else if(player == 11){
        if (!clickedColor){
            ui->player_11->setStyleSheet("background-color: none");
        }else
            ui->player_11->setStyleSheet("background-color: rgb(255,0,0); color: rgb(255,255,255)");
    }
    //player 2
    else if(player == 21){
        buttonProp(ui->player2_1,clickedColor);
    }
    else if(player == 22){
        buttonProp(ui->player2_2,clickedColor);
    }
    else if(player == 23){
        buttonProp(ui->player2_3,clickedColor);
    }
    else if(player == 24){
        buttonProp(ui->player2_4,clickedColor);
    }
    else if(player == 25){
        buttonProp(ui->player2_5,clickedColor);
    }
    else if(player == 26){
        buttonProp(ui->player2_6,clickedColor);
    }
    else if(player == 27){
        buttonProp(ui->player2_7,clickedColor);
    }
    else if(player == 28){
        buttonProp(ui->player2_8,clickedColor);
    }
    else if(player == 29){
        buttonProp(ui->player2_9,clickedColor);
    }
    else if(player == 30){
        buttonProp(ui->player2_10,clickedColor);
    }
    else if(player == 31){
        buttonProp(ui->player2_11,clickedColor);
    }
}
//======================================================================//
/* bagian aksi di sini semua */
void MainWindow::on_passButton_released()
{
}
void  MainWindow::on_passButton_pressed()
{
    if(m_ctrl)
    {
        on_passfButton_released();
    } else
        //buttonProp(ui->passButton,false);
        if(siapAct){
            //        qDebug("%s action 1", m_name.toStdString().c_str());
            //        addResult(&m_model, m_model.rowCount(), m_name, QString("passing"));
            //        ui->tableView->setModel(&m_model);
            //        siapAct = 0;
            m_act = QString("passing");
            //tombolAct();
            //ui->groupBox->setStyleSheet("background-color: rgb(255,0,0)");
            isPassing = true;
            m_numpass = m_num;
            m_passingfrom = m_name;
            m_passingteam = m_team;
            //        addResult(&m_model, 0, m_num, m_name, m_team, m_act);
            if (m_team == m_team1)
                qApp->setStyleSheet("QGroupBox#groupBox {background-color: rgb(255,0,0);}");
            else
                qApp->setStyleSheet("QGroupBox#groupBox_3 {background-color: rgb(255,0,0);}");
        }
}
void MainWindow::on_passfButton_released()
{
    if(siapAct){
        QMenu *menu = new QMenu;
        menu->addAction("own fault");
        menu->addAction("intercept");
        menu->addAction("body charge");
        menu->addAction("clearance");
        menu->addAction("header duel");
        menu->addAction("block cross");
        //QPoint pS(30,10);
        QAction *act = menu->exec(QCursor::pos());
        //ui->goalButton->mapToGlobal(pS));
        m_act = QString("pass failed");
        if(act){
            //qDebug() << act->text();
            if(act->text() == "own fault")
            {
                QString ket = ("own fault");
                tombolAct(ket);
            }
            else if(act->text() == "intercept")
            {
                QString ket = ("intercept");
                tombolAct(ket);
            }
            else if(act->text() == "body charge")
            {
                QString ket = ("body charge");
                tombolAct(ket);
            }
            else if(act->text() == "clearance")
            {
                QString ket = ("clearance");
                tombolAct(ket);
            }
            else if(act->text() == "header duel")
            {
                QString ket = ("header duel");
                tombolAct(ket);
            }else if(act->text() == "block cross")
            {
                QString ket = ("block cross");
                tombolAct(ket);
            }
            QKeyEvent* ke = new QKeyEvent(QEvent::KeyPress, Qt::Key_Control,Qt::ControlModifier);
            keyReleaseEvent(ke);
        }
    }
    //    if(siapAct){
    //        m_act = QString("pass failed");
    //        //ui->pushButton_2->setPalette(QPalette(Qt::red));
    //        tombolAct();
    //    }
}
void MainWindow::on_shootonButton_released()
{
    if(siapAct){
        m_act = QString("shoot on target");
        tombolAct();
        //        ui->pushButton_3->setAutoFillBackground(true);
        //        ui->pushButton_3->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(255,255,255)");
    }
}
void MainWindow::on_shootoffButton_released()
{
    if(siapAct){
        m_act = QString("shoot off target");
        tombolAct();
    }
}
void MainWindow::on_tackleButton_released()
{
    if(m_ctrl)
    {
        on_tacklefButton_released();
    }
    else if(siapAct){
        m_act = QString("tackle");
        tombolAct();
    }
}
void MainWindow::on_tacklefButton_released()
{
    if(siapAct){
        m_act = QString("tackle failed");
        tombolAct();
    }
}
void MainWindow::on_headButton_released()
{
    if(m_ctrl)
    {
        on_headfButton_released();
    }
    else
        if(siapAct){
            QMenu *menu = new QMenu;
            QMenu *menu2 = new QMenu;
            menu->addAction("clearance.");
            menu->addAction("passing");
            menu2->setTitle("passing failed");
            menu2->addAction("own fault");
            menu2->addAction("intercept");
            menu2->addAction("body charge");
            menu2->addAction("clearance");
            menu2->addAction("header duel");
            menu2->addAction("block cross");
            menu->addMenu(menu2);
            menu->addAction("shoot on");
            menu->addAction("shoot off");
            menu->addAction("duel");
            //QPoint pS(30,10);
            QAction *act = menu->exec(QCursor::pos());
            //ui->goalButton->mapToGlobal(pS));
            m_act = QString("header won");
            if(act){
                //qDebug() << act->text();
                if(act->text() == "clearance.")
                {
                    QString ket = ("clearance");
                    tombolAct(ket);
                    siapAct = 1;
                    on_clearenceButton_released();
                }
                else if(act->text() == "duel")
                {
                    QString ket = ("duel");
                    tombolAct(ket);
                }else if(act->text() == "passing")
                {
                    QString ket = ("passing");
                    tombolAct(ket);
                    siapAct = 1;
                    changeColorButton(curPlayer, true);
                    on_passButton_pressed();
                }else if(act->text() == "passing failed")
                {
                    QString ket = ("passing failed");
                    tombolAct(ket);
                    //                siapAct = 1;
                    //                on_passfButton_released();
                }else if(act->text() == "shoot on")
                {
                    QString ket = ("shoot on");
                    tombolAct(ket);
                    siapAct = 1;
                    on_shootonButton_released();
                }else if(act->text() == "shoot off")
                {
                    QString ket = ("shoot off");
                    tombolAct(ket);
                    siapAct = 1;
                    on_shootoffButton_released();
                }
                else if(act->text() == "own fault")
                {
                    QString ket = ("passing failed");
                    tombolAct(ket);
                    siapAct = 1;
                    m_act = QString("pass failed");
                    ket = ("own fault");
                    tombolAct(ket);
                }
                else if(act->text() == "intercept")
                {
                    QString ket = ("passing failed");
                    tombolAct(ket);
                    siapAct = 1;
                    m_act = QString("pass failed");
                    ket = ("intercept");
                    tombolAct(ket);
                }
                else if(act->text() == "body charge")
                {
                    QString ket = ("passing failed");
                    tombolAct(ket);
                    siapAct = 1;
                    m_act = QString("pass failed");
                    ket = ("body charge");
                    tombolAct(ket);
                }
                else if(act->text() == "clearance")
                {
                    QString ket = ("passing failed");
                    tombolAct(ket);
                    siapAct = 1;
                    m_act = QString("pass failed");
                    ket = ("clearance");
                    tombolAct(ket);
                }
                else if(act->text() == "header duel")
                {
                    QString ket = ("passing failed");
                    tombolAct(ket);
                    siapAct = 1;
                    m_act = QString("pass failed");
                    ket = ("header duel");
                    tombolAct(ket);
                }else if(act->text() == "block cross")
                {
                    QString ket = ("passing failed");
                    tombolAct(ket);
                    siapAct = 1;
                    m_act = QString("pass failed");
                    ket = ("block cross");
                    tombolAct(ket);
                }
            }
        }
}
void MainWindow::on_headfButton_released()
{
    if(siapAct){
        m_act = QString("header failed");
        tombolAct();
        QKeyEvent* ke = new QKeyEvent(QEvent::KeyPress, Qt::Key_Control,Qt::ControlModifier);
        keyReleaseEvent(ke);
    }
}
void MainWindow::on_penMissedButton_released()
{
    if(siapAct){
        m_act = QString("penalty missed");
        tombolAct();
        QKeyEvent* ke = new QKeyEvent(QEvent::KeyPress, Qt::Key_Control,Qt::ControlModifier);
        keyReleaseEvent(ke);
    }
}
void MainWindow::on_chanceButton_released()
{
    if(siapAct){
        QMenu *menu = new QMenu;
        QMenu *menu1 = new QMenu;
        QMenu *menu2 = new QMenu;
        //        menu->addAction("left");
        //        menu->addAction("center");
        //        menu->addAction("right");
        menu2->setTitle("open play");
        menu2->addAction("Left");
        menu2->addAction("Center");
        menu2->addAction("Right");
        menu->addMenu(menu1);
        menu1->setTitle("set piece");
        menu1->addAction("left");
        menu1->addAction("center");
        menu1->addAction("right");
        menu->addMenu(menu2);
        //QPoint pS(30,10);
        QAction *act = menu->exec(QCursor::pos());
        //ui->goalButton->mapToGlobal(pS));
        m_act = QString ("create chance");
        if(act){
            if(act->text() == "left")
            {
                //m_act = QString ("LEFT chance");
                QString ket = ("set piece-LEFT side");
                tombolAct(ket);
                siapAct = 1;
            }
            else if(act->text() == "center")
            {
                // m_act = QString ("CENTER chance");
                QString ket = ("set piece-CENTER");
                tombolAct(ket);
                siapAct = 1;
            }
            else if(act->text() == "right")
            {
                // m_act = QString ("RIGHT chance");
                QString ket = ("set piece-RIGHT side");
                tombolAct(ket);
                siapAct = 1;
            }
            else if(act->text() == "open play")
            {
                //m_act = ;
                QString ket = ("open play");
                tombolAct(ket);
            }
            else if(act->text() == "set piece")
            {
                // m_act = ;
                QString ket = ("set piece");
                tombolAct(ket);
            }
            if(act->text() == "Left")
            {
                //  m_act = QString ("LEFT chance");
                QString ket = ("open play-LEFT side");
                tombolAct(ket);
                siapAct = 1;
            }
            else if(act->text() == "Center")
            {
                // m_act = QString ("CENTER chance");
                QString ket = ("open play-CENTER");
                tombolAct(ket);
                siapAct = 1;
            }
            else if(act->text() == "Right")
            {
                // m_act = QString ("RIGHT chance");
                QString ket = ("open play-RIGHT side");
                tombolAct(ket);
                siapAct = 1;
            }
        }
    }
}
void MainWindow::on_crossButton_released()
{
    if(m_ctrl)
    {
        on_crossfButton_released();
    }
    else if(siapAct){
        m_act = QString("cross");
        tombolAct();
        siapAct = 1;
        changeColorButton(curPlayer, true);
        on_passButton_pressed();
    }
}
void MainWindow::on_crossfButton_released()
{
    if(siapAct){
        QMenu *menu = new QMenu;
        menu->addAction("own fault");
        menu->addAction("intercept");
        menu->addAction("body charge");
        menu->addAction("clearance");
        menu->addAction("header duel");
        menu->addAction("block cross");
        //QPoint pS(30,10);
        QAction *act = menu->exec(QCursor::pos());
        //ui->goalButton->mapToGlobal(pS));
        m_act = QString("cross failed");
        if(act){
            //qDebug() << act->text();
            if(act->text() == "own fault")
            {
                QString ket =("own fault");
                tombolAct(ket);
                m_act = QString("pass failed");
                tombolAct(ket);
            }
            else if(act->text() == "intercept")
            {
                QString ket =("intercept");
                tombolAct(ket);
                m_act = QString("pass failed");
                tombolAct(ket);
            }
            else if(act->text() == "body charge")
            {
                QString ket =("body charge");
                tombolAct(ket);
                m_act = QString("pass failed");
                tombolAct(ket);
            }
            else if(act->text() == "clearance")
            {
                QString ket =("clearance");
                tombolAct(ket);
                m_act = QString("pass failed");
                tombolAct(ket);
            }
            else if(act->text() == "header duel")
            {
                QString ket =("header duel");
                tombolAct(ket);
                m_act = QString("pass failed");
                tombolAct(ket);
            }else if(act->text() == "block cross")
            {
                QString ket =("block cross");
                tombolAct(ket);
                m_act = QString("pass failed");
                tombolAct(ket);
            }
            QKeyEvent* ke = new QKeyEvent(QEvent::KeyPress, Qt::Key_Control,Qt::ControlModifier);
            keyReleaseEvent(ke);
        }
    }
}
void MainWindow::on_cornerButton_released()
{
    if(siapAct){
        m_act = QString("corner");
        tombolAct();
    }
}
void MainWindow::on_freeKickButton_released()
{   if(m_ctrl)
    {
        on_penMissedButton_released();
    }else
        if(siapAct){
            m_act = QString("free kick");
            tombolAct();
        }
}
void MainWindow::on_throwinButton_released()
{
    if(siapAct){
        m_act = QString("throw in");
        tombolAct();
    }
}
void MainWindow::on_offsideButton_released()
{
    if(siapAct){
        m_act = QString("offside");
        tombolAct();
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << event->globalX() << "," << event->globalY();
}
void MainWindow::on_goalButton_released()
{
    if(m_ctrl){
        on_goalHeaderButton_released();
    } else if(siapAct){
        if(!isGoal)
        {
            QMenu *menu = new QMenu;
            menu->addAction("open play");
            menu->addAction("set piece");
            menu->addAction("penalty");
            //QPoint pS(30,10);
            QAction *act = menu->exec(QCursor::pos());
            //ui->goalButton->mapToGlobal(pS));
            if(act){
                //qDebug() << act->text();
                if(act->text() == "open play")
                {
                    goalSet("Open play");
                }
                else if (act->text() == "set piece")
                {
                    goalSet("Set piece");
                }
                else if (act->text() == "penalty")
                {
                    goalSet("Penalty");
                }
            }
            //isGoal = true;
        }
        else
        {
            goalSet("Open play");
        }
    }
}
void MainWindow::goalSet(QString ket)
{
    m_act = QString("goal");
    addResult(&m_model, 0, m_num, m_name, m_team, "shoot on target");
    addResult(&m_model, 0, m_num, m_name, m_team, m_act);
    m_model.setData(m_model.index(0, 7), ket);
    ui->tableView->setModel(&m_model);
    siapAct = 0;                            //action beres, no undo
    changeColorButton(curPlayer,false);     //matiin warna tombol yg aktif
    //isGoal = false;
}
void MainWindow::on_clearenceButton_released()
{
    if(siapAct){
        m_act = QString("clearance");
        tombolAct();
    }
}
void MainWindow::on_shootblockedButton_released()
{
    if(siapAct){
        m_act = QString("shoot blocked");
        tombolAct();
    }
}
void MainWindow::on_noActionButton_released()
{
    if(siapAct){
        m_act = QString("no action");
        tombolAct();
    }
}
void MainWindow::on_fouledButton_released()
{
    if(siapAct){
        m_act = QString("fouled");
        tombolAct();
    }
}
void MainWindow::on_assistButton_released()
{
    if(m_ctrl){
        on_fantasyAssistButton_released();
    } else if(siapAct){
        QMenu *menu = new QMenu;
        QMenu *menu1 = new QMenu;
        QMenu *menu2 = new QMenu;

        menu2->setTitle("open play");
        menu2->addAction("Left");
        menu2->addAction("Center");
        menu2->addAction("Right");
        menu->addMenu(menu1);
        menu1->setTitle("set piece");
        menu1->addAction("left");
        menu1->addAction("center");
        menu1->addAction("right");
        menu->addMenu(menu2);


        QAction *act = menu->exec(QCursor::pos());
        //ui->goalButton->mapToGlobal(pS));
        m_act = QString ("create chance");
        if(act){
            if(act->text() == "left")
            {
                //m_act = QString ("LEFT chance");
                QString ket = ("set piece-LEFT side");
                tombolAct(ket);
                siapAct = 1;
            }
            else if(act->text() == "center")
            {
                // m_act = QString ("CENTER chance");
                QString ket = ("set piece-CENTER");
                tombolAct(ket);
                siapAct = 1;
            }
            else if(act->text() == "right")
            {
                // m_act = QString ("RIGHT chance");
                QString ket = ("set piece-RIGHT side");
                tombolAct(ket);
                siapAct = 1;
            }
            else if(act->text() == "open play")
            {
                //m_act = ;
                QString ket = ("open play");
                tombolAct(ket);
            }
            else if(act->text() == "set piece")
            {
                // m_act = ;
                QString ket = ("set piece");
                tombolAct(ket);
            }
            if(act->text() == "Left")
            {
                //  m_act = QString ("LEFT chance");
                QString ket = ("open play-LEFT side");
                tombolAct(ket);
                siapAct = 1;
            }
            else if(act->text() == "Center")
            {
                // m_act = QString ("CENTER chance");
                QString ket = ("open play-CENTER");
                tombolAct(ket);
                siapAct = 1;
            }
            else if(act->text() == "Right")
            {
                // m_act = QString ("RIGHT chance");
                QString ket = ("open play-RIGHT side");
                tombolAct(ket);
                siapAct = 1;
            }
        }






        m_act = QString("assist");
        tombolAct();
    }
}
void MainWindow::on_interceptButton_released()
{
    if(m_ctrl)
    {
        on_interceptfButton_released();
    }else
        if(siapAct){
            m_act = QString("intercept");
            tombolAct();
        }
}
void MainWindow::on_foulButton_released()
{
    if(siapAct){
        m_act = QString("foul");
        tombolAct();
    }
}
void MainWindow::on_yellowCardButton_clicked()
{
    if(siapAct){
        m_act = QString("yellow card");
        tombolAct();
    }
}
void MainWindow::on_redCardButton_released()
{
    if(siapAct){
        m_act = QString("red card");
        tombolAct();
    }
}
//-----------------------------------------------------------------
//* bagian player button di mari semua :)
//  fungsi jika tombol player ditekan
void MainWindow::on_player_1_released()
{
    //    qDebug(" player 1");
    m_num = QString::number(m_playerList1.at(0).nomor);
    m_name =  m_playerList1.at(0).nama;  //QString("Player 1");
    m_team = m_team1;
    siapAct = 1;
    colorFromTo(curPlayer,1);
}
void MainWindow::on_player_2_released()
{
    //    qDebug("emit player 2");
    m_num =  QString::number(m_playerList1.at(1).nomor);
    m_name =  m_playerList1.at(1).nama;
    m_team = m_team1;
    siapAct = 1;
    colorFromTo(curPlayer,2);
}
void MainWindow::on_player_3_released()
{
    //    qDebug("emit player 3");
    m_num =  QString::number(m_playerList1.at(2).nomor);
    m_name =  m_playerList1.at(2).nama;
    m_team = m_team1;
    siapAct = 1;
    colorFromTo(curPlayer,3);
}
void MainWindow::on_player_4_released()
{
    //    qDebug("emit player 4");
    m_num =  QString::number(m_playerList1.at(3).nomor);
    m_name =  m_playerList1.at(3).nama;
    m_team = m_team1;
    siapAct = 1;
    colorFromTo(curPlayer,4);
}
void MainWindow::on_player_5_released()
{
    //    qDebug("emit player 5");
    m_num =  QString::number(m_playerList1.at(4).nomor);
    m_name =  m_playerList1.at(4).nama;
    m_team = m_team1;
    siapAct = 1;
    colorFromTo(curPlayer,5);
}
void MainWindow::on_player_6_released()
{
    //    qDebug("emit player 6");
    m_num =  QString::number(m_playerList1.at(5).nomor);
    m_name =  m_playerList1.at(5).nama;
    m_team = m_team1;
    siapAct = 1;
    colorFromTo(curPlayer,6);
}
void MainWindow::on_player_7_released()
{
    //    qDebug("emit player 7");
    m_num =  QString::number(m_playerList1.at(6).nomor);
    m_name =  m_playerList1.at(6).nama;
    m_team = m_team1;
    siapAct = 1;
    colorFromTo(curPlayer,7);
}
void MainWindow::on_player_8_released()
{
    //    qDebug("emit player 8");
    m_num =  QString::number(m_playerList1.at(7).nomor);
    m_name =  m_playerList1.at(7).nama;
    m_team = m_team1;
    siapAct = 1;
    colorFromTo(curPlayer,8);
}
void MainWindow::on_player2_1_released()
{
    m_num =  QString::number(m_playerList2.at(0).nomor);
    m_name =  m_playerList2.at(0).nama;
    m_team = m_team2;
    siapAct = 1;
    colorFromTo(curPlayer,21);
}
void MainWindow::on_player2_2_released()
{
    m_num =  QString::number(m_playerList2.at(1).nomor);
    m_name =  m_playerList2.at(1).nama;
    m_team = m_team2;
    siapAct = 1;
    colorFromTo(curPlayer,22);
}
void MainWindow::on_player_9_released()
{
    //    qDebug("emit player 9");
    m_num =  QString::number(m_playerList1.at(8).nomor);
    m_name =  m_playerList1.at(8).nama;
    m_team = m_team1;
    siapAct = 1;
    colorFromTo(curPlayer,9);
}
void MainWindow::on_player_10_released()
{
    //    qDebug("emit player 10");
    m_num =  QString::number(m_playerList1.at(9).nomor);
    m_name =  m_playerList1.at(9).nama;
    m_team = m_team1;
    siapAct = 1;
    colorFromTo(curPlayer,10);
}
void MainWindow::on_player_11_released()
{
    //    qDebug("emit player 11");
    m_num =  QString::number(m_playerList1.at(10).nomor);
    m_name =  m_playerList1.at(10).nama;
    m_team = m_team1;
    siapAct = 1;
    colorFromTo(curPlayer,11);
}
void MainWindow::on_player2_3_released()
{
    m_num =  QString::number(m_playerList2.at(2).nomor);
    m_name =  m_playerList2.at(2).nama;
    m_team = m_team2;
    siapAct = 1;
    colorFromTo(curPlayer,23);
}
void MainWindow::on_player2_4_released()
{
    m_num =  QString::number(m_playerList2.at(3).nomor);
    m_name =  m_playerList2.at(3).nama;
    m_team = m_team2;
    siapAct = 1;
    colorFromTo(curPlayer,24);
}
void MainWindow::on_player2_5_released()
{
    m_num =  QString::number(m_playerList2.at(4).nomor);
    m_name =  m_playerList2.at(4).nama;
    m_team = m_team2;
    siapAct = 1;
    colorFromTo(curPlayer,25);
}
void MainWindow::on_player2_6_released()
{
    m_num =  QString::number(m_playerList2.at(5).nomor);
    m_name =  m_playerList2.at(5).nama;
    m_team = m_team2;
    siapAct = 1;
    colorFromTo(curPlayer,26);
}
void MainWindow::on_player2_7_released()
{
    m_num =  QString::number(m_playerList2.at(6).nomor);
    m_name =  m_playerList2.at(6).nama;
    m_team = m_team2;
    siapAct = 1;
    colorFromTo(curPlayer,27);
}
void MainWindow::on_player2_8_released()
{
    m_num =  QString::number(m_playerList2.at(7).nomor);
    m_name =  m_playerList2.at(7).nama;
    m_team = m_team2;
    siapAct = 1;
    colorFromTo(curPlayer,28);
}
void MainWindow::on_player2_9_released()
{
    m_num =  QString::number(m_playerList2.at(8).nomor);
    m_name =  m_playerList2.at(8).nama;
    m_team = m_team2;
    siapAct = 1;
    colorFromTo(curPlayer,29);
}
void MainWindow::on_player2_10_released()
{
    m_num =  QString::number(m_playerList2.at(9).nomor);
    m_name =  m_playerList2.at(9).nama;
    m_team = m_team2;
    siapAct = 1;
    colorFromTo(curPlayer,30);
}
void MainWindow::on_player2_11_released()
{
    m_num =  QString::number(m_playerList2.at(10).nomor);
    m_name =  m_playerList2.at(10).nama;
    m_team = m_team2;
    siapAct = 1;
    colorFromTo(curPlayer,31);
}
void MainWindow::on_player_subs_clicked()
{
    if(siapAct && m_team == m_team1){
        if(formSubs1.exec() && m_num != "NO"){
            int subs2 = formSubs1.getSubsPlayer2() + m_jumlahpemain;
            int subs = formSubs1.getPlayerindex(m_num);  //formSubs1.getSubsPlayer1();
            if(subs >= 0)
            {
                formEditPlayer.substitute(subs,
                                          subs2);
                bool ok=true;
                int i = minute;
                //            int i = QInputDialog::getInt(this, tr("Subtitution time"),
                //                                         tr("Minute:"), minute, 0, 130, 1, &ok);
                if (ok){
                    //                minute = i;
                    //                addResultPassing(&m_model, 0, "", "", "", "substitution", "", "");

                    //OLD VERSION
                    //addResultPassing(&m_model, 0, m_num, m_name, m_team1, "substitution", formEditPlayer.getPlayerNumString(subs),formEditPlayer.getPlayerName(subs));
                    //m_model.setData(m_model.index(0, 7),
                    //               QString(QString::number(i) + "th minute: " + m_name + " off, "
                    //                        + formEditPlayer.getPlayerName(subs) + " on"));

                    //NEW VERSION
                    addResultPassing(&m_model, 0, m_num, m_name, m_team1, "substitution", formEditPlayer.getPlayerNumString(subs),formEditPlayer.getPlayerName(subs),
                                     QString(QString::number(i) + "th minute: " + m_name + " off, "
                                             + formEditPlayer.getPlayerName(subs) + " on"));

                    ui->tableView->setModel(&m_model);
                    //                ui->label->setText(m_num+"-"+formEditPlayer.getPlayerNumString(subs));
                }else
                    formEditPlayer.substitute(subs,subs2);
            }

            refreshPlayer1();
            changeColorButton(curPlayer,false);
            m_num = "NO";
            siapAct = 0;
        }
    }
}
void MainWindow::on_player2_subs_clicked()
{
    if(siapAct && m_team == m_team2){
        if(formSubs2.exec() && m_num != "NO"){
            int subs2 = formSubs2.getSubsPlayer2() + m_jumlahpemain;
            int subs = formSubs2.getPlayerindex(m_num); //formSubs2.getSubsPlayer1();
            if(subs >= 0)
            {
                formEditPlayer2.substitute(subs, subs2);
                bool ok=true;
                int i = minute;
                //            int i = QInputDialog::getInt(this, tr("Subtitution time"),
                //                                         tr("Minute:"), minute, 0, 130, 1, &ok);
                if (ok){
                    //                minute = i;
                    //                addResultPassing(&m_model, 0, "", "", "", "substitution", "", "");

                    //OLD VERSION
                    //addResultPassing(&m_model, 0, m_num, m_name, m_team2, "substitution", formEditPlayer2.getPlayerNumString(subs),formEditPlayer2.getPlayerName(subs));
                    //m_model.setData(m_model.index(0, 7),
                    //                QString(QString::number(i) + "th minute: " + m_name + " off, "
                    //                        + formEditPlayer2.getPlayerName(subs) + " on"));

                    //NEW VERSION
                    addResultPassing(&m_model, 0, m_num, m_name, m_team2, "substitution", formEditPlayer2.getPlayerNumString(subs),formEditPlayer2.getPlayerName(subs),
                                     QString(QString::number(i) + "th minute: " + m_name + " off, "
                                             + formEditPlayer2.getPlayerName(subs) + " on"));

                    ui->tableView->setModel(&m_model);
                    //                ui->label->setText(m_num+"-"+formEditPlayer2.getPlayerNumString(subs));
                }else
                    formEditPlayer2.substitute(subs,subs2);
            }
            refreshPlayer2();
            changeColorButton(curPlayer,false);
            m_num = "NO";
            siapAct = 0;
        }
    }
}
void MainWindow::on_UndoButton_released()
{
    //    int baris = m_model.rowCount();
    //    m_model.removeRow(0);
    if(m_model.rowCount() > startUndo)
    {
        QList<QStandardItem *> row = m_model.takeRow(0);
        undomodel.appendRow(row);
        sizeUndo++;
        ui->tableView->setModel(&m_model);
        QString teamId = getTeamIDbyName(row.at(3)->text());
        undoPostServer(m_idMatch, teamId);
    }
}
void MainWindow::on_redoButton_clicked()
{
    if(sizeUndo>0){
        ui->label->setText("");
        QList<QStandardItem *> redo_act = undomodel.takeRow(undomodel.rowCount()-1);
        m_model.insertRow(0,redo_act);
        sizeUndo = sizeUndo-1;
        QString num = redo_act.at(1)->text();
        QString teamId = getTeamIDbyName(redo_act.at(3)->text());
        QString act = redo_act.at(4)->text();
        QString tonum = redo_act.at(5)->text();
        QString act2 = redo_act.at(7)->text();
        QString m_stage = "1st%20half";
        if(stage == "1st stage"){
            m_stage = "1st%20half";
        } else if(stage == "2nd half"){
            m_stage = "2nd%20half";
        } else if(stage == "1ex half"){
            m_stage = "1ex%20half";
        } else if(stage == "2ex half"){
            m_stage = "2ex%20half";
        }
        if(tonum==""){
            postServer(m_idMatch, teamId, num, act, m_stage, "0", "0",act2);
        }else {
            postServer(m_idMatch, teamId, num, act, m_stage, tonum, "0",act2);
        }

    }
    ui->tableView->setModel(&m_model);
}
void MainWindow::on_saveKeeperButton_released()
{
    if(siapAct){
        m_act = QString("save");
        tombolAct();
    }
}
void MainWindow::on_tableView_doubleClicked(QModelIndex index)
{
    Q_UNUSED(index);
    if(siapAct)
    {
        siapAct = false;
        changeColorButton(curPlayer,false);
        qApp->setStyleSheet("QGroupBox#groupBox {background-color: none;}");
        qApp->setStyleSheet("QGroupBox#groupBox_3 {background-color: none;}");
        isPassing = false;
    }
    //mode = MODE_EDIT_TABLE;
}
void MainWindow::on_tableView_entered(QModelIndex index)
{
    Q_UNUSED(index);
    mode = MODE_PLAY;
}
void MainWindow::changeNumPlayer(int size)
{
    if (size==5)
    {
        ui->player_11->hide();
        ui->player_10->hide();
        ui->player_9->hide();
        ui->player_8->hide();
        ui->player_7->hide();
        ui->player_6->hide();
        ui->horizontalLayout_2->addWidget(ui->player_4);
        ui->horizontalLayout_2->addWidget(ui->player_5);
        ui->horizontalLayout_2->addWidget(ui->player_subs);
        ui->player2_11->hide();
        ui->player2_10->hide();
        ui->player2_9->hide();
        ui->player2_8->hide();
        ui->player2_7->hide();
        ui->player2_6->hide();
        ui->horizontalLayout_5->addWidget(ui->player2_4);
        ui->horizontalLayout_5->addWidget(ui->player2_5);
        ui->horizontalLayout_5->addWidget(ui->player2_subs);

    }
    else if(size==11)
    {
        ui->player_11->show();
        ui->player_10->show();
        ui->player_9->show();
        ui->player_8->show();
        ui->player_7->show();
        ui->player_6->show();
        ui->horizontalLayout->addWidget(ui->player_4);
        ui->horizontalLayout_2->addWidget(ui->player_5);
        ui->horizontalLayout_2->addWidget(ui->player_6);
        ui->horizontalLayout_2->addWidget(ui->player_7);
        ui->horizontalLayout_2->addWidget(ui->player_8);
        ui->horizontalLayout_3->addWidget(ui->player_9);
        ui->horizontalLayout_3->addWidget(ui->player_10);
        ui->horizontalLayout_3->addWidget(ui->player_11);
        ui->horizontalLayout_3->addWidget(ui->player_subs);
        ui->player2_11->show();
        ui->player2_10->show();
        ui->player2_9->show();
        ui->player2_8->show();
        ui->player2_7->show();
        ui->player2_6->show();
        ui->horizontalLayout_8->addWidget(ui->player2_4);
        ui->horizontalLayout_5->addWidget(ui->player2_5);
        ui->horizontalLayout_5->addWidget(ui->player2_6);
        ui->horizontalLayout_5->addWidget(ui->player2_7);
        ui->horizontalLayout_5->addWidget(ui->player2_8);
        ui->horizontalLayout_7->addWidget(ui->player2_9);
        ui->horizontalLayout_7->addWidget(ui->player2_10);
        ui->horizontalLayout_7->addWidget(ui->player2_11);
        ui->horizontalLayout_7->addWidget(ui->player2_subs);
    }
    refreshPlayer1();
    refreshPlayer2();
}
void MainWindow::on_dribbleButton_clicked()
{
    if(m_ctrl)
    {
        on_unDribbleButton_released();
    }
    else if(siapAct){
        m_act = QString("dribble success");
        tombolAct();
    }
}
void MainWindow::on_unDribbleButton_released()
{
    if(siapAct){
        QMenu *menu = new QMenu;
        menu->addAction("own fault");
        menu->addAction("tackle");
        menu->addAction("body charge");
        //QPoint pS(30,10);
        QAction *act = menu->exec(QCursor::pos());
        //ui->goalButton->mapToGlobal(pS));
        m_act = QString("dribble failed");
        if(act){
            //qDebug() << act->text();
            if(act->text() == "own fault")
            {
                QString ket =("own fault");
                tombolAct(ket);
            }
            else if(act->text() == "tackle")
            {
                QString ket =("tackle");
                tombolAct(ket);
            }
            else if(act->text() == "body charge")
            {
                QString ket =("body charge");
                tombolAct(ket);
            }
            QKeyEvent* ke = new QKeyEvent(QEvent::KeyPress, Qt::Key_Control,Qt::ControlModifier);
            keyReleaseEvent(ke);
        }
    }
}
void MainWindow::on_blockButton_released()
{
    if(siapAct){
        m_act = QString("block");
        tombolAct();
    }
}
void MainWindow::on_looseBallButton_released()
{
    if(siapAct){
        QMenu *menu = new QMenu;
        menu->addAction("own fault");
        menu->addAction("tackle");
        //QPoint pS(30,10);
        QAction *act = menu->exec(QCursor::pos());
        //ui->goalButton->mapToGlobal(pS));
        m_act = QString("loose ball");
        if(act){
            //qDebug() << act->text();
            if(act->text() == "own fault")
            {
                QString ket =("own fault");
                tombolAct(ket);
            }
            else if(act->text() == "tackle")
            {
                QString ket =("tackle");
                tombolAct(ket);
            }
        }
    }
}
void MainWindow::on_crossBlockedButton_released()
{
    if(siapAct){
        m_act = QString("cross blocked");
        tombolAct();
        m_act = QString("pass failed");
        tombolAct("block cross");
    }
}
void MainWindow::on_blockCrossButton_released()
{
    if(siapAct){
        m_act = QString("block cross");
        tombolAct();
    }
}
void MainWindow::on_bodyChButton_released()
{
    if(siapAct){
        m_act = QString("body charge");
        tombolAct();
    }
}
void MainWindow::on_interceptfButton_released()
{
    if(siapAct){
        m_act = QString("intercept failed");
        tombolAct();
    }
}
void MainWindow::on_k6Button_released()
{
    if(siapAct){
        m_act = QString("Own Goal");
        tombolAct();
    }
}
void MainWindow::on_k7Button_released()
{
    if(siapAct){
        m_act = QString("handball");
        tombolAct();
        siapAct = 1;
        on_foulButton_released();
    }
}
void MainWindow::on_penaltyButton_released()
{
    if(m_ctrl){
        on_savedPenaltyButton_released();
    } else if(siapAct){
        on_shootonButton_released();
        siapAct = 1;
        on_freeKickButton_released();
        siapAct = 1;
        m_act = QString("penalty goal");
        tombolAct();
    }
}

void MainWindow::mulai(){
    ui->StartButton->setDisabled(1);
    ui->PauseButton->setEnabled(1);
    ui->StopButton->setEnabled(1);

    timer->start(1000);


}

void MainWindow::tunda(){

    ui->StartButton->setEnabled(1);
    ui->PauseButton->setDisabled(1);
    ui->StopButton->setEnabled(1);
    timer->stop();
}

void MainWindow::berhenti(){

    ui->StartButton->setEnabled(1);
    ui->PauseButton->setEnabled(1);
    ui->StopButton->setDisabled(1);
    time->setHMS(0,0,0);
    QString text = time->toString("hh:mm:ss");
    ui->lcdNumber->display(text);
    //timer->killTimer(100);
    i=0;

}

void MainWindow::ubahmenit(){

    bool ok;
    int menitbaru = QInputDialog::getInt(this, tr("Ubah Timer"),
                                         tr("Minute:"), 0, 0, 130, 1, &ok);
    if(ok){
        time->setHMS(0,menitbaru,0);
        QString text = time->toString("hh:mm:ss");
        ui->lcdNumber->display(text);
        //timer->killTimer(100);
        i=0;
    }
}


void MainWindow::showTime(){
    QTime newtime;

    i=i+1;
    newtime = time->addSecs(i);
    QString text = newtime.toString("hh:mm:ss");

    ui->lcdNumber->display(text);

}


void MainWindow::mulai2(){
    ui->StartButton_2->setDisabled(1);
    ui->PauseButton_2->setEnabled(1);
    ui->StopButton_2->setEnabled(1);

    timer2->start(1000);


}

void MainWindow::tunda2(){

    ui->StartButton_2->setEnabled(1);
    ui->PauseButton_2->setDisabled(1);
    ui->StopButton_2->setEnabled(1);
    timer2->stop();
}

void MainWindow::berhenti2(){

    ui->StartButton_2->setEnabled(1);
    ui->PauseButton_2->setEnabled(1);
    ui->StopButton_2->setDisabled(1);

    ui->lcdNumber_3->setSegmentStyle(QLCDNumber::Filled);
    ui->lcdNumber_3->setDigitCount(8);
    time2->setHMS(0,0,0);
    QString text2 = time2->toString("hh:mm:ss");

    minute = time2->minute()+1;
    ui->lcdNumber_3->display(text2);

    j=0;

}

void MainWindow::ubahmenit2(){

    bool ok;
    int menitbaru = QInputDialog::getInt(this, tr("Ubah Timer"),
                                         tr("Minute:"), 0, 0, 130, 1, &ok);
    if(ok){
        time2->setHMS(0,menitbaru,0);
        QString text = time2->toString("hh:mm:ss");
        ui->lcdNumber_3->display(text);
        //timer->killTimer(100);
        j=0;
        minute = menitbaru+1;
    }
}


void MainWindow::showTime2(){
    QTime newtime2;
    //QTime time = new QTime(00,00,00);
    //if(flag==1)
    //i=i-1;
    j=j+1;
    ui->lcdNumber_3->setSegmentStyle(QLCDNumber::Filled);
    ui->lcdNumber_3->setDigitCount(8);
    newtime2 = time2->addSecs(j);
    QString text2 = newtime2.toString("hh:mm:ss");
    minute = newtime2.minute()+1;
    ui->lcdNumber_3->display(text2);

}

void MainWindow::postServer(QString match_id, QString club_id, QString p_number, QString p_action, QString stage, QString pp_number, QString t_minute, QString second_action){
    Q_UNUSED(t_minute);
    QString a_minute = QString::number(minute);
    //    if(p_action=="goal"||p_action=="Own Goal"||p_action=="penalty goal"||p_action=="yellow card"||p_action=="red card"
    //            ){//||p_action=="assist"||p_action=="create chance"){
    //        bool ok;
    //        minute = QInputDialog::getInt(this, p_action+tr(" time"),
    //                                    tr("Minute:"), minute, 0, 130, 1, &ok);
    //        if(ok){
    //            a_minute = QString::number(minute);
    //        }
    //    }
    //    if(p_action=="substitution"){
    //        a_minute = QString::number(minute);
    //    }
    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onGetResult(QNetworkReply*)));
    connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));
    QString url = generateURL(match_id, club_id, p_number, p_action, stage, pp_number, a_minute, second_action);
    //    ui->label->setText("menit="+a_minute);
    mgr->get(QNetworkRequest(QUrl(url)));
}

void MainWindow::onGetResult(QNetworkReply *rep){
    QByteArray bts = rep->readAll();
    QString str(bts);
    ui->label->setText(str);
}

QString MainWindow::generateURL(QString match_id, QString club_id, QString p_number, QString p_action, QString stage, QString pp_number, QString t_minute,QString second_action){
    QString url = baseURL+"player_stats?match_id="+match_id+"&club_id="+club_id+"&number="+p_number+"&player_action="+p_action+"&stage="+stage+"&passed_number="+pp_number+"&time_minute="+t_minute+"&second_action="+second_action;
    return url;
}

QString MainWindow::getTeamIDbyName(QString team_name){
    if(team_name == m_team1){
        return m_idTeam1;
    } else {
        return m_idTeam2;
    }
}

void MainWindow::undoPostServer(QString match_id, QString team_id){
    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onGetResult(QNetworkReply*)));
    connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));
    QString url = baseURL+"undo_player_stats?match_id="+match_id+"&team_id="+team_id;
    mgr->get(QNetworkRequest(QUrl(url)));
}

void MainWindow::on_concededButton_released()
{
    if(siapAct){
        m_act = QString("conceded goal");
        tombolAct();
    }
}

void MainWindow::conceedTeam1(){
    for (int i = 0; i<m_jumlahpemain; i++){
        m_num = QString::number(m_playerList1.at(i).nomor);
        m_name =  m_playerList1.at(i).nama;
        m_team = m_team1;
        siapAct = 1;
        on_concededButton_released();
    }
}

void MainWindow::conceedTeam2(){
    for (int i = 0; i<m_jumlahpemain; i++){
        m_num = QString::number(m_playerList2.at(i).nomor);
        m_name =  m_playerList2.at(i).nama;
        m_team = m_team2;
        siapAct = 1;
        on_concededButton_released();
    }
}

void MainWindow::on_fantasyAssistButton_released(){
    if(siapAct){
        m_act = QString("fantasy assist");
        tombolAct();
    }
}
void MainWindow::on_savedPenaltyButton_released(){
    if(siapAct){
        m_act = QString("saved penalty");
        tombolAct();
    }
}

void MainWindow::on_goalHeaderButton_released(){
    if(siapAct){
        m_act = QString("shoot on target");
        tombolAct();
        siapAct = 1;
        m_act = QString("header won");
        QString ket = ("shoot on");
        tombolAct(ket);
        siapAct=1;
        m_act = QString("goal");
        tombolAct();
    }
}
