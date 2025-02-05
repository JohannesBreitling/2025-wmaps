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

        std::string to_string(Type val) override {
            std::string result = "(";

            result += std::to_string(std::get<0>(val));
            result += ", ";
            result += std::to_string(std::get<0>(val));
            result += ")";

            return result;
        }

        static constexpr const char* NAME = "lat_long";
};

}