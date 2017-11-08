/********************************************************************************
** Form generated from reading UI file 'frmsubstitute.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSUBSTITUTE_H
#define UI_FRMSUBSTITUTE_H

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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_frmSubstitute
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;

    void setupUi(QDialog *frmSubstitute)
    {
        if (frmSubstitute->objectName().isEmpty())
            frmSubstitute->setObjectName(QStringLiteral("frmSubstitute"));
        frmSubstitute->resize(254, 550);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmSubstitute->sizePolicy().hasHeightForWidth());
        frmSubstitute->setSizePolicy(sizePolicy);
        frmSubstitute->setMinimumSize(QSize(200, 360));
        frmSubstitute->setMaximumSize(QSize(270, 800));
        gridLayout = new QGridLayout(frmSubstitute);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox = new QComboBox(frmSubstitute);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 2);

        comboBox_2 = new QComboBox(frmSubstitute);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setEnabled(true);

        gridLayout->addWidget(comboBox_2, 0, 2, 1, 1);

        groupBox = new QGroupBox(frmSubstitute);
        groupBox->setObjectName(QStringLiteral("groupBox"));

        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(frmSubstitute);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));

        gridLayout->addWidget(groupBox_2, 1, 1, 1, 2);

        buttonBox = new QDialogButtonBox(frmSubstitute);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 2);

        pushButton = new QPushButton(frmSubstitute);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 3, 2, 1, 1);


        retranslateUi(frmSubstitute);
        QObject::connect(buttonBox, SIGNAL(accepted()), frmSubstitute, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), frmSubstitute, SLOT(reject()));

        QMetaObject::connectSlotsByName(frmSubstitute);
    } // setupUi

    void retranslateUi(QDialog *frmSubstitute)
    {
        frmSubstitute->setWindowTitle(QApplication::translate("frmSubstitute", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("frmSubstitute", "Main Player", 0));
        groupBox_2->setTitle(QApplication::translate("frmSubstitute", "Substitute", 0));
        pushButton->setText(QApplication::translate("frmSubstitute", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class frmSubstitute: public Ui_frmSubstitute {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSUBSTITUTE_H
