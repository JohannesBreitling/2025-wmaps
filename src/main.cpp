/// ******************************************************************************
///
/// MIT License
/// Copyright (c) 2025 Johannes Breitling
///
/// ******************************************************************************

#include <iostream>

#include "datastructures/graph/Graph.h"
#include "datastructures/graph/attributes/EdgeIdAttribute.h"
#include "datastructures/graph/attributes/OSMNodeIdAttribute.h"
#include "datastructures/graph/attributes/DistanceAttribute.h"
#include "datastructures/graph/attributes/TravelTimeAttribute.h"
#include "datastructures/graph/attributes/LatLongNodeAttribute.h"


int main(int, char**){
    std::cout << "- - - - - - - - - - - - - - - - -\n";
    std::cout << "-           W M A P S           -\n";
    std::cout << "- - - - - - - - - - - - - - - - -\n";
    std::cout << "-                               -\n";
    std::cout << "- - - - - - - - - - - - - - - - -\n";

    // Construct a test Graph
    using namespace wmaps::graph;

    
    attributes::OSMNodeIdAttribute osmNodeIdAttribute;
    attributes::LatLongNodeAttribute latLongNodeAttribute;
    
    using NodeAttributes =  NodeAttributeCollection<attributes::OSMNodeIdAttribute, attributes::LatLongNodeAttribute>;
    // using EdgeAttributes = EdgeAttributeCollection<attributes::EdgeIdAttribute, attributes::TravelTimeAttribute>;


    attributes::EdgeIdAttribute edgeIdAttribute;
    attributes::TravelTimeAttribute travelTimeAttribute;
    EdgeAttributeCollection edgeAttributes = EdgeAttributeCollection(edgeIdAttribute, travelTimeAttribute);
    edgeAttributes.setAttribute<attributes::TravelTimeAttribute>(0, 1);

    /*
    auto graph = Graph<NodeAttributes, EdgeAttributeCollection>();
    graph.reserve(8, 10);

    graph.insertEdge(0, 6);
    graph.insertEdge(1, 5);
    graph.insertEdge(2, 0);
    graph.insertEdge(2, 4);
    graph.insertEdge(3, 5);
    graph.insertEdge(4, 1);
    graph.insertEdge(4, 3);
    graph.insertEdge(5, 7);
    graph.insertEdge(6, 1);
    graph.insertEdge(6, 7);
*/
    // graph.setAttribute<attributes::OSMNodeIdAttribute>(2, 2);

    //graph.setAttribute<attributes::OSMNodeIdAttribute>(2, std::tuple<float, float>(10.15, 12.55));
    //std::cout << graph.getAttribute<attributes::OSMNodeIdAttribute>(2) << std::endl;

    //graph.print();
}
