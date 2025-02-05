
#include <vector>

#pragma once

namespace wmaps::datastructurs {

    // Efficient implementation of am adressable k-ary heap
    template <typename T, int k>
    class Heap {
        public:
            int insert(T val) {
                // Insert the value at the end of the array and then heapify it up
                // Returns the index of the inserted element in the heap
            }

            T extractMin() {
                // Extract the minimum value, update the heap accordingly
                int index = heap[0];
            }

            int decreaseKey(int index, int newVal) {
                // Decrease the value of the element at index to newVal
            }
        
        private:
            std::vector<int> heap;
            std::vector<T> elements;
            std::unordered_map<int, int> indexMap;
    
    };


}