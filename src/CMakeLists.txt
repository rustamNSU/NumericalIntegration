cmake_minimum_required (VERSION 3.8)

add_library(NumericalIntegration INTERFACE)

target_include_directories(NumericalIntegration 
       INTERFACE
       $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
       $<INSTALL_INTERFACE:include>)

file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

install(TARGETS NumericalIntegration EXPORT NumericalIntegrationConfig DESTINATION lib)

install(FILES ${HEADERS} DESTINATION include)