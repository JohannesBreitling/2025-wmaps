#include <tuple>

namespace wmaps::graph::attributes {

// Denotes the travel time along an edge in 10th seconds
class TravelTimeAttribute : public AbstractAttribute<int> {
    public:
        std::string getName() override {
            return NAME;
        }
    
    protected:
        Type defaultValue() override {
            return INVALID_TIME;
        }

        std::string to_string(Type val) override {
            return std::to_string(val);
        }

        static constexpr const char* NAME = "travel_time";
};

}
