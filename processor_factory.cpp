#include <cstring>
#include <memory>
#include <iostream>
#include "processor_factory.h"
#include "p_processor.h"
#include "count_processor.h"
#include "reverse_processor.h"

std::unique_ptr<processor> processor_factory::create (char * string) const
{
   if (!strcmp(string,"p"))
   {
        return std::make_unique<p_processor>(p_processor());
   }
   else if(!strcmp(string,"line_count"))
   {
        return std::make_unique<count_processor>(count_processor());
   }
   else if (!strcmp(string,"reverse"))
   {
        return std::make_unique<reverse_processor>(reverse_processor());
   }
   else
   {
        std::string error;
        error+= "Unknown processor : '";
        error += string;
        error += '\'';
        throw std::runtime_error(error);
   }
}
