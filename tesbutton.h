#ifndef TESBUTTON_H
#define TESBUTTON_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QGroupBox;
class QPushButton;
QT_END_NAMESPACE

class tesbutton : public QDialog
{
    Q_OBJECT
public:
    tesbutton();

    void createButton();
    void createButton5();

    QGroupBox *horizontalGroupBox;
    QPushButton *buttons[11];


private:
    int isFive;

};

#endif // TESBUTTON_H
