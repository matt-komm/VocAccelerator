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
        
        inline VocEntry* get(unsigned int index)
        {
            return _entries[index];
        }
        
        inline unsigned int size()
        {
            return _entries.size();
        }
        
        ~Database();
};

#endif

