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
            using Type = T;

            void reserve(int size) {
                std::cout << "Reserve in attribute: " << getName() << std::endl; // TODO
                values = std::vector<T>(size, defaultValue());
            }

            std::vector<T> values;
        
        protected:
            virtual T defaultValue() = 0;
            virtual std::string getName() = 0;

            void print() {
                std::cout << "Attribute: " << getName() << std::endl;
                for (T val : values) {
                    std::cout << val << ", ";
                }
                std::cout << std::endl;    
            }
    };

}