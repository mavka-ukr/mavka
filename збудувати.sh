#!/usr/bin/env sh
set -e
set -x

ціль .плавлення/мавка.o скомпілювати мавка.ц
clang++ -o мавка .плавлення/мавка.o external/extension.cpp external/main.cpp