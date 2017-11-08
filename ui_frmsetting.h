/********************************************************************************
** Form generated from reading UI file 'frmsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSETTING_H
#define UI_FRMSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_frmSetting
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QLabel *label;
    QComboBox *combo_jumlahpemain;
    QLabel *label_2;
    QComboBox *combo_stage;
    QLabel *label_3;
    QLineEdit *line_baseURL;
    QLabel *label_4;
    QSpinBox *spin_totalpemain;

    void setupUi(QDialog *frmSetting)
    {
        if (frmSetting->objectName().isEmpty())
            frmSetting->setObjectName(QStringLiteral("frmSetting"));
        frmSetting->resize(335, 230);
        gridLayout = new QGridLayout(frmSetting);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(frmSetting);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

        groupBox = new QGroupBox(frmSetting);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 91, 21));
        combo_jumlahpemain = new QComboBox(groupBox);
        combo_jumlahpemain->setObjectName(QStringLiteral("combo_jumlahpemain"));
        combo_jumlahpemain->setGeometry(QRect(200, 30, 74, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 47, 13));
        combo_stage = new QComboBox(groupBox);
        combo_stage->setObjectName(QStringLiteral("combo_stage"));
        combo_stage->setGeometry(QRect(200, 60, 74, 22));
        combo_stage->setEditable(false);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 120, 61, 16));
        line_baseURL = new QLineEdit(groupBox);
        line_baseURL->setObjectName(QStringLiteral("line_baseURL"));
        line_baseURL->setGeometry(QRect(72, 120, 201, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 90, 61, 16));
        spin_totalpemain = new QSpinBox(groupBox);
        spin_totalpemain->setObjectName(QStringLiteral("spin_totalpemain"));
        spin_totalpemain->setGeometry(QRect(200, 90, 71, 22));
        spin_totalpemain->setMinimum(11);
        spin_totalpemain->setMaximum(30);
        spin_totalpemain->setValue(20);

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(frmSetting);
        QObject::connect(buttonBox, SIGNAL(accepted()), frmSetting, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), frmSetting, SLOT(reject()));

        combo_jumlahpemain->setCurrentIndex(1);
        combo_stage->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmSetting);
    } // setupUi

    void retranslateUi(QDialog *frmSetting)
    {
        frmSetting->setWindowTitle(QApplication::translate("frmSetting", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("frmSetting", "General", 0));
        label->setText(QApplication::translate("frmSetting", "Number of Player", 0));
        combo_jumlahpemain->clear();
        combo_jumlahpemain->insertItems(0, QStringList()
         << QApplication::translate("frmSetting", "5", 0)
         << QApplication::translate("frmSetting", "11", 0)
        );
        label_2->setText(QApplication::translate("frmSetting", "Stage", 0));
        combo_stage->clear();
        combo_stage->insertItems(0, QStringList()
         << QApplication::translate("frmSetting", "1st half", 0)
         << QApplication::translate("frmSetting", "2nd half", 0)
         << QApplication::translate("frmSetting", "1ex half", 0)
         << QApplication::translate("frmSetting", "2ex half", 0)
        );
        label_3->setText(QApplication::translate("frmSetting", "Base URL", 0));
        label_4->setText(QApplication::translate("frmSetting", "Total Player", 0));
    } // retranslateUi

};

namespace Ui {
    class frmSetting: public Ui_frmSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSETTING_H
