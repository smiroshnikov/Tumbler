cmake_minimum_required(VERSION 3.6)
project(Tumbler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -DSFML_STATIC")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
set(SOURCE_FILES main.cpp)
add_executable(Tumbler ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} -lsfml-window-s -lgdi32 -lsfml-graphics-s -lopengl32 -lfreetype -ljpeg -lsfml-audio-s -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg -lsfml-network-s -lws2_32 -lsfml-system-s -lwinmm -lz)