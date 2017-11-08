/********************************************************************************
** Form generated from reading UI file 'dialogsave.ui'
**
** Created: Fri 8. Feb 16:52:35 2013
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSAVE_H
#define UI_DIALOGSAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogSave
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogSave)
    {
        if (DialogSave->objectName().isEmpty())
            DialogSave->setObjectName(QString::fromUtf8("DialogSave"));
        DialogSave->resize(375, 89);
        verticalLayout = new QVBoxLayout(DialogSave);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(DialogSave);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        buttonBox = new QDialogButtonBox(DialogSave);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogSave);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogSave, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogSave, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogSave);
    } // setupUi

    void retranslateUi(QDialog *DialogSave)
    {
        DialogSave->setWindowTitle(QApplication::translate("DialogSave", "Save As..", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogSave: public Ui_DialogSave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSAVE_H
