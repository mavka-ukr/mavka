#!/usr/bin/env sh
set -e
set -x

if [ "$1" = "valgrind" ]
then
  valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./out/мавка тест.ю8.м
else
  ./out/мавка тест.ю8.м
fi