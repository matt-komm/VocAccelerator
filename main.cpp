#include <QApplication>
#include <QObject>
#include <QPoint>

#include <iostream>

#include "Database.hpp"
#include "GuessWindowController.hpp"

int main(int argv, char **args)
{   
    
    
    QApplication app(argv, args);

    QMainWindow mainWindow;
    GuessWindowController guessWindowController(mainWindow);
    
    //Checker* checker = new Checker(mainUI);
    //QObject::);
    mainWindow.show();
    return app.exec();
    

    return 0;
}





