#include "VocView.hpp"

#include <iostream>

VocView::VocView(QWidget * parent, Qt::WindowFlags f):
    QWidget(parent,f),
    _conjugationUI(),
    _questionLang(""),
    _answerLang(""),
    _currentVocEntry(0),
    _currentConjugation(0),
    _currentKey("")
{
    _conjugationUI.setupUi(this);
    connect(_conjugationUI.buttonCheck, SIGNAL(clicked(bool)),this,SLOT(checkAnswer(bool)));
}

VocView::~VocView()
{
}

void VocView::setLang(std::string questionLang, std::string answerLang)
{
    _questionLang=questionLang;
    _answerLang=answerLang;
    _conjugationUI.labelQuestion->setText(QString::fromStdString(_questionLang));
    _conjugationUI.labelAnswer->setText(QString::fromStdString(_answerLang));
}

void VocView::display(VocEntry* entry, std::string key)
{
    _currentVocEntry=entry;
    Word* word = entry->getWord(_questionLang);
    _currentConjugation = entry->getWord(_answerLang)->getConjugation("indicative");
    _currentKey=key;
    
    //std::cout<<_currentConjugation->getPerson(key)<<", "<<_currentConjugation->getConjugationForm(key)<<std::endl;
    _conjugationUI.labelPerson->setText(QString::fromStdString(key));
    _conjugationUI.lineeditQuestion->setText(QString::fromStdString(word->getValue()));
    _conjugationUI.lineeditAnswer->setText(QString::fromStdString(_currentConjugation->getPerson(_currentKey)+" "));
}

void VocView::checkAnswer(bool clicked)
{
    //std::cout<<"entered: "<<_conjugationUI.lineeditAnswer->text().toStdString()<<std::endl;
    if (_currentConjugation->getConjugationForm(_currentKey)==_conjugationUI.lineeditAnswer->text().toStdString())
    {
        emit correctAnswer();
    }
    else
    {
        emit wrongAnswer();
    }
}



