#ifndef __CLASS_H__
#define __CLASS_H__

#include "VocEntry.hpp"

#include "tinyxml2.h"

#include <vector>

class Database
{
    protected:
        std::vector<VocEntry*> _entries;
    public:
        Database();
        
        void loadXML(std::string path);
        
        ~Database();
};

#endif

