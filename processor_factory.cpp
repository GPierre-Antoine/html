#include <cstring>
#include <memory>
#include <iostream>
#include "processor_factory.h"
#include "p_processor.h"



std::unique_ptr<processor> processor_factory::create (char * string) const
{
   if (!strcmp(string,"p"))
   {
        return std::make_unique<p_processor>(p_processor());
   }
   else
   {
        std::string error ("Unknown processor : '");
        error += string;
        error += '\'';
        throw std::runtime_error(error);
   }
}
