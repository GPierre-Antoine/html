#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <memory>

#include "processor_factory.h"

namespace fs = std::experimental::filesystem::v1;

int main (int argc, char ** argv)
{
    try
    {

        std::vector<std::shared_ptr<std::ios>> file_input;
        std::stringbuf buffer1; 
        std::stringbuf buffer2;
        std::vector<std::unique_ptr<processor>> arguments;
        file_input.reserve(argc);
        arguments.reserve(argc);
        processor_factory factory;

        for (int argc_counter=1; argc_counter<argc; ++argc_counter)
        {
            if (fs::is_regular_file(argv[argc_counter]))
            {
                file_input.push_back(std::make_shared<std::ifstream>(argv[argc_counter]));
            }
            else
            {
                arguments.push_back(factory.create(argv[argc_counter]));
            }

        }
        if (!file_input.size())
        {
            file_input.push_back(std::shared_ptr<std::istream>(&std::cin,[](void*){}));
        }

        if (!arguments.size())
        {
            throw std::runtime_error("Missing processor");
        }

        for (auto & stream : file_input)
        {

            if (arguments.size() == 1)
            {
                arguments[0]->process(*stream,&std::cout);
                continue;
            }

            std::stringbuf *buffer_ptr1, *buffer_ptr2;

            buffer_ptr1 = &buffer1;
            buffer_ptr2 = &buffer2;

            arguments[0]->process(*stream,&buffer1);


            for (std::size_t i=1; i < arguments.size()-1;++i)
            {
                arguments[i]->process(*buffer_ptr1,*buffer_ptr2);
                std::swap(buffer_ptr1,buffer_ptr2);
            }

            arguments[arguments.size()-1]->process(*buffer_ptr1,&std::cout);

        }

       return EXIT_SUCCESS;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return EXIT_FAILURE;
}
