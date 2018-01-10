
#ifndef HTML_REVERSE_PROCESSOR_H
#define HTML_REVERSE_PROCESSOR_H

#include "processor.h"


class reverse_processor : public processor
{
public:
    virtual void process (std::wistream &in, std::wostream &out) const;
};

#endif //HTML_REVERSE_PROCESSOR_H
