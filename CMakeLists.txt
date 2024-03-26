cmake_minimum_required(VERSION 3.10)
project(BreakoutGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Inclure le dossier des en-têtes
include_directories(include)

# Trouver SDL2 (ajuster selon votre système)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Spécifier où générer l'exécutable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Ajouter les fichiers source
file(GLOB SOURCES "src/*.cpp")

add_executable(BreakoutGame ${SOURCES})
target_link_libraries(BreakoutGame ${SDL2_LIBRARIES})
