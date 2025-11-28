#!/bin/bash
set -e

echo "---------------------"
echo "time node x.js"
time node x.js
echo "---------------------"
echo ""

echo "---------------------"
echo "time lua x.lua"
time lua x.lua
echo "---------------------"
echo ""

echo "---------------------"
echo "time python x.py"
time python x.py
echo "---------------------"
echo ""

echo "---------------------"
echo "time ruby x.rb"
time ruby x.rb
echo "---------------------"
echo ""

echo "---------------------"
echo "time ./будування/ікс86_64-лінукс/готове/мавка ікс.м"
time ./будування/ікс86_64-лінукс/готове/мавка ікс.м
echo "---------------------"