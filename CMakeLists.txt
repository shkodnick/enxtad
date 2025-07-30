cmake_minimum_required(VERSION 4.0.3)
project(app VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew")

find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)
find_package(glm REQUIRED)

add_executable(app
    src/main.cpp
    src/first_app.cpp
    src/app_window.cpp
    src/instance.cpp)

target_include_directories(app
    PRIVATE
    dependencies)

target_link_libraries(app
    glfw
    Vulkan::Vulkan
    )