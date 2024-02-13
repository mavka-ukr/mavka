#!/usr/bin/env bash

MTESTS=$(ls mtests)
MAVKA_VERSION=$(cat VERSION)

for mtest in ${MTESTS[@]}; do
  if [[ $mtest == *"_тест.м" ]]; then
    echo -en "Тестуємо ./mtests/$mtest"
    result=$("./dist/мавка-$MAVKA_VERSION/мавка" "./mtests/$mtest")
    if [ "$result" == "ок" ]; then
        echo -en ": \e[32mok\e[0m\n"
    else
        echo -en "\n\e[31m$result\e[0m\n"
    fi
  fi
done