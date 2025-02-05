#include <tuple>

namespace wmaps::graph::attributes {

class EdgeIdAttribute : public AbstractAttribute<int> {
    public:
        std::string getName() override {
            return NAME;
        }
    
    protected:
        Type defaultValue() override {
            return INVALID_ID;
        }

        static constexpr const char* NAME = "edge_id";
};

}