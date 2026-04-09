#!/bin/bash

set -e

if [ ! -d "build" ]; then
  echo "⚙️ Generando build..."
  cmake -S . -B build
fi

echo "🔨 Compilando..."
cmake --build build

echo "🚀 Ejecutando..."
./build/app