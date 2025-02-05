

#include "datastructures/graph/Graph.h"

namespace wmaps::algorithms {

template<typename GraphT, typename PriorityQueueT>
class Dijkstra {





    // Method to run the Dijkstra algorithm on the graph starting from vertex s
    void run(int s) {
        queue.init();
        queue.insert(s, 0);
    
        while (!queue.empty()) {
            // TODO
        }
    }


    private: 
        using PriorityQueue = datastructures::Heap<int, 2>;
        
        GraphT graph;
        PriorityQueueT queue;

};




}