#include <iostream>

#include "../pugixml/pugixml.hpp"

int main(int numArgs, char** args) {
    std::cout << "- - - - - - - - - - - - - - - - -\n";
    std::cout << "-           W M A P S           -\n";
    std::cout << "- - - - - - - - - - - - - - - - -\n";
    std::cout << "-       BUILD INPUT GRAPH       -\n";
    std::cout << "- - - - - - - - - - - - - - - - -\n";

    // Get the file path of the input graph osm file
    if (numArgs < 2) {
        std::cerr << "Usage: " << args[0] << " <path to input graph osm file>\n";
        return 1;
    }

    const char* inputPath = args[1];
    
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(inputPath);

    if (!result) {
        std::cerr << "Error when parsing the input file: " << result.description() << "\n";
        std::cerr << "Provided file path: " << inputPath << "\n";
        return 1;
    }

    pugi::xml_node root = doc.child("osm");

    for (pugi::xml_node node : root.children("node")) {
        int id = node.attribute("id").as_int();
        std::cout << "Parse node with id : " << id << "\n";
    }
    


    

    std::cout << "Successfully parsed the input file!\n";

    return 0;
}
