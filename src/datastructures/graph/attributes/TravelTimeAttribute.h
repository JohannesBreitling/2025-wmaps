#include <tuple>

namespace wmaps::graph::attributes {

// Denotes the travel time along an edge in 10th seconds
class TravelTimeAttribute : AbstractAttribute<int> {
    protected:
        static constexpr const char* NAME = "travel_time";
};

}
