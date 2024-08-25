cmake_minimum_required(VERSION 3.17)
project(Vulkan2D)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    # We're in the root, define additional targets for developers.

    add_subdirectory(examples/main)
    add_subdirectory(examples/retrolook)
    add_subdirectory(examples/splitscreen)
    add_subdirectory(examples/instancing)
    add_subdirectory(examples/multithread-loading)
    add_subdirectory(examples/shadows)
    add_subdirectory(examples/shadowsglsl)

endif()

add_library(Vulkan2D INTERFACE)


FILE(GLOB_RECURSE Vulkan2D_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/VK2D/*.c
)
target_sources(Vulkan2D PUBLIC
    ${Vulkan2D_SOURCES}
)
target_include_directories(Vulkan2D INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/
)
