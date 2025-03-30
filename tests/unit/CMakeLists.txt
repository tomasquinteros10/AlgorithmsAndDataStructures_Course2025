cmake_minimum_required(VERSION 3.17)
project(sis_refugio_33_tests)

enable_testing()

# Flags adicionales para debug, cobertura y sanitizadores
set(CMAKE_CXX_FLAGS_DEBUG "-g --coverage -fsanitize=address,leak,undefined")

# Ruta al código fuente principal
set(TEST_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/../../src)

file(GLOB UNIT_SRC_FILES
    ${UNIT_SRC_DIR}/*_test.cpp
    )

# Ejecutable de prueba unitaria
add_executable(sis_refugio_33_tests
    ${UNIT_SRC_FILES}
)

# Incluir headers del proyecto
target_include_directories(sis_refugio_33_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/dataStructures
    ${CMAKE_SOURCE_DIR}/include/characters
)

# Linkeo a GTest y sanitizadores
target_link_libraries(sis_refugio_33_tests
    PRIVATE
    debug gtestd
    debug gmockd
    debug gtest_maind
    debug gmock_maind
    optimized gtest
    optimized gmock
    optimized gtest_main
    optimized gmock_main
)

# Descubrir automáticamente los tests
include(GoogleTest)
gtest_discover_tests(sis_refugio_33_tests)
