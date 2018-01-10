
#ifndef HTML_PROCESSOR_FACTORY_H
#define HTML_PROCESSOR_FACTORY_H

#include <map>
#include <memory>
#include "processor.h"


class processor_factory
{
    std::map<const char *,std::shared_ptr<processor>> keeper;
public:
    void load(const char * key, std::shared_ptr<processor> && value);
    std::shared_ptr<processor> create (const char * string) const;
    processor_factory();
};

#endif //HTML_PROCESSOR_FACTORY_H
