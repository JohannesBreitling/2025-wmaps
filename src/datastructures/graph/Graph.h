/// ******************************************************************************
///
/// MIT License
/// Copyright (c) 2025 Johannes Breitling
///
/// ******************************************************************************

#pragma once

#include <vector>
#include <cassert>
#include "attributes/AbstractAttribute.h"
#include "../../tools/Constants.h"

namespace wmaps::graph {

template<typename ...Attributes>
struct NodeAttributeCollection : public Attributes... {
    public: 
};

template<typename ...Attributes>
struct EdgeAttributeCollection : public Attributes... {

    public:
        EdgeAttributeCollection(Attributes... attributes) {
            (handleAttribute(attributes), ...);
        }

        template<typename Attribute>
        void handleAttribute(Attribute attr) {
            std::cout << attr.getName() << std::endl;
            attr.reserve(10);
        }

        template<typename Attribute>
        void setAttribute(const int idx, typename Attribute::Type val) {
            // Attribute::values[idx] = val;
            Attribute::reserve(20);
            std::cout << "SET: " << Attribute::getName() << std::endl;
            std::cout << "SIZE: " << Attribute::values.size() << std::endl;
            std::cout << Attribute::values[0] << std::endl;
        }

        void reserve(const int numEdges) {
            (Attributes::reserve(numEdges), ...);
        }

        template<typename Attribute>
        void reserve(const int numEdges) {
            Attribute::reserve(numEdges);
        }

        /*
        template<typename Attribute>
        void getAttribute(std::string name, typename Attribute::Type val) {
            Attribute::values[name] = val;
        }*/
    
};


template<typename NodeAttributesT, typename EdgeAttributesT>
class Graph : public NodeAttributesT, public EdgeAttributesT {

    public:

        
        Graph() {

        }

        // Reserve memory for the graph
        void reserve(int numNodes, int numEdges) {
            this->numNodes = numNodes;
            this->numEdges = numEdges;

            outEdges = std::vector<int>(numNodes + 1, INVALID_INDEX);
            edgeHeads = std::vector<int>(numEdges, INVALID_EDGE);
            edgeTails = std::vector<int>(numEdges, INVALID_EDGE);

            outEdges[0] = 0;
            currNode = 0;
            insertedEdges = 0;

            // TODO Reserve space for the attributes
            // NodeAttributeCollection::reserve(numNodes);
            
            EdgeAttributesT::reserve(numEdges);
        }

        // Methods to fill the graph with edges
        // Returns the idx of the edge in the graph
        // We restrict the construction of the graph such that the edges are added in order of the tail node
        void insertEdge(int from, int to) {
            if (numEdges == insertedEdges)
                throw std::invalid_argument("Graph building is finished, no more edges can be added");
            
            assert(from < numNodes);
            assert(from >= 0);
            assert(to < numNodes);
            assert(to >= 0);
            assert(from >= currNode);

            if (from == currNode) {
                // We just add another edge for the current node
                edgeTails[insertedEdges] = from;
                edgeHeads[insertedEdges] = to;
                ++insertedEdges;
            } else {
                // We add the first edge to a node
                // Along the way we might have skipped some nodes that have no out edges
                while (currNode < from) {
                    ++currNode;
                    outEdges[currNode] = insertedEdges;
                }

                edgeTails[insertedEdges] = from;
                edgeHeads[insertedEdges] = to;
           
                ++currNode;
                ++insertedEdges;
                outEdges[currNode] = insertedEdges;
            }
            
            if (insertedEdges == numEdges) {
                while (currNode <= numNodes) {
                    ++currNode;
                    outEdges[currNode] = (insertedEdges - 1);
                }
            }
        }

        // Method to retrieve the (out) degree of a node
        int degree(int node) {
            assert(node < numNodes);
            assert(node >= 0);
            return outEdges[node + 1] - outEdges[node];;
        }

        // Return the (position of the) first edge of the given node
        int firstEdge(int node) {
            if (degree(node) == 0)
                return INVALID_INDEX;
            
            return outEdges[node];
        }

        // Return the (position of the) last edge of the given node
        int lastEdge(int node) {
            if (degree(node) == 0)
                return INVALID_INDEX;
            
            return outEdges[node + 1] - 1;
        }

        /*
        template<typename AttributeT>
        void setAttribute(int node, typename AttributeT::Type val) {
            AttributeT::values[node] = val;
        }

        template<typename AttributeT>
        const typename AttributeT::Type getAttribute(int node) {
            return AttributeT::values[node];
        }*/

        void print() {
            // Print the out edge array
            std::cout << "OutEdges [";
            std::string delim = "";
            for (int idx : outEdges) {
                std::cout << delim << idx;
                delim = ", ";
            }
            std::cout << "]\n";

            // Print a list of all the edges
            std::cout << "Edges [";
            delim = "";
            for (int i = 0; i < numEdges; i++) {
                std::cout << delim << "(" << edgeTails[i] << ", " << edgeHeads[i] << ")";
                delim = ", ";
            }
            std::cout << "]\n";
        }

    private:
        NodeAttributesT nodeAttributes;
        EdgeAttributesT edgeAttributes;

        // The size of the graph
        int numNodes;
        int numEdges;

        // Run variables to build up the array representation of the graph
        int currNode = 0;
        int insertedEdges = 0;
        
        // The outEdges vector stores the index of the first edge of each node in edgeHeads and edgeTails
        std::vector<int> outEdges;
        // The edgeHeads vector stores the head of each edge with a given id
        std::vector<int> edgeHeads;
        // The edgeTails vector stores the tail of each edge with a given id
        std::vector<int> edgeTails;
};

}