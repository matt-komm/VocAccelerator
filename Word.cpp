#include "Word.hpp"

#include <iostream>

Word::Word(VocEntry* vocEntry, std::string lang, std::string value):
    _vocEntry(vocEntry),
    _lang(lang), 
    _value(value), 
    _hint("")
{
}

Word::~Word()
{
}

Word* Word::loadFromXML(VocEntry* vocEntry, const tinyxml2::XMLElement* element)
{
    std::string lang="";
    for (const tinyxml2::XMLAttribute* attr = element->FirstAttribute(); attr!=0; attr = attr->Next())
    {
        if (strcmp(attr->Name(),"lang")==0)
        {
            lang=std::string(attr->Value());
        }
    }
    if (lang=="")
    {   
        return 0;
    }
    std::string value="";
    std::string hint="";
    std::vector<std::string> alt;
    
    for (const tinyxml2::XMLElement* child = element->FirstChildElement(); child!=0; child=child->NextSiblingElement())
    {
        if (strcmp(child->Name(),"value")==0)
        {
            value = child->GetText();
            for (const tinyxml2::XMLElement* altElement = child->FirstChildElement("alt"); altElement!=0; altElement=altElement->NextSiblingElement("alt"))
            {
                alt.push_back(altElement->GetText());
            }
        }
        else if (strcmp(child->Name(),"hint")==0)
        {
            hint=std::string(child->Value());
        }
        
    }
    Word* word = new Word(vocEntry,lang,value);
    word->setHint(hint);
    word->setAlternatives(alt);
    
    const tinyxml2::XMLElement* child = element->FirstChildElement("conjugation");
    if (child!=0)
    {
        for (const tinyxml2::XMLElement* conjugationElements = child->FirstChildElement("temp"); conjugationElements!=0; conjugationElements=conjugationElements->NextSiblingElement("temp"))
        {
            Conjugation* conjugation = Conjugation::loadFromXML(word,conjugationElements);
            if (conjugation!=0)
            {    
                Conjugation::initPersonsByLang(conjugation,lang);
                word->addConjugation(conjugation);
            }
            
        }
    }
    return word;
}



