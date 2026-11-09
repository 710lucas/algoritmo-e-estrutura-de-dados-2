cmake_minimum_required(VERSION 4.3)
project(atividade_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(atividade_3
        src/Paciente.cpp
        src/Paciente.h
        src/TipoAtendimento.h
        src/main.cpp
        src/ArvoreBST.cpp
        src/ArvoreBST.h)
