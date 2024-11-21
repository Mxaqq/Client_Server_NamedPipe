cmake_minimum_required(VERSION 3.10)
project(NamedPipeProject)

# Установить стандарт C++
set(CMAKE_CXX_STANDARD 17)

# Добавить подпроекты
add_subdirectory(NamedPipeLibrary)
add_subdirectory(Launch/client)
add_subdirectory(Launch/server)