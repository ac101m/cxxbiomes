#include "catch.hpp"

#include "cxxbiomes/util/area.hpp"

#include <random>

using namespace cxxbiomes::util;

SCENARIO ("Test area2d") {

    WHEN ("An area is default constructed") {
        Area area;

        THEN ("The min and max vectors are zero") {
            REQUIRE (area.min.x == 0);
            REQUIRE (area.min.z == 0);
            REQUIRE (area.max.x == 0);
            REQUIRE (area.max.z == 0);
        }

        THEN ("Width() and Height() return zero") {
            REQUIRE (area.Width() == 0);
            REQUIRE (area.Height() == 0);
        }

        THEN ("Size() returns zero") {
            REQUIRE (area.Size() == 0);
        }
    }

    WHEN ("An area is constructed from plain integers and from vectors") {
        THEN ("They constructed areas are identical") {
            std::random_device r;
            std::default_random_engine random(r());
            std::uniform_int_distribution<int> distribution(-32768, 32768);

            int test_count = 64;

            for (unsigned i = 0; i < test_count; i++) {
                int x1 = distribution(random);
                int z1 = distribution(random);
                int x2 = distribution(random);
                int z2 = distribution(random);

                Vec2 v1 = Vec2(x1, z1);
                Vec2 v2 = Vec2(x2, z2);

                Area int_area(x1, z1, x2, z2);
                Area vec_area(v1, v2);

                REQUIRE (int_area == vec_area);
            }
        }
    }

    GIVEN ("Two vectors") {
        Vec2 v1(-21, -54);
        Vec2 v2(67, 91);

        int expected_width = v2.x - v1.x;
        int expected_height = v2.z - v1.z;

        int expected_size = expected_width * expected_height;

        WHEN ("An area is initialized from the vectors") {
            Area area(v1, v2);

            THEN ("Area min and max coordinates are correctly initialized") {
                REQUIRE (area.min == v1);
                REQUIRE (area.max == v2);
            }

            THEN ("Width() and height() return the correct values") {
                REQUIRE (area.Width() == expected_width);
                REQUIRE (area.Height() == expected_height);
            }

            THEN ("Size() returns the correct value") {
                REQUIRE (area.Size() == expected_size);
            }
        }

        WHEN ("An area is initialized from the vectors in reverse order") {
            Area area(v2, v1);

            THEN ("Area min and max coordinates are correctly initialized") {
                REQUIRE (area.min == v1);
                REQUIRE (area.max == v2);
            }

            THEN ("Width() and height() return the correct values") {
                REQUIRE (area.Width() == expected_width);
                REQUIRE (area.Height() == expected_height);
            }

            THEN ("Size() returns the correct value") {
                REQUIRE (area.Size() == expected_size);
            }
        }
    }
}
