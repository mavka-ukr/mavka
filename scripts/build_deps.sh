#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

NCURSES_VERSION="$(cat "$SCRIPT_DIR/NCURSES_VERSION")"
READLINE_VERSION="$(cat "$SCRIPT_DIR/READLINE_VERSION")"
LIBUV_VERSION="$(cat "$SCRIPT_DIR/LIBUV_VERSION")"
OPENSSL_VERSION="$(cat "$SCRIPT_DIR/OPENSSL_VERSION")"
CURL_VERSION="$(cat "$SCRIPT_DIR/CURL_VERSION")"

extract_if_needed() {
  local tarball="$1"
  local extract_dir="$2"

  if [ ! -d "$extract_dir" ]; then
    mkdir -p "$(dirname "$extract_dir")"
    tar -xf "$tarball" -C "$(dirname "$extract_dir")"
  fi
}

ensure_tarball() {
  local tarball="$1"
  if [ ! -f "$tarball" ]; then
    echo "Skipping dependency: missing $tarball"
    return 1
  fi
  return 0
}

build_ncurses() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5" rc="$6"
  local ncurses_dir="build/ncurses/$target/ncurses-${NCURSES_VERSION}"
  local build_dir="$ncurses_dir/build_ncurses"
  local tarball="$(pwd)/scripts/ncurses-${NCURSES_VERSION}.tar.gz"

  if ! ensure_tarball "$tarball"; then
    return 1
  fi

  extract_if_needed "$tarball" "$ncurses_dir"

  if [ ! -d "$build_dir" ]; then
    pushd "$ncurses_dir" > /dev/null
    AR="$ar" RANLIB="$ranlib" CC="$cc" CFLAGS="-O3" LDFLAGS="$ldflags" RC="$rc" \
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
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5" rc="$6" ncurses_build_dir="$7"
  local readline_dir="build/readline/$target/readline-${READLINE_VERSION}"
  local build_dir="$readline_dir/build_readline"
  local tarball="$(pwd)/scripts/readline-${READLINE_VERSION}.tar.gz"

  if [ ! -d "$ncurses_build_dir" ]; then
    echo "Skipping readline: missing ncurses build dir $ncurses_build_dir"
    exit 1
    return 1
  fi

  if ! ensure_tarball "$tarball"; then
    return 1
  fi

  extract_if_needed "$tarball" "$readline_dir"

  if [ ! -d "$build_dir" ]; then
    pushd "$readline_dir" > /dev/null
    if [[ "$target" == *"android"* ]]; then
      export ac_cv_func_getpwent=no
      export ac_cv_func_setpwent=no
      export ac_cv_func_endpwent=no
    fi
    AR="$ar" RANLIB="$ranlib" CC="$cc" \
      CFLAGS="-O3 -I$ncurses_build_dir/include" \
      LDFLAGS="$ldflags -L$ncurses_build_dir/lib" RC="$rc" \
      ./configure --host="$target" --prefix="$(pwd)/build_readline" \
        --enable-static --disable-shared --with-curses
    make -j"$(nproc)"
    make install
    popd > /dev/null
  fi

  RESULT_DIR="$build_dir"
}

build_libuv() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5" rc="$6"
  local uv_dir="build/libuv/$target/libuv-v${LIBUV_VERSION}"
  local build_dir="$uv_dir/build_libuv"
  local tarball="$(pwd)/scripts/libuv-v${LIBUV_VERSION}.tar.gz"

  if ! ensure_tarball "$tarball"; then
    return 1
  fi

  extract_if_needed "$tarball" "$uv_dir"

  if [ ! -d "$build_dir" ]; then
    pushd "$uv_dir" > /dev/null
    sh autogen.sh

    local configure_host="$target"
    if [ "$target" = "x86_64-windows-gnu" ]; then
      configure_host="x86_64-w64-mingw32"
    elif [ "$target" = "aarch64-windows-gnu" ]; then
      configure_host="aarch64-w64-mingw32"
    elif [ "$target" = "x86_64-macos" ]; then
      configure_host="x86_64-apple-darwin"
    elif [ "$target" = "aarch64-macos" ]; then
      configure_host="aarch64-apple-darwin"
    fi

    AR="$ar" RANLIB="$ranlib" CC="$cc" CFLAGS="-O3" LDFLAGS="$ldflags" RC="$rc" \
      ./configure --host="$configure_host" --prefix="$(pwd)/build_libuv" \
        --enable-static --disable-shared
    make -j"$(nproc)"
    make install
    popd > /dev/null
  fi

  RESULT_DIR="$build_dir"
}

build_openssl() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5" rc="$6"
  local openssl_dir="build/openssl/$target/openssl-${OPENSSL_VERSION}"
  local build_dir="$openssl_dir/build_openssl"
  local tarball="$(pwd)/scripts/openssl-${OPENSSL_VERSION}.tar.gz"

  if ! ensure_tarball "$tarball"; then
    return 1
  fi

  extract_if_needed "$tarball" "$openssl_dir"

  if [ ! -d "$build_dir" ]; then
    pushd "$openssl_dir" > /dev/null

    mkdir -p build_openssl
    local abs_prefix
    abs_prefix="$(cd build_openssl && pwd)"

    local os_target="gcc"
    if [[ "$target" == *"linux"* ]]; then
      [[ "$target" == *"x86_64"* ]] && os_target="linux-x86_64"
      [[ "$target" == *"aarch64"* ]] && os_target="linux-aarch64"
    elif [[ "$target" == *"windows"* ]]; then
      [[ "$target" == *"x86_64"* ]] && os_target="mingw64"
      [[ "$target" == *"aarch64"* ]] && os_target="mingw64"
    elif [[ "$target" == *"macos"* ]]; then
      [[ "$target" == *"x86_64"* ]] && os_target="darwin64-x86_64-cc"
      [[ "$target" == *"aarch64"* ]] && os_target="darwin64-arm64-cc"
    elif [[ "$target" == *"android"* ]]; then
      [[ "$target" == *"aarch64"* ]] && os_target="android64-aarch64"
    fi

    if [[ "$target" == *"aarch64"* ]]; then
      local extra_config_flags="no-asm"
    fi

    ./Configure "$os_target" \
      --prefix="$abs_prefix" \
      --libdir=lib \
      no-shared no-module no-dso no-tests no-docs $extra_config_flags \
      CC="$cc" AR="$ar" RANLIB="$ranlib" LDFLAGS="$ldflags" RC="$rc" CFLAGS="-O3"

    make -j"$(nproc)"
    make install_sw
    popd > /dev/null
  fi

  RESULT_DIR="$build_dir"
}

setup_linux_libraries() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5" rc="$6"
  local root
  root="$(pwd)"

  DEPS_CFLAGS=""
  DEPS_LIBS=""

  local ncurses_build=""
  local readline_build=""
  local uv_build=""
  local openssl_build=""

  if build_ncurses "$ar" "$ranlib" "$cc" "$target" "$ldflags" "$rc"; then
    ncurses_build="$RESULT_DIR"
  else
    echo "ncurses support disabled"
  fi

  if [ -n "$ncurses_build" ] && build_readline "$ar" "$ranlib" "$cc" "$target" "$ldflags" "$rc" "$ncurses_build"; then
    readline_build="$RESULT_DIR"
  else
    echo "readline support disabled"
  fi

  if build_libuv "$ar" "$ranlib" "$cc" "$target" "$ldflags" "$rc"; then
    uv_build="$RESULT_DIR"
  else
    echo "libuv support disabled"
  fi

  if build_openssl "$ar" "$ranlib" "$cc" "$target" "$ldflags" "$rc"; then
    openssl_build="$RESULT_DIR"
  else
    echo "openssl support disabled"
  fi

  if [ -n "$ncurses_build" ]; then
    DEPS_CFLAGS="-I$root/$ncurses_build/include"
  fi

  if [ -n "$readline_build" ]; then
    DEPS_CFLAGS+=" -DPROGRAM_USE_READLINE -I$root/$readline_build/include"
  fi

  if [ -n "$openssl_build" ]; then
    DEPS_CFLAGS+=" -I$root/$openssl_build/include"
  fi

  if [ -n "$readline_build" ]; then
    DEPS_LIBS="$root/$readline_build/lib/libreadline.a"
    DEPS_LIBS+=" $root/$readline_build/lib/libhistory.a"
  fi

  if [ -n "$ncurses_build" ]; then
    DEPS_LIBS+=" $root/$ncurses_build/lib/libncurses.a"
    DEPS_LIBS+=" $root/$ncurses_build/lib/libform.a"
    DEPS_LIBS+=" $root/$ncurses_build/lib/libpanel.a"
  fi

  if [ -n "$uv_build" ]; then
    DEPS_LIBS+=" $root/$uv_build/lib/libuv.a"
  fi

  if [ -n "$openssl_build" ]; then
    DEPS_LIBS+=" $root/$openssl_build/lib/libssl.a"
    DEPS_LIBS+=" $root/$openssl_build/lib/libcrypto.a"
    DEPS_LIBS+=" -ldl"
  fi
}

setup_windows_libraries() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5" rc="$6"
  local root
  root="$(pwd)"

  DEPS_CFLAGS=""
  DEPS_LIBS=""

  local uv_build=""
  local openssl_build=""

  if build_libuv "$ar" "$ranlib" "$cc" "$target" "$ldflags" "$rc"; then
    uv_build="$RESULT_DIR"
  else
    echo "libuv support disabled"
  fi

  if build_openssl "$ar" "$ranlib" "$cc" "$target" "$ldflags" "$rc"; then
    openssl_build="$RESULT_DIR"
  else
    echo "openssl support disabled"
  fi

  if [ -n "$openssl_build" ]; then
    DEPS_CFLAGS+=" -I$root/$openssl_build/include"
  fi

  if [ -n "$uv_build" ]; then
    DEPS_LIBS+=" $root/$uv_build/lib/libuv.a"
  fi

  if [ -n "$openssl_build" ]; then
    DEPS_LIBS+=" $root/$openssl_build/lib/libssl.a"
    DEPS_LIBS+=" $root/$openssl_build/lib/libcrypto.a"
    DEPS_LIBS+=" -lws2_32 -lgdi32 -lcrypt32 -luser32"
  fi
}

setup_macos_libraries() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5" rc="$6"
  local root
  root="$(pwd)"

  DEPS_CFLAGS=""
  DEPS_LIBS=""

  local uv_build=""
  local openssl_build=""

  if build_libuv "$ar" "$ranlib" "$cc" "$target" "$ldflags" "$rc"; then
    uv_build="$RESULT_DIR"
  else
    echo "libuv support disabled"
  fi

  if build_openssl "$ar" "$ranlib" "$cc" "$target" "$ldflags" "$rc"; then
    openssl_build="$RESULT_DIR"
  else
    echo "openssl support disabled"
  fi

  if [ -n "$openssl_build" ]; then
    DEPS_CFLAGS+=" -I$root/$openssl_build/include"
  fi

  if [ -n "$uv_build" ]; then
    DEPS_LIBS+=" $root/$uv_build/lib/libuv.a"
  fi

  if [ -n "$openssl_build" ]; then
    DEPS_LIBS+=" $root/$openssl_build/lib/libssl.a"
    DEPS_LIBS+=" $root/$openssl_build/lib/libcrypto.a"
    DEPS_LIBS+=""
  fi
}