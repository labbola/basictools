#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QLCDNumber>
#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QSqlDatabase>
#include "dialogsave.h"
#include "frmedit.h"
#include "frmsubstitute.h"
#include "frmsetting.h"
#include "frmminute.h"
//#include "tesbutton.h"

QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QCheckBox;
class QGroupBox;
class QLabel;
class QLineEdit;
QT_END_NAMESPACE

namespace Ui {
    class MainWindow;
}

enum MODE_ENUM{
    MODE_EDIT_TABLE,
    MODE_PLAY
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool licenseFileExist();
    bool connectDatabase();
    QString getMacAddress();
    bool macAddressDefined(const QString &settingsPath);
    void generateLicense(const QString &license);
    void addResult(QAbstractItemModel *model, int line, const QString num, const QString name, const QString team, const QString act);
    void addResult(QAbstractItemModel *model, int line, const QString num, const QString name, const QString team, const QString act, const QString act2);
    void addResultPassing(QAbstractItemModel *model, int line, const QString num, const QString name, const QString team, const QString act, const QString tonum, const QString toname);
    void addResultPassing(QAbstractItemModel *model, int line, const QString num, const QString name, const QString team, const QString act, const QString tonum, const QString toname, const QString act2);
    void tombolAct();
    void tombolAct(QString information);
    void tombolActPassing();
    void changeColorButton(int player, bool clickedColor);
    void colorFromTo(int from, int to);
    void buttonProp(QPushButton *button, bool berwarna);
    void buttonChangeName(QPushButton *button, int noPlayer, QString namaPlayer);
    void initPlayer();
    void refreshPlayer1();
    void refreshPlayer2();
    void saveAsFile(QString filename);
    int  saveFileOnExit();
    void changeNumPlayer(int size);
    int i;
    int j;
    static int mjudul;

    static int getnumjudul()
    {
        static int sjudul = 0;
        sjudul++;

        return sjudul;
    }



protected:
    void keyReleaseEvent(QKeyEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    void initialize();
    DialogSave saveBox;

    frmEdit formEditPlayer;
    frmEdit formEditPlayer2;
    frmSubstitute formSubs1;
    frmSubstitute formSubs2;
    frmSetting  formSetting;
    frmMinute formMinute;

    QSqlDatabase m_db;
    QString m_license;
    QStandardItemModel m_model;
    QString baseURL;
    QString m_num;
    QString m_name;
    QString m_act;
    QString m_team, m_team1, m_team2;
    QString m_idTeam1, m_idTeam2, m_idMatch, stage;
    QString m_passingteam, m_numpass, m_passingfrom, m_passingto;
    QColor m_color1, m_color2;
    int m_jumlahpemain;
    int m_totalpemain;
    int siapAct;
    int curPlayer;
    bool isPassing;
    int sizeUndo;
    int startUndo;
    QString m_appsTitle;

    QList<playerStruct> m_playerList1;
    QList<playerStruct> m_playerList2;
    QStandardItemModel undomodel;
    bool isChanged;
    bool m_shft;
    bool m_ctrl;
    bool m_space;
    bool isGoal;

    MODE_ENUM mode;

    QPushButton *start;
    QPushButton *stop;
    QPushButton *pause;
    QTime *time;
    QTimer *timer;
    QPushButton *start2;
    QPushButton *stop2;
    QPushButton *pause2;
    QTime *time2;
    QTimer *timer2;
    QLCDNumber *injurt;

    QPushButton *setminute;
    QPushButton *setminute2;

    int minute;

public slots:
//    void closeApp();

private slots:


    void on_k7Button_released();
    void on_k6Button_released();
    void on_tableView_entered(QModelIndex index);
    void on_tableView_doubleClicked(QModelIndex index);
    void on_saveKeeperButton_released();
    void on_redCardButton_released();
    void on_yellowCardButton_clicked();
    void on_redoButton_clicked();
    void on_player2_subs_clicked();
    void on_player_subs_clicked();

    //player 2
    void on_player2_11_released();
    void on_player2_10_released();
    void on_player2_9_released();
    void on_player2_8_released();
    void on_player2_7_released();
    void on_player2_6_released();
    void on_player2_5_released();
    void on_player2_4_released();
    void on_player2_3_released();
    void on_player2_2_released();
    void on_player2_1_released();

    //player 1
    void on_player_11_released();
    void on_player_10_released();
    void on_player_9_released();
    void on_player_8_released();
    void on_player_7_released();
    void on_player_6_released();
    void on_player_5_released();
    void on_player_4_released();
    void on_player_3_released();
    void on_player_2_released();
    void on_player_1_released();


    //Action
    void on_foulButton_released();
    void on_interceptButton_released();
    void on_assistButton_released();
    void on_fouledButton_released();
    void on_noActionButton_released();
    void on_goalButton_released();
    void on_offsideButton_released();
    void on_freeKickButton_released();
    void on_cornerButton_released();
    void on_throwinButton_released();
    void on_headfButton_released();
    void on_headButton_released();
    void on_crossfButton_released();
    void on_crossButton_released();
    void on_tacklefButton_released();
    void on_tackleButton_released();
    void on_shootonButton_released();
    void on_passfButton_released();
    void on_passButton_pressed();
    void on_passButton_released();
    void on_shootoffButton_released();
    void on_clearenceButton_released();
    void on_shootblockedButton_released();
    void on_dribbleButton_clicked();
    void on_blockButton_released();
    void on_unDribbleButton_released();
    //add new jan 2013
    void on_looseBallButton_released();
    void on_crossBlockedButton_released();
    void on_bodyChButton_released();
    void on_blockCrossButton_released();
    void on_interceptfButton_released();
    void goalSet(QString ket);

    void newFile();
    void saveFile();
    void saveAsFile();
    void loadFile();
    void loadFileExtended();
    void on_tulis(QString str);
    void editTeam();
    void editTeam2();
    void preferences();

    void on_UndoButton_released();

    //add new FEB 2014
    void on_penMissedButton_released();
    void on_chanceButton_released();
    void on_penaltyButton_released();
    //add new MAR 2014
    void mulai();
    void tunda();
    void berhenti();
    void showTime();
    void mulai2();
    void tunda2();
    void berhenti2();
    void ubahmenit();
    void ubahmenit2();
    void showTime2();
    QString generateURL(QString match_id, QString club_id, QString p_number, QString p_action, QString stage="1st%20half", QString pp_number="0", QString t_minute="0", QString second_action="");
    void postServer(QString match_id, QString club_id, QString p_number, QString p_action, QString stage="1st%20half", QString pp_number="0", QString t_minute="0", QString second_action="");
    void onGetResult(QNetworkReply *rep);
    QString getTeamIDbyName(QString team_name);
    void undoPostServer(QString match_id, QString team_id);

    //add new Juni 2016
    void conceedTeam1();
    void conceedTeam2();
    void on_concededButton_released();

    //add new agustus 2016
    void on_fantasyAssistButton_released();
    void on_savedPenaltyButton_released();
    void on_goalHeaderButton_released();

signals:
    void tulis(QString str);
};

#endif // MAINWINDOW_H
