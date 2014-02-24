#include "VocEntry.hpp"

#include <iostream>


VocEntry::VocEntry(std::string type, std::string uuid):
    _type(type), _uuid(uuid), _renderer("default")
{
}

VocEntry::~VocEntry()
{
}

void VocEntry::addWord(Word* entry)
{
    if (_words.find(entry->getLang())==_words.end())
    {
        _words[entry->getLang()]=entry;
    }
}

Word* VocEntry::getWord(std::string lang)
{
    if (_words.find(lang)!=_words.end())
    {
        return _words[lang];
    }
    else
    {
        throw "language not found";
        return 0;
    }
}

VocEntry* VocEntry::loadFromXML(const tinyxml2::XMLElement* element)
{

    std::string type="";
    std::string uuid="";
    for (const tinyxml2::XMLAttribute* attr = element->FirstAttribute(); attr!=0; attr = attr->Next())
    {
        if (strcmp(attr->Name(),"type")==0)
        {
            type=std::string(attr->Value());
        }
        /*
        else if (strcmp(attr->Name(),"uuid")==0)
        {
            uuid=std::string(attr->Value());
        }
        */
    }
    //std::cout<<"vocentry: "<<type<<", "<<uuid<<std::endl;
    
    if (type=="") //|| uuid=="")
    {
        return 0;
    }
    VocEntry* vocEntry = new VocEntry(type,uuid);
    if (element->FirstChildElement("category")!=0)
    {   
        //TODO
    }
    for (const tinyxml2::XMLElement* child = element->FirstChildElement("word"); child!=0; child=child->NextSiblingElement("word"))
    {
        Word* word = Word::loadFromXML(vocEntry,child);
        if (word!=0)
        {
            //std::cout<<"  add word: "<<word->getLang()<<", "<<word->getValue()<<std::endl;
            vocEntry->addWord(word);
        }
    }
    return vocEntry;
}
