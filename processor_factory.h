
#ifndef HTML_PROCESSOR_FACTORY_H
#define HTML_PROCESSOR_FACTORY_H

#include <memory>
#include "processor.h"


class processor_factory
{
public:
    std::unique_ptr<processor> create (char * string) const;
};

#endif //HTML_PROCESSOR_FACTORY_H
