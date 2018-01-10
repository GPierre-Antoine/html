
#ifndef HTML_COUNT_PROCESSOR_H
#define HTML_COUNT_PROCESSOR_H

#include "processor.h"


class count_processor : public processor
{
public:
    virtual void process (std::wistream &in, std::wostream &out) const;
};

#endif //HTML_COUNT_PROCESSOR_H
