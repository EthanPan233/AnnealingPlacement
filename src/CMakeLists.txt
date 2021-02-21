cmake_minimum_required(VERSION 2.8)

# Message
message(STATUS "UBC Feb 2021 Ethan Pan")
message(STATUS "CPEN 513 Assignment2")
message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS ${PROJECT_SOURCE_DIR})

# set the project name
project(AnnealingPlacement)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add src files
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_FILES ${SRC_DIR}/Circuit.cpp ${SRC_DIR}/Cell.cpp ${SRC_DIR}/main.cpp)

######################
# Check Dependencies #
######################
# uncommment this line if you are using self-compiled boost lib
# set(Boost_USE_STATIC_LIBS ON)
# find_package(Boost COMPONENTS system filesystem program_options REQUIRED)

# add the executable
add_executable(AnnealingPlacement ${SRC_FILES})

target_include_directories(AnnealingPlacement PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

# Boost
# target_include_directories(AnnealingPlacement PUBLIC ${Boost_INCLUDE_DIR})
# target_link_libraries(AnnealingPlacement PUBLIC ${Boost_LIBRARIES})
