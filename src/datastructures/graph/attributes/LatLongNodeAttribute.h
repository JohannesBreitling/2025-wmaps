#include <tuple>


namespace wmaps::graph::attributes {

class LatLongNodeAttribute : public AbstractAttribute<std::tuple<float, float>> {
    public:
        std::string getName() override {
            return NAME;
        }
    
    protected:
        Type defaultValue() override {
            return {INVALID_COORD, INVALID_COORD};
        }

        static constexpr const char* NAME = "lat_long";
};

}