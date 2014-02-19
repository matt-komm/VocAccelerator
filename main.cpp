#include <QApplication>
#include <QObject>
#include <QPoint>
#include "ui_textguess.h"

#include <iostream>

#include "Checker.hpp"

int main(int argv, char **args)
{
    QApplication app(argv, args);

    Ui_TextGuessWindow mainUI;
    QMainWindow *mainWindow = new QMainWindow();
    mainUI.setupUi(mainWindow);
    
    Checker* checker = new Checker(mainUI);
    QObject::connect(mainUI.checkButton, SIGNAL(clicked(bool)),checker,SLOT(checkAnswer(bool)));
    mainWindow->show();
    return app.exec();
}




