#ifndef __CHECKER_H__
#define __CHECKER_H__

#include <QApplication>
#include <QObject>
#include <QPoint>
#include "ui_GuessWindow.h"

#include <iostream>
#include <list>

class GuessWindowController: 
    public QObject
{
    Q_OBJECT
    protected:
        QMainWindow& _mainWindow;
        Ui_GuessWindow* _mainWindowUI;
        Database _db;
        unsigned int _currentElement;
        std::string _currentKey;
    public:
        GuessWindowController(QMainWindow& mainWindow);

    public slots:
        void nextEntry();
        void countWrong();

};

#endif

