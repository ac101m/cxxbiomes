#ifndef CXXBIOMES_AREA2D_HPP
#define CXXBIOMES_AREA2D_HPP

#include "cxxbiomes/util/vec2.hpp"

namespace cxxbiomes::util {

    class Area2D {
    private:
        Vec2 const m_min;
        Vec2 const m_max;

    public:
        Area2D();
        Area2D(Vec2 v1, Vec2 v2);
        Area2D(int x1, int z1, int x2, int z2);
    };

}

#endif //CXXBIOMES_AREA2D_HPP
