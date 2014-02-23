#ifndef __VOCVIEW_H__
#define __VOCVIEW_H__


#include "Database.hpp"

#include "ui_default.h"
#include "ui_conjugation.h"

#include <QWidget>
#include <vector>

class VocView:
    public QWidget
{
    Q_OBJECT

    protected:
        Ui_ConjugationView _conjugationUI;
        std::string _questionLang;
        std::string _answerLang;
        VocEntry* _currentVocEntry;
        
        Conjugation* _currentConjugation;
        std::string _currentKey;
    public:
        VocView(QWidget * parent = 0, Qt::WindowFlags f = 0);
        ~VocView();
        
        void setLang(std::string questionLang, std::string answerLang);
        void display(VocEntry* entry, std::string key);
        
    signals:
        void correctAnswer();
        void wrongAnswer();
        
    public slots:
        void checkAnswer(bool clicked);
        
};

#endif

