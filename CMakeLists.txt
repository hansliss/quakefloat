cmake_minimum_required(VERSION 3.16)

project(quakefloat LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(quakefloat_lib STATIC
    quakefloat.c
)
target_include_directories(quakefloat_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(quakefloat
    main.c
)
target_link_libraries(quakefloat
    PRIVATE quakefloat_lib
)

add_executable(quakefloat_tests
    tests/quakefloat_tests.c
)
target_link_libraries(quakefloat_tests
    PRIVATE quakefloat_lib
)

if(UNIX AND NOT APPLE)
    target_link_libraries(quakefloat PRIVATE m)
    target_link_libraries(quakefloat_tests PRIVATE m)
endif()

install(TARGETS quakefloat)

enable_testing()
add_test(NAME quakefloat_precision COMMAND quakefloat_tests)
