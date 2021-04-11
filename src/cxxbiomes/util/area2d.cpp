#include "cxxbiomes/util/area2d.hpp"

namespace cxxbiomes::util {

    Area2D::Area2D() = default;

    Area2D::Area2D(Vec2 v1, Vec2 v2) :
        m_min(Vec2::Min(v1, v2)),
        m_max(Vec2::Max(v1, v2))
    {}

    Area2D::Area2D(int x1, int z1, int x2, int z2) :
        m_min(Vec2::Min(Vec2(x1, z1), Vec2(x2, z2))),
        m_max(Vec2::Max(Vec2(x1, z1), Vec2(x2, z2)))
    {}
}
