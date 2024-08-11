# Minimalna wersja CMake, której używamy
cmake_minimum_required(VERSION 3.10)

# Nazwa projektu
project(data_structures_and_algorithm VERSION 0.1.0 LANGUAGES C CXX)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dodanie katalogu z plikami nagłówkowymi
# TODO : dodać algorithms
include_directories(data_structures/inc)

# Wskazanie plików źródłowych
set(SOURCES
    main.cc
    data_structures/src/linked_list.cc
)

# Tworzenie pliku wykonywalnego
add_executable(main ${SOURCES})

include(CTest)
enable_testing()