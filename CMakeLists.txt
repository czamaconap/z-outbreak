# Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(Z_OUTBREAK)

# Estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Genera compile_commands.json para IntelliSense / clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Si no se especifica tipo de build, usar Debug por defecto
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Buscar dependencias del sistema
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# =========================
# Engine
# =========================
add_library(engine
    engine/src/core/gl_system.cpp
    engine/src/core/time.cpp
    engine/src/input/input.cpp
    engine/src/graphics/renderer.cpp
    engine/src/graphics/shader.cpp
    engine/src/graphics/stb_image.cpp
    vendor/glad/src/glad.c

    # Dear ImGui core
    vendor/imgui/imgui.cpp
    vendor/imgui/imgui_draw.cpp
    vendor/imgui/imgui_tables.cpp
    vendor/imgui/imgui_widgets.cpp

    # Dear ImGui backends
    vendor/imgui/backends/imgui_impl_glfw.cpp
    vendor/imgui/backends/imgui_impl_opengl3.cpp

    # Opcional
    # vendor/imgui/imgui_demo.cpp
)

target_include_directories(engine PUBLIC
    engine/include
    vendor/glad/include
    vendor/glm
    vendor/stb
    vendor/imgui
    vendor/imgui/backends
)

target_link_libraries(engine PUBLIC
    OpenGL::GL
    glfw
)

# =========================
# Game
# =========================
add_library(game
    game/src/game.cpp
    game/src/player/player.cpp
    game/src/world/room.cpp
)

target_include_directories(game PUBLIC
    game/include
)

target_link_libraries(game PUBLIC
    engine
)

# =========================
# App
# =========================
add_executable(app
    app/main.cpp
)

target_link_libraries(app PRIVATE
    game
)

# =========================
# Recursos
# =========================
file(COPY res DESTINATION ${CMAKE_BINARY_DIR})