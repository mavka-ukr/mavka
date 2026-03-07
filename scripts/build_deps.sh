#!/bin/bash
set -e

extract_if_needed() {
  local tarball="$1"
  local extract_dir="$2"

  if [ ! -d "$extract_dir" ]; then
    mkdir -p "$(dirname "$extract_dir")"
    tar -xf "$tarball" -C "$(dirname "$extract_dir")"
  fi
}

build_ncurses() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5"
  local ncurses_dir="будування/ncurses/$target/ncurses-6.4"
  local build_dir="$ncurses_dir/build_ncurses"

  extract_if_needed "$(pwd)/scripts/ncurses-6.4.tar.gz" "$ncurses_dir"

  if [ ! -d "$build_dir" ]; then
    pushd "$ncurses_dir" > /dev/null
    AR="$ar" RANLIB="$ranlib" CC="$cc --target=$target" CFLAGS="-O3" LDFLAGS="$ldflags" \
      ./configure --host="$target" --prefix="$(pwd)/build_ncurses" \
        --with-shared=no --with-static=yes --without-progs --without-tests \
        --without-cxx --without-cxx-binding --without-ada --without-curses-h
    make -j"$(nproc)"
    make install
    popd > /dev/null
  fi

  RESULT_DIR="$build_dir"
}

build_readline() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5" ncurses_build_dir="$6"
  local readline_dir="будування/readline/$target/readline-8.2"
  local build_dir="$readline_dir/build_readline"

  extract_if_needed "$(pwd)/scripts/readline-8.2.tar.gz" "$readline_dir"

  if [ ! -d "$build_dir" ]; then
    pushd "$readline_dir" > /dev/null
    if [[ "$target" == *"android"* ]]; then
      export ac_cv_func_getpwent=no
      export ac_cv_func_setpwent=no
      export ac_cv_func_endpwent=no
    fi
    AR="$ar" RANLIB="$ranlib" CC="$cc --target=$target" \
      CFLAGS="-I$ncurses_build_dir/include -O3" \
      LDFLAGS="$ldflags -L$ncurses_build_dir/lib" \
      ./configure --host="$target" --prefix="$(pwd)/build_readline" \
        --enable-static --disable-shared --with-curses \
        --without-progs --without-tests --without-cxx --without-cxx-binding
    make -j"$(nproc)"
    make install
    popd > /dev/null
  fi

  RESULT_DIR="$build_dir"
}

build_idn2() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5"
  local idn2_dir="будування/libidn2/$target/libidn2-2.3.2"
  local build_dir="$idn2_dir/build_idn2"

  extract_if_needed "$(pwd)/scripts/libidn2-2.3.2.tar.gz" "$idn2_dir"

  if [ ! -d "$build_dir" ]; then
    pushd "$idn2_dir" > /dev/null
    if [[ "$target" == *"android"* ]]; then
      export ac_cv_func_strchrnul=no
    fi
    AR="$ar" RANLIB="$ranlib" CC="$cc --target=$target" CFLAGS="-O3" LDFLAGS="$ldflags" \
      ./configure --host="$target" --prefix="$(pwd)/build_idn2" \
        --enable-static --disable-shared --without-tests --without-gcc-atomics
    make -j"$(nproc)"
    make install
    popd > /dev/null
  fi

  RESULT_DIR="$build_dir"
}

build_uv() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5"
  local uv_dir="будування/libuv/$target/libuv-v1.51.0"
  local build_dir="$uv_dir/build_uv"

  extract_if_needed "$(pwd)/scripts/libuv-v1.51.0.tar.gz" "$uv_dir"

  if [ ! -d "$build_dir" ]; then
    pushd "$uv_dir" > /dev/null
    sh autogen.sh
    AR="$ar" RANLIB="$ranlib" CC="$cc --target=$target" CFLAGS="-O3" LDFLAGS="$ldflags" \
      ./configure --host="$target" --prefix="$(pwd)/build_uv"
    make -j"$(nproc)"
    make install
    popd > /dev/null
  fi

  RESULT_DIR="$build_dir"
}

setup_linux_libraries() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5"
  local root
  root="$(pwd)"

  build_ncurses "$ar" "$ranlib" "$cc" "$target" "$ldflags"
  local ncurses_build="$RESULT_DIR"

  build_readline "$ar" "$ranlib" "$cc" "$target" "$ldflags" "$ncurses_build"
  local readline_build="$RESULT_DIR"

  build_idn2 "$ar" "$ranlib" "$cc" "$target" "$ldflags"
  local idn2_build="$RESULT_DIR"

  build_uv "$ar" "$ranlib" "$cc" "$target" "$ldflags"
  local uv_build="$RESULT_DIR"

  DEPS_CFLAGS="-I$root/$ncurses_build/include"
  DEPS_CFLAGS+=" -DPROGRAM_USE_READLINE -I$root/$readline_build/include"
  DEPS_CFLAGS+=" -I$root/$idn2_build/include"

  DEPS_LIBS="$root/$readline_build/lib/libreadline.a"
  DEPS_LIBS+=" $root/$readline_build/lib/libhistory.a"
  DEPS_LIBS+=" $root/$ncurses_build/lib/libncurses.a"
  DEPS_LIBS+=" $root/$ncurses_build/lib/libform.a"
  DEPS_LIBS+=" $root/$ncurses_build/lib/libpanel.a"
  DEPS_LIBS+=" $root/$idn2_build/lib/libidn2.a"
  DEPS_LIBS+=" $root/$uv_build/lib/libuv.a"
}
