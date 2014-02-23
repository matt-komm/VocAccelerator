#include "GuessWindowController.hpp"

GuessWindowController::GuessWindowController(QMainWindow& mainWindow):
    QObject(),
    _mainWindow(mainWindow),
    _mainWindowUI(new Ui_GuessWindow()),
    _db(),
    _currentElement(0),
    _currentKey("s1")
{
    _mainWindowUI->setupUi(&_mainWindow);
    
    _db.loadXML("../testing.xml");
    _mainWindowUI->widgetVocView->setLang("german","french");
    connect(_mainWindowUI->widgetVocView, SIGNAL(correctAnswer()),this,SLOT(nextEntry()));
    connect(_mainWindowUI->widgetVocView, SIGNAL(wrongAnswer()),this,SLOT(countWrong()));
    _mainWindowUI->widgetVocView->display(_db.get(_currentElement),_currentKey);
}

void GuessWindowController::nextEntry()
{
    //std::cout<<"next entry"<<std::endl;
    if (_currentKey=="s1")
    {
        _currentKey="s2";
    }
    else if (_currentKey=="s2")
    {
        _currentKey="s3";
    }
    else
    {
        _currentKey="s1";
        ++_currentElement;
        if (_currentElement>=_db.size())
        {
            _currentElement=0;
        }
    }
    _mainWindowUI->widgetVocView->display(_db.get(_currentElement),_currentKey);
}

void GuessWindowController::countWrong()
{
    _mainWindowUI->lcdNumberFalse->display(int(_mainWindowUI->lcdNumberFalse->value()+1.1));
}
