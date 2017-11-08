/********************************************************************************
** Form generated from reading UI file 'frmsql.ui'
**
** Created: Fri 8. Feb 16:52:36 2013
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSQL_H
#define UI_FRMSQL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_frmSQL
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *frmSQL)
    {
        if (frmSQL->objectName().isEmpty())
            frmSQL->setObjectName(QString::fromUtf8("frmSQL"));
        frmSQL->resize(398, 206);
        buttonBox = new QDialogButtonBox(frmSQL);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(frmSQL);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 70, 113, 20));
        label = new QLabel(frmSQL);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 70, 71, 16));

        retranslateUi(frmSQL);
        QObject::connect(buttonBox, SIGNAL(accepted()), frmSQL, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), frmSQL, SLOT(reject()));

        QMetaObject::connectSlotsByName(frmSQL);
    } // setupUi

    void retranslateUi(QDialog *frmSQL)
    {
        frmSQL->setWindowTitle(QApplication::translate("frmSQL", "Dialog", 0));
        label->setText(QApplication::translate("frmSQL", "nama dbtable", 0));
    } // retranslateUi

};

namespace Ui {
    class frmSQL: public Ui_frmSQL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSQL_H
