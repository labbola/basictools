/********************************************************************************
** Form generated from reading UI file 'frmminute.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMINUTE_H
#define UI_FRMMINUTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_frmMinute
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *minuteEdit;

    void setupUi(QDialog *frmMinute)
    {
        if (frmMinute->objectName().isEmpty())
            frmMinute->setObjectName(QStringLiteral("frmMinute"));
        frmMinute->resize(190, 82);
        buttonBox = new QDialogButtonBox(frmMinute);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(0, 50, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        minuteEdit = new QSpinBox(frmMinute);
        minuteEdit->setObjectName(QStringLiteral("minuteEdit"));
        minuteEdit->setGeometry(QRect(10, 20, 161, 22));

        retranslateUi(frmMinute);
        QObject::connect(buttonBox, SIGNAL(accepted()), frmMinute, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), frmMinute, SLOT(reject()));

        QMetaObject::connectSlotsByName(frmMinute);
    } // setupUi

    void retranslateUi(QDialog *frmMinute)
    {
        frmMinute->setWindowTitle(QApplication::translate("frmMinute", "Minute", 0));
    } // retranslateUi

};

namespace Ui {
    class frmMinute: public Ui_frmMinute {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMINUTE_H
