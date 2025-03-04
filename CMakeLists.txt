cmake_minimum_required(VERSION 3.27)
project(OOP_Lab_09)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP_Lab_09 main.cpp
        Produs.cpp
        Produs.h
        Repo.h
        Repo.cpp
        tests.cpp
        tests.h
        Service.cpp
        Service.h
        Ui.h
        Ui.cpp
        RepoBani.cpp
        RepoBani.h
        Bani.cpp
        Bani.h
        RepoFile.cpp
        RepoFile.h
        ExcepValidareDate.h)
