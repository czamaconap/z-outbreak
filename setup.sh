#!/bin/bash

# Nombre del proyecto (puedes cambiarlo)
PROJECT_NAME="z-outbreak"

echo "🚀 Creando estructura del proyecto: $PROJECT_NAME"

# Carpeta raíz
mkdir -p $PROJECT_NAME
cd $PROJECT_NAME || exit

# App
mkdir -p app

# Engine
mkdir -p engine/include/core
mkdir -p engine/include/graphics
mkdir -p engine/include/math
mkdir -p engine/include/input
mkdir -p engine/include/scene

mkdir -p engine/src/core
mkdir -p engine/src/graphics
mkdir -p engine/src/math
mkdir -p engine/src/input
mkdir -p engine/src/scene

# Game
mkdir -p game/include/player
mkdir -p game/include/world
mkdir -p game/include/enemies
mkdir -p game/include/systems

mkdir -p game/src/player
mkdir -p game/src/world
mkdir -p game/src/enemies
mkdir -p game/src/systems

# Recursos
mkdir -p res/shaders
mkdir -p res/textures
mkdir -p res/models
mkdir -p res/audio
mkdir -p res/ui
mkdir -p res/scenes

# Vendor (librerías externas)
mkdir -p vendor/glad
mkdir -p vendor/glm
mkdir -p vendor/stb
mkdir -p vendor/imgui

# Build
mkdir -p build

echo "✅ Estructura creada correctamente"