
#include "p_processor.h"

void p_processor::process (std::wistream &in, std::wostream &out) const
{
    std::wstring line;
    for (;std::getline(in,line);)
    {
        out << "<p>" << line << "</p>\n";
    }   
}
