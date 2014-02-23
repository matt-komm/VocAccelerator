#ifndef __CONJUGATION_H__
#define __CONJUGATION_H__

#include "tinyxml2.h"

class Word;

#include <string>
#include <map>

class Conjugation   
{
    protected:
        Word* _baseWord;
        std::string _temp;
        
        static const std::string SINGULAR_1PERSON;
        static const std::string SINGULAR_2PERSON;
        static const std::string SINGULAR_3PERSON;

        static const std::string PLURAL_1PERSON;
        static const std::string PLURAL_2PERSON;
        static const std::string PLURAL_3PERSON;
        
        std::map<std::string, std::string> _conjugationForms;
        std::map<std::string, std::string> _persons;
        
    public:
        Conjugation(Word* baseWord, std::string temp);
        static Conjugation* loadFromXML(Word* word, tinyxml2::XMLElement* element);
        static void initPersonsByLang(Conjugation* conjugation, std::string lang);
        void addConjugationForm(std::string person, std::string form);
        void addPerson(std::string person, std::string form);
        inline std::string getTemp() const
        {
            return _temp;
        }
        inline std::string getPerson(std::string key)
        {
            return _persons[key];
        }
        inline std::string getConjugationForm(std::string key)
        {
            return _conjugationForms[key];
        }
        
        ~Conjugation();
};


#endif

