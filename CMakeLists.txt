cmake_minimum_required(VERSION 3.23)
project(imagenes)

set(CMAKE_CXX_STANDARD 20)

add_executable(imagenes main.cpp fecha.cpp imagen.cpp imagen.h contenedor_Imagenes.cpp contenedor_Imagenes.h)
