
#ifndef HTML_P_PROCESSOR_H
#define HTML_P_PROCESSOR_H

#include "processor.h"


class p_processor : public processor
{
public:
    virtual void process (std::wistream &in, std::wostream &out) const;
    virtual ~p_processor(){}
};

#endif //HTML_P_PROCESSOR_H
