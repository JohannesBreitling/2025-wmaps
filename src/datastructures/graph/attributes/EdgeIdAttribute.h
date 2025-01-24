#include <tuple>

namespace wmaps::graph::attributes {

class EdgeIdAttribute : AbstractAttribute<int> {
    protected:
        static constexpr const char* NAME = "edge_id";
};

}