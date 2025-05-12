#!/usr/bin/env sh
set -e
set -x

ціль tmp/ехо.ll скомпілювати ехо.ц
clang -o tmp/ехо tmp/ехо.ll turbo.c