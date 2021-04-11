#include "catch.hpp"

#include "cxxbiomes/util/vec2.hpp"

using namespace cxxbiomes::util;

SCENARIO ("Test vec2") {
    GIVEN ("A default constructed Vec2") {
        Vec2 vec;

        THEN ("x and z coordinates are initialized to zero") {
            REQUIRE (vec.x == 0);
            REQUIRE (vec.z == 0);
        }
    }

    GIVEN ("An initialized instance of Vec2") {
        int x = 32, z = -98;

        Vec2 vec(x, z);

        THEN ("x and z coordinates") {
            REQUIRE (vec.x == x);
            REQUIRE (vec.z == z);
        }
    }

    GIVEN ("Two initialized Vec2 objects") {
        Vec2 v1(43, 32);
        Vec2 v2(-32, -17);

        WHEN ("The minimum of the two vectors is computed") {
            Vec2 min = Vec2::Min(v1, v2);

            THEN ("Vector components are the minimum of the two input vectors") {
                REQUIRE (min.x == std::min(v1.x, v2.x));
                REQUIRE (min.z == std::min(v1.z, v2.z));
            }
        }

        WHEN ("The maximum of the two vectors is computed") {
            Vec2 min = Vec2::Max(v1, v2);

            THEN ("Vector components are the maximum of the two input vectors") {
                REQUIRE (min.x == std::max(v1.x, v2.x));
                REQUIRE (min.z == std::max(v1.z, v2.z));
            }
        }
    }
}
