#ifndef CXXBIOMES_VEC2_HPP
#define CXXBIOMES_VEC2_HPP

namespace cxxbiomes::util {

    struct Vec2 {
        int x = 0;
        int z = 0;

        Vec2();
        Vec2(int x, int z);

        static Vec2 Min(Vec2 v1, Vec2 v2);
        static Vec2 Max(Vec2 v1, Vec2 v2);
    };

}

#endif //CXXBIOMES_VEC2_HPP
