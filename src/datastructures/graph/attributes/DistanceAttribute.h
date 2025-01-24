#include <tuple>


namespace wmaps::graph::attributes {

// Denotes the length of an edge in meters
class DistanceAttribute : AbstractAttribute<float> {
    protected:
        static constexpr const char* NAME = "distance";
};

}

