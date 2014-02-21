#include <QApplication>
#include <QObject>
#include <QPoint>
#include "ui_base.h"

#include <iostream>

#include "Database.hpp"

int main(int argv, char **args)
{   
    Database db;
    db.loadXML("../testing.xml");
    
    QApplication app(argv, args);

    Ui_MainWindow mainUI;
    QMainWindow *mainWindow = new QMainWindow();
    mainUI.setupUi(mainWindow);
    
    //Checker* checker = new Checker(mainUI);
    //QObject::connect(mainUI.checkButton, SIGNAL(clicked(bool)),checker,SLOT(checkAnswer(bool)));
    mainWindow->show();
    return app.exec();
    

    return 0;
}





