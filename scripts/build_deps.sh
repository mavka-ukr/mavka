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

ensure_tarball() {
  local tarball="$1"
  if [ ! -f "$tarball" ]; then
    echo "Skipping dependency: missing $tarball"
    return 1
  fi
  return 0
}

build_ncurses() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5"
  local ncurses_dir="будування/ncurses/$target/ncurses-6.4"
  local build_dir="$ncurses_dir/build_ncurses"
  local tarball="$(pwd)/scripts/ncurses-6.4.tar.gz"

  if ! ensure_tarball "$tarball"; then
    return 1
  fi

  extract_if_needed "$tarball" "$ncurses_dir"

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
  local tarball="$(pwd)/scripts/readline-8.2.tar.gz"

  if [ ! -d "$ncurses_build_dir" ]; then
    echo "Skipping readline: missing ncurses build dir $ncurses_build_dir"
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

build_libuv() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5"
  local uv_dir="будування/libuv/$target/libuv-v1.51.0"
  local build_dir="$uv_dir/build_libuv"
  local tarball="$(pwd)/scripts/libuv-v1.51.0.tar.gz"

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

    AR="$ar" RANLIB="$ranlib" CC="$cc --target=$target" CFLAGS="-O3" LDFLAGS="$ldflags" \
      ./configure --host="$configure_host" --prefix="$(pwd)/build_libuv"
    make -j"$(nproc)"
    make install
    popd > /dev/null
  fi

  RESULT_DIR="$build_dir"
}

build_openssl() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5"
  local openssl_dir="будування/openssl/$target/openssl-3.2.1"
  local build_dir="$openssl_dir/build_openssl"
  local tarball="$(pwd)/scripts/openssl-3.2.1.tar.gz"

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
    fi

    AR="$ar" RANLIB="$ranlib" CC="$cc" \
      CFLAGS="--target=$target -O3" LDFLAGS="$ldflags" \
      ./Configure "$os_target" --prefix="$abs_prefix" --libdir=lib \
        no-shared no-module no-dso no-tests no-docs

    make -j"$(nproc)"
    make install_sw
    popd > /dev/null
  fi

  RESULT_DIR="$build_dir"
}

build_curl() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5" openssl_build_dir="$6"
  local curl_dir="будування/curl/$target/curl-8.6.0"
  local build_dir="$curl_dir/build_curl"
  local tarball="$(pwd)/scripts/curl-8.6.0.tar.gz"

  if [ ! -d "$openssl_build_dir" ]; then
    echo "Skipping curl: missing openssl build dir $openssl_build_dir"
    return 1
  fi

  local abs_openssl_dir
  abs_openssl_dir="$(cd "$openssl_build_dir" && pwd)"

  if ! ensure_tarball "$tarball"; then
    return 1
  fi

  extract_if_needed "$tarball" "$curl_dir"

  if [ ! -d "$build_dir" ]; then
    pushd "$curl_dir" > /dev/null

    mkdir -p build_curl
    local abs_prefix
    abs_prefix="$(cd build_curl && pwd)"

    local configure_host="$target"
    local extra_libs="-lpthread"
    if [[ "$target" == *"windows"* ]]; then
      extra_libs="-lws2_32 -lgdi32 -lcrypt32 -luser32"
      [ "$target" = "x86_64-windows-gnu" ] && configure_host="x86_64-w64-mingw32"
      [ "$target" = "aarch64-windows-gnu" ] && configure_host="aarch64-w64-mingw32"
    elif [[ "$target" == *"linux"* ]]; then
      extra_libs="-ldl -lpthread"
    elif [[ "$target" == *"macos"* ]]; then
      extra_libs="-lpthread"
      [ "$target" = "x86_64-macos" ] && configure_host="x86_64-apple-darwin"
      [ "$target" = "aarch64-macos" ] && configure_host="aarch64-apple-darwin"
    fi

    AR="$ar" RANLIB="$ranlib" CC="$cc --target=$target" \
      CFLAGS="-O3" LDFLAGS="$ldflags -L$abs_openssl_dir/lib" \
      CPPFLAGS="-I$abs_openssl_dir/include" \
      LIBS="$extra_libs" \
      ./configure --host="$configure_host" --prefix="$abs_prefix" \
        --enable-static --disable-shared \
        --with-openssl="$abs_openssl_dir" \
        --disable-docs --disable-manual --without-libpsl

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

  DEPS_CFLAGS=""
  DEPS_LIBS=""

  local ncurses_build=""
  local readline_build=""
  local uv_build=""
  local openssl_build=""
  local curl_build=""

  if build_ncurses "$ar" "$ranlib" "$cc" "$target" "$ldflags"; then
    ncurses_build="$RESULT_DIR"
  else
    echo "ncurses support disabled"
  fi

  if [ -n "$ncurses_build" ] && build_readline "$ar" "$ranlib" "$cc" "$target" "$ldflags" "$ncurses_build"; then
    readline_build="$RESULT_DIR"
  else
    echo "readline support disabled"
  fi

  if build_libuv "$ar" "$ranlib" "$cc" "$target" "$ldflags"; then
    uv_build="$RESULT_DIR"
  else
    echo "libuv support disabled"
  fi

  if build_openssl "$ar" "$ranlib" "$cc" "$target" "$ldflags"; then
    openssl_build="$RESULT_DIR"
  else
    echo "openssl support disabled"
  fi

  if [ -n "$openssl_build" ] && build_curl "$ar" "$ranlib" "$cc" "$target" "$ldflags" "$openssl_build"; then
    curl_build="$RESULT_DIR"
  else
    echo "curl support disabled"
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

  if [ -n "$curl_build" ]; then
    DEPS_CFLAGS+=" -I$root/$curl_build/include"
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

  if [ -n "$curl_build" ]; then
    DEPS_LIBS+=" $root/$curl_build/lib/libcurl.a"
  fi

  if [ -n "$openssl_build" ]; then
    DEPS_LIBS+=" $root/$openssl_build/lib/libssl.a"
    DEPS_LIBS+=" $root/$openssl_build/lib/libcrypto.a"
    DEPS_LIBS+=" -ldl -lpthread"
  fi
}

setup_windows_libraries() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5"
  local root
  root="$(pwd)"

  DEPS_CFLAGS=""
  DEPS_LIBS=""

  local uv_build=""
  local openssl_build=""
  local curl_build=""

  if build_libuv "$ar" "$ranlib" "$cc" "$target" "$ldflags"; then
    uv_build="$RESULT_DIR"
  else
    echo "libuv support disabled"
  fi

  if build_openssl "$ar" "$ranlib" "$cc" "$target" "$ldflags"; then
    openssl_build="$RESULT_DIR"
  else
    echo "openssl support disabled"
  fi

  if [ -n "$openssl_build" ] && build_curl "$ar" "$ranlib" "$cc" "$target" "$ldflags" "$openssl_build"; then
    curl_build="$RESULT_DIR"
  else
    echo "curl support disabled"
  fi

  if [ -n "$openssl_build" ]; then
    DEPS_CFLAGS+=" -I$root/$openssl_build/include"
  fi

  if [ -n "$curl_build" ]; then
    DEPS_CFLAGS+=" -I$root/$curl_build/include"
  fi

  if [ -n "$uv_build" ]; then
    DEPS_LIBS+=" $root/$uv_build/lib/libuv.a"
  fi

  if [ -n "$curl_build" ]; then
    DEPS_LIBS+=" $root/$curl_build/lib/libcurl.a"
  fi

  if [ -n "$openssl_build" ]; then
    DEPS_LIBS+=" $root/$openssl_build/lib/libssl.a"
    DEPS_LIBS+=" $root/$openssl_build/lib/libcrypto.a"
    DEPS_LIBS+=" -lws2_32 -lgdi32 -lcrypt32 -luser32"
  fi
}

setup_macos_libraries() {
  local ar="$1" ranlib="$2" cc="$3" target="$4" ldflags="$5"
  local root
  root="$(pwd)"

  DEPS_CFLAGS=""
  DEPS_LIBS=""

  local uv_build=""
  local openssl_build=""
  local curl_build=""

  if build_libuv "$ar" "$ranlib" "$cc" "$target" "$ldflags"; then
    uv_build="$RESULT_DIR"
  else
    echo "libuv support disabled"
  fi

  if build_openssl "$ar" "$ranlib" "$cc" "$target" "$ldflags"; then
    openssl_build="$RESULT_DIR"
  else
    echo "openssl support disabled"
  fi

  if [ -n "$openssl_build" ] && build_curl "$ar" "$ranlib" "$cc" "$target" "$ldflags" "$openssl_build"; then
    curl_build="$RESULT_DIR"
  else
    echo "curl support disabled"
  fi

  if [ -n "$openssl_build" ]; then
    DEPS_CFLAGS+=" -I$root/$openssl_build/include"
  fi

  if [ -n "$curl_build" ]; then
    DEPS_CFLAGS+=" -I$root/$curl_build/include"
  fi

  if [ -n "$uv_build" ]; then
    DEPS_LIBS+=" $root/$uv_build/lib/libuv.a"
  fi

  if [ -n "$curl_build" ]; then
    DEPS_LIBS+=" $root/$curl_build/lib/libcurl.a"
  fi

  if [ -n "$openssl_build" ]; then
    DEPS_LIBS+=" $root/$openssl_build/lib/libssl.a"
    DEPS_LIBS+=" $root/$openssl_build/lib/libcrypto.a"
    DEPS_LIBS+=" -lpthread"
  fi
}