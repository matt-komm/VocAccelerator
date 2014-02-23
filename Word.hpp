#ifndef __WORD_H__
#define __WORD_H__

#include "tinyxml2.h"
#include "Conjugation.hpp"

class VocEntry;

#include <string>
#include <vector>
#include <map>


class Word
{
    protected:
        VocEntry* _vocEntry;
        std::string _lang;
        std::string _value;
        std::vector<std::string> _alternatives;
        std::map<std::string,Conjugation*> _conjugations;
        std::string _hint;  
    public:
        Word(VocEntry* vocEntry, std::string lang, std::string value);
        
        static Word* loadFromXML(VocEntry* vocEntry, tinyxml2::XMLElement* element);
        
        inline void setLang(std::string lang)
        {
            _lang=lang;
        }
        
        inline std::string getLang() const
        {
            return _lang;
        }
        
        inline void setValue(std::string value)
        {
            _value=value;
        }
        
        inline std::string getValue() const
        {
            return _value;
        }
        
        inline void setHint(std::string hint)
        {
            _hint=hint;
        }
        
        inline std::string getHint() const
        {
            return _hint;
        }
        
        inline void addConjugation(Conjugation* conjugation)
        {
            _conjugations[conjugation->getTemp()]=conjugation;
        }
        
        inline Conjugation* getConjugation(std::string temp)
        {
            return _conjugations[temp];
        }
        
        void setAlternatives(std::vector<std::string> alt)
        {
            _alternatives=alt;
        }
        
        ~Word();
};

#endif

