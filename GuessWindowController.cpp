#include "GuessWindowController.hpp"

GuessWindowController::GuessWindowController(QMainWindow& mainWindow):
    QObject(),
    _mainWindow(mainWindow),
    _mainWindowUI(new Ui_GuessWindow()),
    _db(),
    _currentElement(0),
    _currentKey("s3")
{
    _mainWindowUI->setupUi(&_mainWindow);
    
    _db.loadXML("../testing.xml");
    _mainWindowUI->widgetVocView->setLang("german","french");
    connect(_mainWindowUI->widgetVocView, SIGNAL(correctAnswer()),this,SLOT(nextEntry()));
    connect(_mainWindowUI->widgetVocView, SIGNAL(wrongAnswer()),this,SLOT(countWrong()));
    connect(_mainWindowUI->buttonHint, SIGNAL(clicked(bool)),_mainWindowUI->widgetVocView,SLOT(showHint(bool)));
    connect(_mainWindowUI->buttonSkip, SIGNAL(clicked(bool)),this,SLOT(skip()));
    
    _mainWindowUI->widgetVocView->display(_db.get(_currentElement),_currentKey);
}

void GuessWindowController::skip()
{
    nextEntry();
}

void GuessWindowController::nextEntry()
{
    //std::cout<<"next entry"<<std::endl;
    if (_currentKey=="s3")
    {
        _currentKey="p1";
    }
    else if (_currentKey=="p1")
    {
        _currentKey="p3";
    }
    else
    {
        _currentKey="s3";
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
