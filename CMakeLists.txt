cmake_minimum_required(VERSION 3.6)

project(ast LANGUAGES CXX)

find_package(SDL2 CONFIG REQUIRED)

INCLUDE(FindPkgConfig)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

include_directories(${SDL2_TTF_INCLUDE_DIRS})
link_directories (${SDL2_TTF_LIBRARY_DIRS})




set(SRC_FILES
    src/source.cpp
    src/Asteroide.cpp
    src/Bullet.cpp
    src/Game.cpp
    src/fonction.cpp
    src/Texture.cpp
    src/vaisseau.cpp )


####
file(
  GLOB
  HEADERS_FILES
  include/*
)

add_executable(ast "")
target_sources(ast PUBLIC ${SRC_FILES})
target_compile_options(ast PUBLIC -Wall -Wextra)
target_include_directories(ast PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(ast SDL2::SDL2main SDL2::SDL2 ${SDL2_TTF_LIBRARIES})
