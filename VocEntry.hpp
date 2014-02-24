#ifndef __VOCENTRY_H__
#define __VOCENTRY_H__

#include "Word.hpp"

#include "tinyxml2.h"

#include <string>
#include <vector>
#include <map>

class VocEntry
{
    protected:
        std::string _type;
        std::string _uuid;
        
        std::string _renderer;
        std::map<std::string,Word*> _words;
    public:
        VocEntry(std::string type, std::string uuid);
        
        static VocEntry* loadFromXML(const tinyxml2::XMLElement* element);
        
        void addWord(Word* word);
        Word* getWord(std::string lang);
        
        ~VocEntry();
};

#endif

