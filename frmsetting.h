#ifndef FRMSETTING_H
#define FRMSETTING_H

#include <QDialog>

namespace Ui {
    class frmSetting;
}

class frmSetting : public QDialog
{
    Q_OBJECT

public:
    explicit frmSetting(QWidget *parent = 0);
    ~frmSetting();
    int getNumPlayer();
    QString getStage();
    QString getbaseURL();
    int getTotalPlayer();


private:
    Ui::frmSetting *ui;

    int m_jumlahpemain;
    int m_totalpemain;
    QString m_stage;
    QString m_baseURL;

private slots:
    void on_combo_jumlahpemain_currentIndexChanged(QString n);
    void on_combo_stage_currentIndexChanged(QString s);
    void on_line_baseURL_textChanged(QString );
    void on_spin_totalpemain_valueChanged(int arg1);
//    void on_combo_jumlahpemain_currentIndexChanged(int index);
};

#endif // FRMSETTING_H
