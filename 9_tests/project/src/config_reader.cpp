#include "config_reader.h"
#include <fstream>
#include <stdexcept>

int read_port_from_file(const std::string& path) {

    std::ifstream input(path);

    if(!input)
        throw std::runtime_error("cannot open file");

    std::string key;
    int value;

    input >> key >> value;

    if(key != "port")
        throw std::runtime_error("invalid config");

    return value;
}
