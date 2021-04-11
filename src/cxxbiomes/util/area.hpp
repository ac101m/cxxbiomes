#ifndef CXXBIOMES_AREA_HPP
#define CXXBIOMES_AREA_HPP

#include "cxxbiomes/util/vec2.hpp"

namespace cxxbiomes::util {

    struct Area {
        Vec2 min;
        Vec2 max;

        Area() = default;

        Area(Vec2 v1, Vec2 v2) :
                min(Vec2::Min(v1, v2)),
                max(Vec2::Max(v1, v2))
        {}

        Area(int x1, int z1, int x2, int z2) :
                min(Vec2::Min(Vec2(x1, z1), Vec2(x2, z2))),
                max(Vec2::Max(Vec2(x1, z1), Vec2(x2, z2)))
        {}

        [[nodiscard]] int Width() const { return max.x - min.x; }
        [[nodiscard]] int Height() const { return max.z - min.z; }
        [[nodiscard]] long Size() const { return (long)this->Width() * (long)this->Height(); }

        bool operator==(Area const other) const {
            return this->min == other.min && this->max == other.max;
        }
    };

}

#endif //CXXBIOMES_AREA_HPP
