#include <tuple>


namespace wmaps::graph::attributes {
// Denotes the length of an edge in meters
class DistanceAttribute : public AbstractAttribute<float> {
    public:
        std::string getName() override {
            return NAME;
        }
    
    protected:
        Type defaultValue() override {
            return INVALID_DISTANCE;
        }

        static constexpr const char* NAME = "distance";
};
}