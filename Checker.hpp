#ifndef __CHECKER_H__
#define __CHECKER_H__

#include <QApplication>
#include <QObject>
#include <QPoint>
#include "ui_textguess.h"

#include <iostream>

class Checker: 
    public QObject
{
    Q_OBJECT
    protected:
        Ui_TextGuessWindow& _wnd;

    public:
        Checker(Ui_TextGuessWindow& wnd);


    public slots:
        void checkAnswer(bool clicked);

};

#endif

