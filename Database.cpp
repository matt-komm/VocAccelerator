#include "Database.hpp"

Database::Database()
{
}

void Database::loadXML(std::string path)
{
    tinyxml2::XMLDocument document;
    document.LoadFile(path.c_str());
    for (tinyxml2::XMLElement* entry = document.FirstChildElement("vocentry"); entry!=0; entry=entry->NextSiblingElement("vocentry"))
    {
        VocEntry* vocEntry = VocEntry::loadFromXML(entry);
        if (vocEntry!=0)
        {
            _entries.push_back(vocEntry);
        }
    }
}

Database::~Database()
{
}


