#ifndef FRMEDIT_H
#define FRMEDIT_H

#include <QDialog>
#include <QStandardItemModel>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>


struct playerStruct {
    int     nomor;
    QString nama;
    QString team;
    QString posisi;
    QString mop;
};

namespace Ui {
    class frmEdit;
}

class frmEdit : public QDialog
{
    Q_OBJECT

public:
    explicit frmEdit(QWidget *parent = 0);
    ~frmEdit();

    void    initializeTable();
    int     getPlayerNumber(int tombol);
    QString getPlayerNumString(int tombol);
    QString getPlayerTeam(int tombol);
    QString getPlayerPosition(int tombol);
    QString getPlayerMop(int tombol);
    QString getPlayerName(int tombol);

    QString getTeamName();
    QString getTeamID();
    QString getMacthID();
    QColor  getTeamColor();

    int     getSizePlayer();

    int     substitute(int mainNumber, int subsNumber);

    int saveProfile();
    void loadProfile();

    void commitChange();

    void setBaseUrl(QString url);

    void setSizePlayer(int size);

//    void moveUp;
//    void moveDown;


private:
    Ui::frmEdit *ui;

    playerStruct m_playerStruct;
    QStandardItemModel m_model;
    QStandardItemModel m_modelTemp;
    QString m_nameTeam;
    QString m_idTeam;
    QString m_idMatch;
    QColor m_colorTeam;
    QString base_url;

    int m_tableSize;
    //QList<playerStruct> m_listPlayerStruct;

private slots:
    void on_saveButton_released();
    void on_loadButton_released();
    void on_buttonBox_accepted();
    void on_nameTeamEdit_textChanged(QString );
    void on_tableSelect(QModelIndex ind);
    void on_idTeamEdit_textChanged(QString );
    void on_idMatchEdit_textChanged(QString );
    void moveUp();
    void moveDown();
    void changeColorTeam();
    void doubleClickTable(QModelIndex val);
    void on_saveMopButton_released();
    void postServer();
    void onGetResult(QNetworkReply *rep);

signals:
    void siapAccept();

};

#endif // FRMEDIT_H
