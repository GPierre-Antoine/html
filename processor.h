
#ifndef HTML_PROCESSOR_H
#define HTML_PROCESSOR_H

#include <iostream>

class processor
{
public:
    virtual void process (std::wistream &in, std::wostream &out) const =0;
    virtual ~processor(){}
};

#endif //HTML_PROCESSOR_H
