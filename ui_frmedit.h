/********************************************************************************
** Form generated from reading UI file 'frmedit.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMEDIT_H
#define UI_FRMEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_frmEdit
{
public:
    QDialogButtonBox *buttonBox;
    QTableView *tableView;
    QPushButton *moveUpButton;
    QPushButton *moveDownButton;
    QLabel *label;
    QPushButton *colorTeamButton;
    QLabel *label_2;
    QLineEdit *nameTeamEdit;
    QLabel *label_3;
    QPushButton *loadButton;
    QFrame *line;
    QPushButton *saveButton;
    QLineEdit *idMatchEdit;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *idTeamEdit;
    QPushButton *saveMopButton;

    void setupUi(QDialog *frmEdit)
    {
        if (frmEdit->objectName().isEmpty())
            frmEdit->setObjectName(QStringLiteral("frmEdit"));
        frmEdit->setEnabled(true);
        frmEdit->resize(560, 380);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmEdit->sizePolicy().hasHeightForWidth());
        frmEdit->setSizePolicy(sizePolicy);
        frmEdit->setMinimumSize(QSize(560, 380));
        frmEdit->setMaximumSize(QSize(560, 380));
        frmEdit->setBaseSize(QSize(560, 380));
        buttonBox = new QDialogButtonBox(frmEdit);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(300, 330, 161, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableView = new QTableView(frmEdit);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 20, 401, 201));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setWordWrap(false);
        tableView->setCornerButtonEnabled(true);
        tableView->verticalHeader()->setDefaultSectionSize(20);
        tableView->verticalHeader()->setMinimumSectionSize(15);
        moveUpButton = new QPushButton(frmEdit);
        moveUpButton->setObjectName(QStringLiteral("moveUpButton"));
        moveUpButton->setGeometry(QRect(431, 20, 31, 41));
        sizePolicy.setHeightForWidth(moveUpButton->sizePolicy().hasHeightForWidth());
        moveUpButton->setSizePolicy(sizePolicy);
        moveUpButton->setMaximumSize(QSize(560, 400));
        moveUpButton->setSizeIncrement(QSize(100, 100));
        QFont font;
        font.setPointSize(12);
        moveUpButton->setFont(font);
        moveDownButton = new QPushButton(frmEdit);
        moveDownButton->setObjectName(QStringLiteral("moveDownButton"));
        moveDownButton->setGeometry(QRect(430, 80, 31, 41));
        sizePolicy.setHeightForWidth(moveDownButton->sizePolicy().hasHeightForWidth());
        moveDownButton->setSizePolicy(sizePolicy);
        moveDownButton->setMaximumSize(QSize(560, 400));
        moveDownButton->setSizeIncrement(QSize(100, 100));
        moveDownButton->setFont(font);
        label = new QLabel(frmEdit);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 220, 581, 41));
        label->setTextFormat(Qt::AutoText);
        label->setWordWrap(true);
        colorTeamButton = new QPushButton(frmEdit);
        colorTeamButton->setObjectName(QStringLiteral("colorTeamButton"));
        colorTeamButton->setGeometry(QRect(300, 290, 161, 23));
        label_2 = new QLabel(frmEdit);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 260, 71, 16));
        nameTeamEdit = new QLineEdit(frmEdit);
        nameTeamEdit->setObjectName(QStringLiteral("nameTeamEdit"));
        nameTeamEdit->setGeometry(QRect(300, 260, 161, 20));
        label_3 = new QLabel(frmEdit);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 290, 71, 16));
        loadButton = new QPushButton(frmEdit);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setGeometry(QRect(490, 20, 61, 41));
        line = new QFrame(frmEdit);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(470, 20, 20, 341));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        saveButton = new QPushButton(frmEdit);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(490, 80, 61, 41));
        idMatchEdit = new QLineEdit(frmEdit);
        idMatchEdit->setObjectName(QStringLiteral("idMatchEdit"));
        idMatchEdit->setGeometry(QRect(90, 260, 113, 20));
        label_4 = new QLabel(frmEdit);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 260, 47, 13));
        label_5 = new QLabel(frmEdit);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 291, 47, 13));
        idTeamEdit = new QLineEdit(frmEdit);
        idTeamEdit->setObjectName(QStringLiteral("idTeamEdit"));
        idTeamEdit->setGeometry(QRect(90, 291, 113, 20));
        saveMopButton = new QPushButton(frmEdit);
        saveMopButton->setObjectName(QStringLiteral("saveMopButton"));
        saveMopButton->setGeometry(QRect(490, 140, 61, 41));
        buttonBox->raise();
        tableView->raise();
        moveUpButton->raise();
        moveDownButton->raise();
        label->raise();
        colorTeamButton->raise();
        label_2->raise();
        nameTeamEdit->raise();
        label_3->raise();
        loadButton->raise();
        line->raise();
        saveButton->raise();
        idMatchEdit->raise();
        idTeamEdit->raise();
        label_4->raise();
        label_5->raise();
        saveMopButton->raise();

        retranslateUi(frmEdit);

        QMetaObject::connectSlotsByName(frmEdit);
    } // setupUi

    void retranslateUi(QDialog *frmEdit)
    {
        frmEdit->setWindowTitle(QApplication::translate("frmEdit", "Dialog", 0));
#ifndef QT_NO_TOOLTIP
        moveUpButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        moveUpButton->setText(QApplication::translate("frmEdit", "\342\226\262", 0));
#ifndef QT_NO_TOOLTIP
        moveDownButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        moveDownButton->setText(QApplication::translate("frmEdit", "\342\226\274", 0));
        label->setText(QApplication::translate("frmEdit", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Gunakan baris 1-11 sebagai pemain utama. Baris lainnya untuk cadangan.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Use 1-11th row as a main player on the field. Other rows as a substitute player.</span></p></body></html>", 0));
        colorTeamButton->setText(QApplication::translate("frmEdit", "color", 0));
        label_2->setText(QApplication::translate("frmEdit", "Team Name", 0));
        label_3->setText(QApplication::translate("frmEdit", "Team Color", 0));
        loadButton->setText(QApplication::translate("frmEdit", "Load \n"
" Profile", 0));
        saveButton->setText(QApplication::translate("frmEdit", "Save \n"
" Profile", 0));
        label_4->setText(QApplication::translate("frmEdit", "Match ID", 0));
        label_5->setText(QApplication::translate("frmEdit", "Team ID", 0));
        saveMopButton->setText(QApplication::translate("frmEdit", "Save\n"
"MOP", 0));
    } // retranslateUi

};

namespace Ui {
    class frmEdit: public Ui_frmEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMEDIT_H
