#include <iostream>
#include <string>
#include <boost/program_options.hpp>
#include "LanScanner.hpp"

using namespace boost::program_options;


int main(int argc, char *argv[])
{
    try
    {
        options_description program_options("Options");
        program_options.add_options()
        ("help,h", "Help screen")
        ("ip", value<std::string>(), "Ip address")
        ("port", value<int>(), "port");
        variables_map vm;
        store(parse_command_line(argc, argv, program_options), vm);
        notify(vm);

        if (vm.count("help"))
        {
            std::cout << program_options << std::endl;
        }
        else if(vm.count("ip") && vm.count("port"))
        {
            LanScanner scanner(true);
            scanner.lanScan(vm["ip"].as<std::string>());
        }   

    }
    catch (const error &ex)
    {
        std::cerr << ex.what() << std::endl;
    }


    return 0;
}
