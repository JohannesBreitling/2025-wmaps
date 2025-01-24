/// ******************************************************************************
///
/// MIT License
/// Copyright (c) 2025 Johannes Breitling
///
/// ******************************************************************************


// The abstract attribute class is a template class that is used to store attributes of nodes or edges in a graph.


namespace wmaps::graph::attributes {

    template <typename T>
    class AbstractAttribute {
    
        public:
        
        protected:
        
            void reserve(int size) {
                values.reserve(size);
            }
            
            std::vector<T> values;

    };

}