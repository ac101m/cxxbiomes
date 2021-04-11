#ifndef CXXBIOMES_VEC2_HPP
#define CXXBIOMES_VEC2_HPP

namespace cxxbiomes::util {

    struct Vec2 {
        int x = 0;
        int z = 0;

        Vec2() = default;

        Vec2(int x, int z) :
            x(x), z(z)
        {}

        static Vec2 Min(Vec2 const v1, Vec2 const v2) {
            return Vec2(std::min(v1.x, v2.x), std::min(v1.z, v2.z));
        }

        static Vec2 Max(Vec2 const v1, Vec2 const v2) {
            return Vec2(std::max(v1.x, v2.x), std::max(v1.z, v2.z));
        }

        bool operator==(Vec2 const other) const {
            return this->x == other.x && this->z == other.z;
        }
    };

}

#endif //CXXBIOMES_VEC2_HPP
