
#include "p_processor.h"

void p_processor::process (std::istream &in, std::ostream &out) const
{
    std::string line;
    for (;std::getline(in,line);)
    {
        out << "<p>" << line << "</p>\n";
    }   
}
