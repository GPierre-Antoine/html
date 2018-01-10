
#include "count_processor.h"

void count_processor::process (std::wistream &in, std::wostream &out) const
{
    std::wstring line;
    std::size_t counter=0;
    for (;std::getline(in,line);)
    {
        out << ++counter  << " : " << line << "\n";
    }   
}
