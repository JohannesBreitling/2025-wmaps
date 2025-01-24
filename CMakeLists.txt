cmake_minimum_required(VERSION 3.15..3.31)
project(wmaps VERSION 0.1.0 LANGUAGES C CXX)

# Set the C++ standard
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the compile flags to -O3 for optimized code
if(CMAKE_CXX_COMPILER_ID MATCHES GNU|Clang)
  set(CMAKE_CXX_FLAGS_DEVEL -O3)
endif()

# Add the differet executables
add_executable(wmaps src/main.cpp)
add_executable(wmaps_build_input_graph src/utils/build_input_graph/BuildInputGraph.cpp)

# Add the pugixml library
add_library(pugixml SHARED src/utils/pugixml/pugixml.cpp)
target_link_libraries(wmaps_build_input_graph pugixml)
install(TARGETS pugixml DESTINATION lib)

foreach(SRC_DIR ${SOURCE_DIRECTORIES})
  add_subdirectory(${SRC_DIR})
endforeach()