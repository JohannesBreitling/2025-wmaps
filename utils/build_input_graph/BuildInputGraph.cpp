#include <iostream>

#include "../pugixml/pugixml.hpp"

int main(int numArgs, char** args) {
    std::cout << "Hello, from the input graph building!\n";

    // Get the file path of the input graph osm file
    if (numArgs < 2) {
        std::cerr << "Usage: " << args[0] << " <path to input graph osm file>\n";
        return 1;
    }

    std::string inputPath = args[1];

    std::cout << "Das ist der Path : " << inputPath << std::endl;

    return 0;
}
