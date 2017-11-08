#ifndef FRMSQL_H
#define FRMSQL_H

#include <QDialog>

namespace Ui {
    class frmSQL;
}

class frmSQL : public QDialog
{
    Q_OBJECT

public:
    explicit frmSQL(QWidget *parent = 0);
    ~frmSQL();

private:
    Ui::frmSQL *ui;
};

#endif // FRMSQL_H
