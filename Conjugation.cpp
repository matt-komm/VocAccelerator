#include "Conjugation.hpp"

const std::string Conjugation::SINGULAR_1PERSON="s1";
const std::string Conjugation::SINGULAR_2PERSON="s2";
const std::string Conjugation::SINGULAR_3PERSON="s3";

const std::string Conjugation::PLURAL_1PERSON="p1";
const std::string Conjugation::PLURAL_2PERSON="p2";
const std::string Conjugation::PLURAL_3PERSON="p3";

Conjugation::Conjugation(Word* baseWord, std::string temp):
    _baseWord(baseWord),
    _temp(temp)
{
}

Conjugation::~Conjugation()
{
}
 
Conjugation* Conjugation::loadFromXML(Word* word, tinyxml2::XMLElement* element)
{
    std::string temp = "";
    for (tinyxml2::XMLAttribute* attr = element->FirstAttribute(); attr!=0; attr = attr->Next())
    {
        if (strcmp(attr->Name(),"name")==0)
        {
            temp=std::string(attr->Value());
        }
    }
    if (temp=="")
    {
        return 0;
    }
    Conjugation* conjugation = new Conjugation(word, temp);
    for (tinyxml2::XMLElement* child = element->FirstChildElement(); child!=0; child=child->NextSiblingElement())
    {
        conjugation->addConjugationForm(child->Name(),child->GetText());
    }
    return conjugation;
}


void Conjugation::initPersonsByLang(Conjugation* conjugation, std::string lang)
{
    if (lang=="french")
    {
        conjugation->addPerson("s1","je");
        conjugation->addPerson("s2","tu");
        conjugation->addPerson("s3","il");
        conjugation->addPerson("p1","nous");
        conjugation->addPerson("p2","vous");
        conjugation->addPerson("p3","ils");
    }
}

void Conjugation::addConjugationForm(std::string person, std::string form)
{
    //e.g. s1: j'ai, s2: tu as, ...
    _conjugationForms[person]=form;
}

void Conjugation::addPerson(std::string person, std::string form)
{
    //e.g. s1: "je", s2: "tu, ..
    _persons[person]=form;
}
