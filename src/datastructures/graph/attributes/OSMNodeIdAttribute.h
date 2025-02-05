#include <tuple>

namespace wmaps::graph::attributes {

class OSMNodeIdAttribute : public AbstractAttribute<int> {
    public:
        std::string getName() override {
            return NAME;
        }
    
    protected:
        Type defaultValue() override {
            return INVALID_ID;
        }

        std::string to_string(Type val) override {
            return std::to_string(val);
        }

        static constexpr const char* NAME = "vertex_id";
};

}
