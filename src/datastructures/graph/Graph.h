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
struct NodeAttributeCollection {};

template<typename ...Attributes>
struct EdgeAttributeCollection {};

template <typename EdgeAttributeCollectionT, typename NodeAttribtueCollectionT>
class Graph {

    public:
        
        Graph() {
            
        }

        // Reserve memory for the graph
        void reserve(int numNodes, int numEdges) {
            this->numNodes = numNodes;
            this->numEdges = numEdges;
            outEdges.reserve(numNodes + 1);
            edgeHeads.reserve(numEdges);
            edgeTails.reserve(numEdges);

            outEdges = std::vector<int>(numNodes + 1, INVALID_INDEX);
            edgeHeads = std::vector<int>(numEdges, INVALID_EDGE);
            edgeTails = std::vector<int>(numEdges, INVALID_EDGE);

            outEdges[0] = 0;
            currNode = 0;
            insertedEdges = 0;
        }

        // Methods to fill the graph with edges
        // Returns the idx of the edge in the graph
        // We restrict the construction of the graph such that the edges are added in order of the tail node
        int insertEdge(int from, int to) {
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
        NodeAttribtueCollectionT nodeAttributes;
        EdgeAttributeCollectionT edgeAttributes;

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