#include <cstring>
#include <memory>
#include <iostream>
#include "processor_factory.h"

std::shared_ptr<processor> processor_factory::create (const char * string) const
{
    
    std::string error;
    error+= "Unknown processor : '";
    error += string;
    error += "', available entries : ";

    bool first = true;

    for (auto const &key:keeper)
    {
        
        if (!strcmp(key.first,string))
        {
            return key.second;
        }
        if (first)
        {
            first = false;
        }
        else
        {
            error += ", ";
        }
        error+= key.first;
    }

    throw std::runtime_error(error);

}

processor_factory::processor_factory()
{
    keeper = std::map<const char*,std::shared_ptr<processor>>();
}

void processor_factory::load (const char * key, std::shared_ptr<processor> && value)
{
    keeper.insert(std::make_pair(key,std::move(value)));
    if (!keeper.count(key))
    {
        std::string error;
        error+="Insertion failed : ";
        error+= key;
        throw std::runtime_error(error);
    }
}
