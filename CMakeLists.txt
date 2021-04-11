cmake_minimum_required(VERSION 3.16)
project(cxxbiomes)

set(CMAKE_CXX_STANDARD 17)

include_directories(src include)

set(LIB_SRCS
        src/cxxbiomes/util/buffer2d.hpp
        src/cxxbiomes/util/vec2.hpp src/cxxbiomes/util/vec2.cpp src/cxxbiomes/util/area2d.cpp
        src/cxxbiomes/util/area2d.hpp)

set(TEST_SRCS
        src/testmain.cpp
        src/cxxbiomes/util/buffer2d.hpp src/tests/testbuffer2d.cpp src/cxxbiomes/util/vec2.hpp
        src/tests/testvec2.cpp src/cxxbiomes/util/vec2.cpp src/cxxbiomes/util/area2d.cpp
        src/cxxbiomes/util/area2d.hpp src/tests/testarea2d.cpp)

#add_library(cxxbiomes ${LIB_SRCS})
#set_target_properties(cxxbiomes PROPERTIES PUBLIC_HEADER src/cxxbiomes.hpp)
add_executable(cxxbiomes-test ${LIB_SRCS} ${TEST_SRCS})

include(GNUInstallDirs)

install(
    TARGETS cxxbiomes-test
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
