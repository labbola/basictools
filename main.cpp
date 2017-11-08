//#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QApplication>
#include <QNetworkInterface>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QString settingsPath = QDir::currentPath() + "/license.txt";

    if (w.licenseFileExist()) {
        if (w.macAddressDefined(settingsPath)) {
            w.show();
        } else {
            QMessageBox msgBox;
            msgBox.setText("You don't have a valid registered license!");
            msgBox.exec();

            a.quit();
            return 0;
        }
    } else {
        QString tempMacAddress = "MAC address:: (only for debugging): " + w.getMacAddress();

        QMessageBox msgBox;
        msgBox.setText(tempMacAddress);
        msgBox.exec();

        if (w.connectDatabase()) {
            w.show();
        } else {
            QMessageBox msgBox;
            msgBox.setText("You don't have a valid license!");
            msgBox.exec();

            a.quit();
            return 0;
        }
    }
    return a.exec();
}
