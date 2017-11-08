/********************************************************************************
** Form generated from reading UI file 'loadwarningbox.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADWARNINGBOX_H
#define UI_LOADWARNINGBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_loadWarningBox
{
public:

    void setupUi(QDialog *loadWarningBox)
    {
        if (loadWarningBox->objectName().isEmpty())
            loadWarningBox->setObjectName(QStringLiteral("loadWarningBox"));
        loadWarningBox->resize(361, 165);

        retranslateUi(loadWarningBox);

        QMetaObject::connectSlotsByName(loadWarningBox);
    } // setupUi

    void retranslateUi(QDialog *loadWarningBox)
    {
        loadWarningBox->setWindowTitle(QApplication::translate("loadWarningBox", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class loadWarningBox: public Ui_loadWarningBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADWARNINGBOX_H
