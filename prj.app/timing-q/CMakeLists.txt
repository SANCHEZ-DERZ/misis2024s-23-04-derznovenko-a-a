cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)

project(prj)
find_package(Matplot++ CONFIG REQUIRED)
#find_package(tomlplusplus REQUIRED)

add_executable(timing-q timing-q.cpp)
target_link_libraries(timing-q Matplot++::cimg  Matplot++::matplot)
target_link_libraries(timing-q stackarrt)
target_link_libraries(timing-q stacklstt)






