#include <tuple>

namespace wmaps::graph::attributes {

class VertexIdAttribute : AbstractAttribute<int> {
    protected:
        static constexpr const char* NAME = "vertex_id";
};

}
