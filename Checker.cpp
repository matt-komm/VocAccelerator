#include "Checker.hpp"

Checker::Checker(Ui_TextGuessWindow& wnd):
    _wnd(wnd)
{ 
}

void Checker::checkAnswer(bool clicked)
{
    std::cout<<_wnd.answerTextField->text().toStdString()<<std::endl;
}




