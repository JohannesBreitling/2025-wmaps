#include <tuple>


namespace wmaps::graph::attributes {

class LatLongNodeAttribute : AbstractAttribute<std::tuple<float, float>> {
    protected:
        static constexpr const char* NAME = "lat_long";
};

}