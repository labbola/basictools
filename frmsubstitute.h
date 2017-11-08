#ifndef FRMSUBSTITUTE_H
#define FRMSUBSTITUTE_H

#include <QDialog>

namespace Ui {
    class frmSubstitute;
}

class frmSubstitute : public QDialog
{
    Q_OBJECT

public:
    explicit frmSubstitute(QWidget *parent = 0);
    ~frmSubstitute();

    void addCombo(QString no, QString name);
    void clearCombo();
    void addCombo2(QString no, QString name);
    void clearCombo2();
    int getSubsPlayer1();
    int getSubsPlayer2();

    void createMain();
    void createSubs();
    void aturButton(int size);
    int getPlayerindex(QString num);
    void setSizeSubs(int size);

private:
    Ui::frmSubstitute *ui;

    int m_selected;
    int m_selectedSubs;
    int m_totalsubs;
    int m_totalsubinit;

    QPushButton *buttons[11];
    QPushButton *subsBu[16];


    void createInit();

private slots:
    void on_pushButton_clicked();
    void on_buttonBox_accepted();
    void digitClicked();
    void subsdigitClicked();
};

#endif // FRMSUBSTITUTE_H
