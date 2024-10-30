#!/usr/bin/env bash

TYPE="$1"

if [ -z "$TYPE" ]; then
    echo "Використання: $0 <ц|cpp>"
    exit 1
fi

if [ "$TYPE" == "ц" ]; then
  echo "інструменти/інструменти.ц"
  echo "МаМа/Вказівка.ц"
  echo "МаМа/Дія.ц"
  echo "МаМа/Значення.ц"
  echo "МаМа/Логічне.ц"
  echo "МаМа/Машина.ц"
  echo "МаМа/Модуль.ц"
  echo "МаМа/Обʼєкт.ц"
  echo "МаМа/Перебір.ц"
  echo "МаМа/Помилка.ц"
  echo "МаМа/Результат.ц"
  echo "МаМа/Середовище.ц"
  echo "МаМа/Символ.ц"
  echo "МаМа/Словник.ц"
  echo "МаМа/Слово.ц"
  echo "МаМа/Список.ц"
  echo "МаМа/Структура.ц"
  echo "МаМа/Текст.ц"
  echo "МаМа/Утилізатор.ц"
  echo "МаМа/Число.ц"
  echo "компілятор/компілятор.ц"
  echo "РМв1/РМв1.ц"
  echo "мавка.ц"
  echo "бібліотека/бібліотека.ц"
  echo "бібліотека/М.ц"
  echo "бібліотека/читати.ц"
else
  echo "external/різне.cpp"
  echo "external/термінал.cpp"
  echo "external/інструменти.cpp"
  echo "external/інструменти_бібліотеки.cpp"
  echo "external/main.cpp"
fi