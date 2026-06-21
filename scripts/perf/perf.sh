#!/bin/bash
set -e

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
MAVKA="$1"

echo "--- МАВКА ---"
time $MAVKA "$SCRIPT_DIR/міліон.м"
echo

echo "--- PYTHON ---"
time python "$SCRIPT_DIR/milion.py"
echo

echo "--- RUBY ---"
time ruby "$SCRIPT_DIR/milion.rb"
echo

echo "--- LUA ---"
time lua "$SCRIPT_DIR/milion.lua"
echo

echo "--- PHP ---"
time php "$SCRIPT_DIR/milion.php"
echo

echo "--- NODE ---"
time node "$SCRIPT_DIR/milion.js"