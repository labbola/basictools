/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSaveCSV;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout;
    QPushButton *player_1;
    QPushButton *player_2;
    QPushButton *player_3;
    QPushButton *player_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *player_5;
    QPushButton *player_6;
    QPushButton *player_7;
    QPushButton *player_8;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *player_9;
    QPushButton *player_10;
    QPushButton *player_11;
    QSpacerItem *horizontalSpacer;
    QPushButton *player_subs;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *player2_5;
    QPushButton *player2_6;
    QPushButton *player2_7;
    QPushButton *player2_8;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *player2_1;
    QPushButton *player2_2;
    QPushButton *player2_3;
    QPushButton *player2_4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *player2_9;
    QPushButton *player2_10;
    QPushButton *player2_11;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *player2_subs;
    QTableView *tableView;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_233;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *fouledButton;
    QPushButton *assistButton;
    QPushButton *goalButton;
    QPushButton *freeKickButton;
    QPushButton *foulButton;
    QPushButton *k6Button;
    QPushButton *k7Button;
    QPushButton *chanceButton;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *cornerButton;
    QPushButton *throwinButton;
    QPushButton *clearenceButton;
    QPushButton *interceptButton;
    QPushButton *saveKeeperButton;
    QPushButton *offsideButton;
    QPushButton *penaltyButton;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *dribbleButton;
    QPushButton *crossButton;
    QPushButton *headButton;
    QPushButton *tackleButton;
    QPushButton *passButton;
    QPushButton *shootonButton;
    QPushButton *shootblockedButton;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *crossBlockedButton;
    QPushButton *bodyChButton;
    QPushButton *blockCrossButton;
    QPushButton *looseBallButton;
    QPushButton *shootoffButton;
    QPushButton *blockButton;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_46;
    QGridLayout *gridLayout_2;
    QPushButton *UndoButton;
    QPushButton *redoButton;
    QSpacerItem *verticalSpacer;
    QPushButton *noActionButton;
    QPushButton *yellowCardButton;
    QPushButton *redCardButton;
    QLabel *label;
    QGroupBox *groupBox_4;
    QLCDNumber *lcdNumber;
    QPushButton *StartButton;
    QPushButton *PauseButton;
    QPushButton *StopButton;
    QPushButton *SetButton;
    QWidget *widget_5;
    QPushButton *StartButton_2;
    QPushButton *PauseButton_2;
    QPushButton *StopButton_2;
    QLCDNumber *lcdNumber_3;
    QPushButton *SetButton_2;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(899, 651);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(850, 600));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        QPalette palette;
        QBrush brush(QColor(0, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(170, 170, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(85, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        QBrush brush3(QColor(123, 123, 123, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        MainWindow->setPalette(palette);
        QIcon icon;
        icon.addFile(QStringLiteral("C:/Users/AR2014/Downloads/Logo-only.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLocale(QLocale(QLocale::Indonesian, QLocale::Indonesia));
        actionSaveCSV = new QAction(MainWindow);
        actionSaveCSV->setObjectName(QStringLiteral("actionSaveCSV"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMinimumSize(QSize(888, 620));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 180, 872, 137));
        _2 = new QHBoxLayout(horizontalLayoutWidget);
        _2->setObjectName(QStringLiteral("_2"));
        _2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(horizontalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        player_1 = new QPushButton(groupBox);
        player_1->setObjectName(QStringLiteral("player_1"));

        horizontalLayout->addWidget(player_1);

        player_2 = new QPushButton(groupBox);
        player_2->setObjectName(QStringLiteral("player_2"));

        horizontalLayout->addWidget(player_2);

        player_3 = new QPushButton(groupBox);
        player_3->setObjectName(QStringLiteral("player_3"));

        horizontalLayout->addWidget(player_3);

        player_4 = new QPushButton(groupBox);
        player_4->setObjectName(QStringLiteral("player_4"));

        horizontalLayout->addWidget(player_4);


        gridLayout_7->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        player_5 = new QPushButton(groupBox);
        player_5->setObjectName(QStringLiteral("player_5"));

        horizontalLayout_2->addWidget(player_5);

        player_6 = new QPushButton(groupBox);
        player_6->setObjectName(QStringLiteral("player_6"));

        horizontalLayout_2->addWidget(player_6);

        player_7 = new QPushButton(groupBox);
        player_7->setObjectName(QStringLiteral("player_7"));

        horizontalLayout_2->addWidget(player_7);

        player_8 = new QPushButton(groupBox);
        player_8->setObjectName(QStringLiteral("player_8"));

        horizontalLayout_2->addWidget(player_8);


        gridLayout_7->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        player_9 = new QPushButton(groupBox);
        player_9->setObjectName(QStringLiteral("player_9"));

        horizontalLayout_3->addWidget(player_9);

        player_10 = new QPushButton(groupBox);
        player_10->setObjectName(QStringLiteral("player_10"));

        horizontalLayout_3->addWidget(player_10);

        player_11 = new QPushButton(groupBox);
        player_11->setObjectName(QStringLiteral("player_11"));

        horizontalLayout_3->addWidget(player_11);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        player_subs = new QPushButton(groupBox);
        player_subs->setObjectName(QStringLiteral("player_subs"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("C:/Users/AR2014/Downloads/subst.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        player_subs->setIcon(icon1);
        player_subs->setIconSize(QSize(32, 16));

        horizontalLayout_3->addWidget(player_subs);


        gridLayout_7->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        _2->addWidget(groupBox);

        groupBox_3 = new QGroupBox(horizontalLayoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_8 = new QGridLayout(groupBox_3);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        player2_5 = new QPushButton(groupBox_3);
        player2_5->setObjectName(QStringLiteral("player2_5"));

        horizontalLayout_5->addWidget(player2_5);

        player2_6 = new QPushButton(groupBox_3);
        player2_6->setObjectName(QStringLiteral("player2_6"));

        horizontalLayout_5->addWidget(player2_6);

        player2_7 = new QPushButton(groupBox_3);
        player2_7->setObjectName(QStringLiteral("player2_7"));

        horizontalLayout_5->addWidget(player2_7);

        player2_8 = new QPushButton(groupBox_3);
        player2_8->setObjectName(QStringLiteral("player2_8"));

        horizontalLayout_5->addWidget(player2_8);


        gridLayout_8->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        player2_1 = new QPushButton(groupBox_3);
        player2_1->setObjectName(QStringLiteral("player2_1"));

        horizontalLayout_8->addWidget(player2_1);

        player2_2 = new QPushButton(groupBox_3);
        player2_2->setObjectName(QStringLiteral("player2_2"));

        horizontalLayout_8->addWidget(player2_2);

        player2_3 = new QPushButton(groupBox_3);
        player2_3->setObjectName(QStringLiteral("player2_3"));

        horizontalLayout_8->addWidget(player2_3);

        player2_4 = new QPushButton(groupBox_3);
        player2_4->setObjectName(QStringLiteral("player2_4"));

        horizontalLayout_8->addWidget(player2_4);


        gridLayout_8->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        player2_9 = new QPushButton(groupBox_3);
        player2_9->setObjectName(QStringLiteral("player2_9"));

        horizontalLayout_7->addWidget(player2_9);

        player2_10 = new QPushButton(groupBox_3);
        player2_10->setObjectName(QStringLiteral("player2_10"));

        horizontalLayout_7->addWidget(player2_10);

        player2_11 = new QPushButton(groupBox_3);
        player2_11->setObjectName(QStringLiteral("player2_11"));

        horizontalLayout_7->addWidget(player2_11);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        player2_subs = new QPushButton(groupBox_3);
        player2_subs->setObjectName(QStringLiteral("player2_subs"));
        player2_subs->setIcon(icon1);
        player2_subs->setIconSize(QSize(32, 16));

        horizontalLayout_7->addWidget(player2_subs);


        gridLayout_8->addLayout(horizontalLayout_7, 2, 0, 1, 1);


        _2->addWidget(groupBox_3);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 10, 16777215, 161));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);
        tableView->setMinimumSize(QSize(0, 0));
        tableView->setSizeIncrement(QSize(0, 0));
        tableView->setBaseSize(QSize(800, 100));
        QFont font;
        font.setPointSize(8);
        tableView->setFont(font);
        tableView->setAutoFillBackground(true);
        tableView->setFrameShape(QFrame::StyledPanel);
        tableView->setFrameShadow(QFrame::Plain);
        tableView->setLineWidth(0);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setDragEnabled(false);
        tableView->setAlternatingRowColors(true);
        tableView->setSortingEnabled(true);
        tableView->horizontalHeader()->setVisible(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 320, 815, 216));
        horizontalLayout_233 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_233->setObjectName(QStringLiteral("horizontalLayout_233"));
        horizontalLayout_233->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(horizontalLayoutWidget_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setLayoutDirection(Qt::LeftToRight);
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setAlignment(Qt::AlignCenter);
        groupBox_2->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 50, -1);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, 0, -1, 0);
        fouledButton = new QPushButton(groupBox_2);
        fouledButton->setObjectName(QStringLiteral("fouledButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(fouledButton->sizePolicy().hasHeightForWidth());
        fouledButton->setSizePolicy(sizePolicy3);

        horizontalLayout_9->addWidget(fouledButton);

        assistButton = new QPushButton(groupBox_2);
        assistButton->setObjectName(QStringLiteral("assistButton"));
        sizePolicy3.setHeightForWidth(assistButton->sizePolicy().hasHeightForWidth());
        assistButton->setSizePolicy(sizePolicy3);

        horizontalLayout_9->addWidget(assistButton);

        goalButton = new QPushButton(groupBox_2);
        goalButton->setObjectName(QStringLiteral("goalButton"));
        sizePolicy3.setHeightForWidth(goalButton->sizePolicy().hasHeightForWidth());
        goalButton->setSizePolicy(sizePolicy3);

        horizontalLayout_9->addWidget(goalButton);

        freeKickButton = new QPushButton(groupBox_2);
        freeKickButton->setObjectName(QStringLiteral("freeKickButton"));

        horizontalLayout_9->addWidget(freeKickButton);

        foulButton = new QPushButton(groupBox_2);
        foulButton->setObjectName(QStringLiteral("foulButton"));
        sizePolicy3.setHeightForWidth(foulButton->sizePolicy().hasHeightForWidth());
        foulButton->setSizePolicy(sizePolicy3);

        horizontalLayout_9->addWidget(foulButton);

        k6Button = new QPushButton(groupBox_2);
        k6Button->setObjectName(QStringLiteral("k6Button"));

        horizontalLayout_9->addWidget(k6Button);

        k7Button = new QPushButton(groupBox_2);
        k7Button->setObjectName(QStringLiteral("k7Button"));
        sizePolicy3.setHeightForWidth(k7Button->sizePolicy().hasHeightForWidth());
        k7Button->setSizePolicy(sizePolicy3);

        horizontalLayout_9->addWidget(k7Button);

        chanceButton = new QPushButton(groupBox_2);
        chanceButton->setObjectName(QStringLiteral("chanceButton"));

        horizontalLayout_9->addWidget(chanceButton);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetFixedSize);
        cornerButton = new QPushButton(groupBox_2);
        cornerButton->setObjectName(QStringLiteral("cornerButton"));

        horizontalLayout_6->addWidget(cornerButton);

        throwinButton = new QPushButton(groupBox_2);
        throwinButton->setObjectName(QStringLiteral("throwinButton"));

        horizontalLayout_6->addWidget(throwinButton);

        clearenceButton = new QPushButton(groupBox_2);
        clearenceButton->setObjectName(QStringLiteral("clearenceButton"));

        horizontalLayout_6->addWidget(clearenceButton);

        interceptButton = new QPushButton(groupBox_2);
        interceptButton->setObjectName(QStringLiteral("interceptButton"));

        horizontalLayout_6->addWidget(interceptButton);

        saveKeeperButton = new QPushButton(groupBox_2);
        saveKeeperButton->setObjectName(QStringLiteral("saveKeeperButton"));

        horizontalLayout_6->addWidget(saveKeeperButton);

        offsideButton = new QPushButton(groupBox_2);
        offsideButton->setObjectName(QStringLiteral("offsideButton"));

        horizontalLayout_6->addWidget(offsideButton);

        penaltyButton = new QPushButton(groupBox_2);
        penaltyButton->setObjectName(QStringLiteral("penaltyButton"));

        horizontalLayout_6->addWidget(penaltyButton);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setSizeConstraint(QLayout::SetDefaultConstraint);
        dribbleButton = new QPushButton(groupBox_2);
        dribbleButton->setObjectName(QStringLiteral("dribbleButton"));
        sizePolicy3.setHeightForWidth(dribbleButton->sizePolicy().hasHeightForWidth());
        dribbleButton->setSizePolicy(sizePolicy3);

        horizontalLayout_10->addWidget(dribbleButton);

        crossButton = new QPushButton(groupBox_2);
        crossButton->setObjectName(QStringLiteral("crossButton"));

        horizontalLayout_10->addWidget(crossButton);

        headButton = new QPushButton(groupBox_2);
        headButton->setObjectName(QStringLiteral("headButton"));

        horizontalLayout_10->addWidget(headButton);

        tackleButton = new QPushButton(groupBox_2);
        tackleButton->setObjectName(QStringLiteral("tackleButton"));

        horizontalLayout_10->addWidget(tackleButton);

        passButton = new QPushButton(groupBox_2);
        passButton->setObjectName(QStringLiteral("passButton"));

        horizontalLayout_10->addWidget(passButton);

        shootonButton = new QPushButton(groupBox_2);
        shootonButton->setObjectName(QStringLiteral("shootonButton"));

        horizontalLayout_10->addWidget(shootonButton);

        shootblockedButton = new QPushButton(groupBox_2);
        shootblockedButton->setObjectName(QStringLiteral("shootblockedButton"));

        horizontalLayout_10->addWidget(shootblockedButton);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        crossBlockedButton = new QPushButton(groupBox_2);
        crossBlockedButton->setObjectName(QStringLiteral("crossBlockedButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(crossBlockedButton->sizePolicy().hasHeightForWidth());
        crossBlockedButton->setSizePolicy(sizePolicy4);

        horizontalLayout_11->addWidget(crossBlockedButton);

        bodyChButton = new QPushButton(groupBox_2);
        bodyChButton->setObjectName(QStringLiteral("bodyChButton"));

        horizontalLayout_11->addWidget(bodyChButton);

        blockCrossButton = new QPushButton(groupBox_2);
        blockCrossButton->setObjectName(QStringLiteral("blockCrossButton"));

        horizontalLayout_11->addWidget(blockCrossButton);

        looseBallButton = new QPushButton(groupBox_2);
        looseBallButton->setObjectName(QStringLiteral("looseBallButton"));

        horizontalLayout_11->addWidget(looseBallButton);

        shootoffButton = new QPushButton(groupBox_2);
        shootoffButton->setObjectName(QStringLiteral("shootoffButton"));

        horizontalLayout_11->addWidget(shootoffButton);

        blockButton = new QPushButton(groupBox_2);
        blockButton->setObjectName(QStringLiteral("blockButton"));

        horizontalLayout_11->addWidget(blockButton);


        verticalLayout->addLayout(horizontalLayout_11);


        horizontalLayout_233->addWidget(groupBox_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        groupBox_46 = new QGroupBox(horizontalLayoutWidget_2);
        groupBox_46->setObjectName(QStringLiteral("groupBox_46"));
        sizePolicy3.setHeightForWidth(groupBox_46->sizePolicy().hasHeightForWidth());
        groupBox_46->setSizePolicy(sizePolicy3);
        groupBox_46->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayout_2 = new QGridLayout(groupBox_46);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 5, -1, 0);
        UndoButton = new QPushButton(groupBox_46);
        UndoButton->setObjectName(QStringLiteral("UndoButton"));
        sizePolicy4.setHeightForWidth(UndoButton->sizePolicy().hasHeightForWidth());
        UndoButton->setSizePolicy(sizePolicy4);
        QIcon icon2;
        icon2.addFile(QStringLiteral("C:/Users/AR2014/Downloads/arrow_undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        UndoButton->setIcon(icon2);

        gridLayout_2->addWidget(UndoButton, 0, 0, 1, 1);

        redoButton = new QPushButton(groupBox_46);
        redoButton->setObjectName(QStringLiteral("redoButton"));
        redoButton->setEnabled(true);
        sizePolicy4.setHeightForWidth(redoButton->sizePolicy().hasHeightForWidth());
        redoButton->setSizePolicy(sizePolicy4);
        QIcon icon3;
        icon3.addFile(QStringLiteral("C:/Users/AR2014/Downloads/arrow_redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        redoButton->setIcon(icon3);

        gridLayout_2->addWidget(redoButton, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        noActionButton = new QPushButton(groupBox_46);
        noActionButton->setObjectName(QStringLiteral("noActionButton"));

        gridLayout_2->addWidget(noActionButton, 3, 0, 1, 1);

        yellowCardButton = new QPushButton(groupBox_46);
        yellowCardButton->setObjectName(QStringLiteral("yellowCardButton"));
        QPalette palette1;
        QBrush brush4(QColor(255, 255, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        yellowCardButton->setPalette(palette1);
        yellowCardButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QStringLiteral("C:/Users/AR2014/Downloads/200px-Yellow_card32.png"), QSize(), QIcon::Normal, QIcon::Off);
        yellowCardButton->setIcon(icon4);

        gridLayout_2->addWidget(yellowCardButton, 4, 0, 1, 1);

        redCardButton = new QPushButton(groupBox_46);
        redCardButton->setObjectName(QStringLiteral("redCardButton"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("C:/Users/AR2014/Downloads/60px-Red_card.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        redCardButton->setIcon(icon5);

        gridLayout_2->addWidget(redCardButton, 5, 0, 1, 1);


        horizontalLayout_4->addWidget(groupBox_46);


        horizontalLayout_233->addLayout(horizontalLayout_4);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 540, 231, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Georgia"));
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(570, 530, 301, 61));
        lcdNumber = new QLCDNumber(groupBox_4);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(10, 20, 121, 31));
        lcdNumber->setAutoFillBackground(true);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(8);
        StartButton = new QPushButton(groupBox_4);
        StartButton->setObjectName(QStringLiteral("StartButton"));
        StartButton->setGeometry(QRect(140, 20, 31, 31));
        QIcon icon6;
        icon6.addFile(QStringLiteral("play.png"), QSize(), QIcon::Normal, QIcon::Off);
        StartButton->setIcon(icon6);
        PauseButton = new QPushButton(groupBox_4);
        PauseButton->setObjectName(QStringLiteral("PauseButton"));
        PauseButton->setGeometry(QRect(180, 20, 31, 31));
        QIcon icon7;
        icon7.addFile(QStringLiteral("pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        PauseButton->setIcon(icon7);
        StopButton = new QPushButton(groupBox_4);
        StopButton->setObjectName(QStringLiteral("StopButton"));
        StopButton->setGeometry(QRect(220, 20, 31, 31));
        QIcon icon8;
        icon8.addFile(QStringLiteral("refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        StopButton->setIcon(icon8);
        StopButton->setIconSize(QSize(16, 32));
        SetButton = new QPushButton(groupBox_4);
        SetButton->setObjectName(QStringLiteral("SetButton"));
        SetButton->setGeometry(QRect(260, 20, 31, 31));
        QIcon icon9;
        icon9.addFile(QStringLiteral("eject.png"), QSize(), QIcon::Normal, QIcon::Off);
        SetButton->setIcon(icon9);
        SetButton->setIconSize(QSize(16, 32));
        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(240, 540, 325, 41));
        StartButton_2 = new QPushButton(widget_5);
        StartButton_2->setObjectName(QStringLiteral("StartButton_2"));
        StartButton_2->setGeometry(QRect(160, 10, 31, 31));
        StartButton_2->setIcon(icon6);
        PauseButton_2 = new QPushButton(widget_5);
        PauseButton_2->setObjectName(QStringLiteral("PauseButton_2"));
        PauseButton_2->setGeometry(QRect(200, 10, 31, 31));
        PauseButton_2->setIcon(icon7);
        StopButton_2 = new QPushButton(widget_5);
        StopButton_2->setObjectName(QStringLiteral("StopButton_2"));
        StopButton_2->setGeometry(QRect(241, 9, 31, 31));
        StopButton_2->setIcon(icon8);
        StopButton_2->setIconSize(QSize(16, 32));
        lcdNumber_3 = new QLCDNumber(widget_5);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(30, 10, 121, 31));
        SetButton_2 = new QPushButton(widget_5);
        SetButton_2->setObjectName(QStringLiteral("SetButton_2"));
        SetButton_2->setGeometry(QRect(280, 9, 31, 31));
        SetButton_2->setIcon(icon9);
        SetButton_2->setIconSize(QSize(16, 32));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 590, 191, 31));
        QFont font2;
        font2.setKerning(true);
        label_2->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 899, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSaveCSV);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Basic Stats v0.14.1", 0));
        actionSaveCSV->setText(QApplication::translate("MainWindow", "Save To CSV", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Team 1", 0));
        player_1->setText(QApplication::translate("MainWindow", "P1", 0));
        player_2->setText(QApplication::translate("MainWindow", "P2", 0));
        player_3->setText(QApplication::translate("MainWindow", "P3", 0));
        player_4->setText(QApplication::translate("MainWindow", "P4", 0));
        player_5->setText(QApplication::translate("MainWindow", "P5", 0));
        player_6->setText(QApplication::translate("MainWindow", "P6", 0));
        player_7->setText(QApplication::translate("MainWindow", "P7", 0));
        player_8->setText(QApplication::translate("MainWindow", "P8", 0));
        player_9->setText(QApplication::translate("MainWindow", "P9", 0));
        player_10->setText(QApplication::translate("MainWindow", "P10", 0));
        player_11->setText(QApplication::translate("MainWindow", "P11", 0));
        player_subs->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Team 2", 0));
        player2_5->setText(QApplication::translate("MainWindow", "P5", 0));
        player2_6->setText(QApplication::translate("MainWindow", "P6", 0));
        player2_7->setText(QApplication::translate("MainWindow", "P7", 0));
        player2_8->setText(QApplication::translate("MainWindow", "P8", 0));
        player2_1->setText(QApplication::translate("MainWindow", "P1", 0));
        player2_2->setText(QApplication::translate("MainWindow", "P2", 0));
        player2_3->setText(QApplication::translate("MainWindow", "P3", 0));
        player2_4->setText(QApplication::translate("MainWindow", "P4", 0));
        player2_9->setText(QApplication::translate("MainWindow", "P9", 0));
        player2_10->setText(QApplication::translate("MainWindow", "P10", 0));
        player2_11->setText(QApplication::translate("MainWindow", "P11", 0));
        player2_subs->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Action", 0));
        fouledButton->setText(QApplication::translate("MainWindow", "Fouled\n"
"1", 0));
        assistButton->setText(QApplication::translate("MainWindow", "Assist\n"
"2", 0));
        goalButton->setText(QApplication::translate("MainWindow", "Goal\n"
"3", 0));
        freeKickButton->setText(QApplication::translate("MainWindow", "Free Kick\n"
"4", 0));
        foulButton->setText(QApplication::translate("MainWindow", "Foul\n"
"5", 0));
        k6Button->setText(QApplication::translate("MainWindow", "Own Goal\n"
"6", 0));
        k7Button->setText(QApplication::translate("MainWindow", "HandBall\n"
"7", 0));
        chanceButton->setText(QApplication::translate("MainWindow", "Create Chance\n"
"8", 0));
        cornerButton->setText(QApplication::translate("MainWindow", "Corner\n"
"Q", 0));
        throwinButton->setText(QApplication::translate("MainWindow", "Throw in\n"
"W", 0));
        clearenceButton->setText(QApplication::translate("MainWindow", "Clearance\n"
"E", 0));
        interceptButton->setText(QApplication::translate("MainWindow", "Intercept\n"
"R", 0));
        saveKeeperButton->setText(QApplication::translate("MainWindow", "Save\n"
"T", 0));
        offsideButton->setText(QApplication::translate("MainWindow", "Offside\n"
"Y", 0));
        penaltyButton->setText(QApplication::translate("MainWindow", "Penalty\n"
"U", 0));
        dribbleButton->setText(QApplication::translate("MainWindow", "Dribble\n"
"CAPS", 0));
        crossButton->setText(QApplication::translate("MainWindow", "Cross\n"
"A", 0));
        headButton->setText(QApplication::translate("MainWindow", "Head\n"
"S", 0));
        tackleButton->setText(QApplication::translate("MainWindow", "Tackle\n"
"D", 0));
        passButton->setText(QApplication::translate("MainWindow", "Pass\n"
"F", 0));
        shootonButton->setText(QApplication::translate("MainWindow", "Shoot On\n"
"G", 0));
        shootblockedButton->setText(QApplication::translate("MainWindow", "Shot Blocked\n"
"H", 0));
        crossBlockedButton->setText(QApplication::translate("MainWindow", "Cross Blocked\n"
"Z", 0));
        bodyChButton->setText(QApplication::translate("MainWindow", "Body Charge\n"
"X", 0));
        blockCrossButton->setText(QApplication::translate("MainWindow", "Block Cross\n"
"C", 0));
        looseBallButton->setText(QApplication::translate("MainWindow", "Loose Ball\n"
"V", 0));
        shootoffButton->setText(QApplication::translate("MainWindow", "Shot Off\n"
"B", 0));
        blockButton->setText(QApplication::translate("MainWindow", "Block\n"
"N", 0));
        groupBox_46->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        UndoButton->setText(QString());
        redoButton->setText(QString());
        noActionButton->setText(QApplication::translate("MainWindow", "no action", 0));
        yellowCardButton->setText(QApplication::translate("MainWindow", "Card", 0));
        redCardButton->setText(QApplication::translate("MainWindow", "Card", 0));
        label->setText(QString());
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Timer", 0));
        StartButton->setText(QString());
        PauseButton->setText(QString());
        StopButton->setText(QString());
        SetButton->setText(QString());
        StartButton_2->setText(QString());
        PauseButton_2->setText(QString());
        StopButton_2->setText(QString());
        SetButton_2->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Hak Cipta \302\251 2016 Labbola.com ", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
