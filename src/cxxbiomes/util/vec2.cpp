#include <algorithm>

#include "cxxbiomes/util/vec2.hpp"

namespace cxxbiomes::util {

    Vec2::Vec2() = default;

    Vec2::Vec2(int x, int z) :
        x(x), z(z)
    {}

    Vec2 Vec2::Min(Vec2 const v1, Vec2 const v2) {
        return Vec2(std::min(v1.x, v2.x), std::min(v1.z, v2.z));
    }

    Vec2 Vec2::Max(Vec2 const v1, Vec2 const v2) {
        return Vec2(std::max(v1.x, v2.x), std::max(v1.z, v2.z));
    }
}
