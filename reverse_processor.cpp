#include <stack>
#include "reverse_processor.h"

void reverse_processor::process (std::wistream &in, std::wostream &out) const
{
    std::wstring line;
    std::stack<std::wstring> sstack;
    
    for (;std::getline(in,line);)
    {
        sstack.push(line);
    }
    for (;!sstack.empty();sstack.pop())
    {
        out << sstack.top() << "\n";
    }
}
