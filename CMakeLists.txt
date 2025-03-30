cmake_minimum_required(VERSION 3.17)
project(SisRefugio33)

# Establece el estándar de C++ a utilizar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Recopila todos los archivos fuente dentro del directorio src
file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Define el ejecutable y sus archivos fuente
add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})

# Establece el directorio de inclusión para los archivos de cabecera usando target_include_directories
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include")
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include/dataStructures")
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include/characters")

# Copia todos los archivos de la carpeta assets al directorio de ejecución
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/assets"
)

# Mensaje para indicar el inicio de la compilación
message(STATUS "Compilando el proyecto ${CMAKE_PROJECT_NAME}")
