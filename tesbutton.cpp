#include "tesbutton.h"

#include <QtWidgets>

tesbutton::tesbutton()
{

    for (int i = 0; i < 11; ++i) {
        buttons[i] = new QPushButton();
        connect(buttons[i], SIGNAL(clicked()), this, SLOT(digitClicked()));
    }

    horizontalGroupBox = new QGroupBox(tr("Horizontal layout"));
    createButton();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(horizontalGroupBox);

    setLayout(mainLayout);

    isFive = false;
}


void tesbutton::createButton()
{
    if(isFive){
    QVBoxLayout *layout = new QVBoxLayout;

    for (int i = 0; i < 11; i++) {
        //qDebug("createmain");
        buttons[i]->setText(QString::number(i));
        layout->addWidget(buttons[i]);
    }

    horizontalGroupBox->setLayout(layout);
    }
}

void tesbutton::createButton5()
{
//    QVBoxLayout *layout = new QVBoxLayout;

//    for (int i = 0; i < 5; i++) {
//        //qDebug("createmain");
//        buttons[i]->setText(QString::number(i));
//        layout->addWidget(buttons[i]);
//    }

//    horizontalGroupBox->setLayout(layout);

//    QGridLayout *mainLayout = new QGridLayout;
//    mainLayout->addWidget(horizontalGroupBox);

//    setLayout(mainLayout);

    if (!isFive)
    {
        for (int i = 6; i < 11; i++) {
            buttons[i]->hide();
        }
        isFive = true;
    }
}
