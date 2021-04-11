#include "catch.hpp"
#include "cxxbiomes/util/buffer2d.hpp"

using namespace cxxbiomes::util;

SCENARIO ("Test Buffer2D<int>") {

    GIVEN ("A default constructed Buffer2D") {
        unsigned const width = 32;
        unsigned const height = 16;

        Buffer2D<int> buffer(width, height);

        WHEN ("The getters for width and height are called") {
            unsigned get_width = buffer.Width();
            unsigned get_height = buffer.Height();

            THEN ("Their values match the initializated values") {
                REQUIRE (get_width == width);
                REQUIRE (get_height == height);
            }
        }
    }

    GIVEN ("A Buffer2D constructed with a default value") {
        unsigned const width = 16;
        unsigned const height = 32;

        int const default_value = 1337;

        Buffer2D<int> buffer(width, height, default_value);

        WHEN ("The getters for width and height are called") {
            unsigned get_width = buffer.Width();
            unsigned get_height = buffer.Height();

            THEN ("Their values match the initializated values") {
                REQUIRE (get_width == width);
                REQUIRE (get_height == height);
            }
        }

        WHEN ("Values are fetched from the buffer") {
            THEN ("The values match the default") {
                for (int j = 0; j < buffer.Height(); j++) {
                    for (int i = 0; i < buffer.Width(); i++) {
                        REQUIRE (buffer.At(i, j) == default_value);
                    }
                }
            }
        }

        WHEN ("The buffer is filled with values") {
            for (int j = 0; j < buffer.Height(); j++) {
                for (int i = 0; i < buffer.Width(); i++) {
                    buffer.Put(i, j, i * j);
                }
            }

            THEN ("Values read from the buffer match the stored values") {
                for (int j = 0; j < buffer.Height(); j++) {
                    for (int i = 0; i < buffer.Width(); i++) {
                        REQUIRE (buffer.At(i, j) == i * j);
                    }
                }
            }
        }
    }
}
