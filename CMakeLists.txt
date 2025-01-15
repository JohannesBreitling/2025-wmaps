cmake_minimum_required(VERSION 3.15..3.31)
project(wmaps VERSION 0.1.0 LANGUAGES C CXX)

# Add the differet executables
add_executable(wmaps main.cpp)
add_executable(wmaps_build_input_graph utils/build_input_graph/BuildInputGraph.cpp)

# Add the pugixml library
add_library(pugixml SHARED utils/pugixml/pugixml.cpp)
target_link_libraries(wmaps_build_input_graph pugixml)
install(TARGETS pugixml DESTINATION lib)