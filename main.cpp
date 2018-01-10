#include <fstream>
#include <sstream>
#include <experimental/filesystem>
#include <memory>

#include "processor_factory.h"

namespace fs = std::experimental::filesystem::v1;


void use_processors(const std::vector<std::unique_ptr<processor>> & arguments, std::wiostream & first, std::wostream & second)
{
    if (arguments.size() == 1)
    {
        arguments[0]->process(first,second);
        return;
    }

    std::wstringstream buffer1,  buffer2,  *buffer_ptr1, *buffer_ptr2;

    buffer_ptr1 = &buffer1;
    buffer_ptr2 = &buffer2;

    arguments[0]->process(first,buffer1);


    for (std::size_t i=1; i < arguments.size()-1;++i)
    {
        arguments[i]->process(*buffer_ptr1,*buffer_ptr2);
        std::swap(*buffer_ptr1,*buffer_ptr2);
    }

    arguments[arguments.size()-1]->process(*buffer_ptr1,second);

}


int main (int argc, char ** argv)
{
    try
    {

        std::vector<std::wstringstream> strings;
        std::vector<std::unique_ptr<processor>> arguments;
        strings.reserve(argc);
        arguments.reserve(argc);
        processor_factory factory;

        for (int argc_counter=1; argc_counter<argc; ++argc_counter)
        {
            if (fs::is_regular_file(argv[argc_counter]))
            {
                std::ifstream file(argv[argc_counter]);
                if (file)
                {
                    strings.emplace_back(std::wstringstream());
                    strings[strings.size()-1] << file.rdbuf();
                    file.close();
                }
            }
            else
            {
                arguments.push_back(factory.create(argv[argc_counter]));
            }

        }
        if (!strings.size())
        {
            strings.push_back(std::wstringstream());
            strings[strings.size()-1] << std::wcin.rdbuf();
        }

        if (!arguments.size())
        {
            throw std::runtime_error("Missing processor");
        }

        for (auto & stream : strings)
        {
            use_processors(arguments,stream,std::wcout);
        }

       return EXIT_SUCCESS;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return EXIT_FAILURE;
}
