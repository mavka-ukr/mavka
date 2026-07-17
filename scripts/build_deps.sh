#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

NCURSES_VERSION="$(cat "$SCRIPT_DIR/NCURSES_VERSION")"
READLINE_VERSION="$(cat "$SCRIPT_DIR/READLINE_VERSION")"
LIBUV_VERSION="$(cat "$SCRIPT_DIR/LIBUV_VERSION")"
OPENSSL_VERSION="$(cat "$SCRIPT_DIR/OPENSSL_VERSION")"
CURL_VERSION="$(cat "$SCRIPT_DIR/CURL_VERSION")"

TARGET=""
TARGET_CC=""
TARGET_AR=""
TARGET_RANLIB=""
TARGET_RC=""
TARGET_CPPFLAGS=""
TARGET_CFLAGS=""
TARGET_LDFLAGS=""

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
  local ncurses_dir="build/ncurses/$TARGET/ncurses-${NCURSES_VERSION}"
  local build_dir="$ncurses_dir/build_ncurses"
  local tarball="$(pwd)/scripts/ncurses-${NCURSES_VERSION}.tar.gz"

  if ! ensure_tarball "$tarball"; then
    return 1
  fi

  extract_if_needed "$tarball" "$ncurses_dir"

  if [ ! -d "$build_dir" ]; then
    pushd "$ncurses_dir" > /dev/null
    CC="$TARGET_CC" AR="$TARGET_AR" RANLIB="$TARGET_RANLIB" RC="$TARGET_RC" CPPFLAGS="$TARGET_CPPFLAGS" CFLAGS="$TARGET_CFLAGS" LDFLAGS="$TARGET_LDFLAGS" \
      ./configure --build="$(clang -dumpmachine)" --host="$TARGET" --prefix="$(pwd)/build_ncurses" \
        --with-shared=no --with-static=yes --without-progs --without-tests \
        --without-cxx --without-cxx-binding --without-ada --without-curses-h
    make -j"$(nproc)"
    make install
    popd > /dev/null
  fi

  RESULT_DIR="$build_dir"
}

build_readline() {
  local ncurses_build_dir="$1"
  local readline_dir="build/readline/$TARGET/readline-${READLINE_VERSION}"
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
    if [[ "$TARGET" == *"android"* ]]; then
      export ac_cv_func_getpwent=no
      export ac_cv_func_setpwent=no
      export ac_cv_func_endpwent=no
    fi
    CC="$TARGET_CC" AR="$TARGET_AR" RANLIB="$TARGET_RANLIB" RC="$TARGET_RC" CPPFLAGS="$TARGET_CPPFLAGS -I$ncurses_build_dir/include" CFLAGS="$TARGET_CFLAGS" LDFLAGS="$TARGET_LDFLAGS -L$ncurses_build_dir/lib" \
      ./configure --build="$(clang -dumpmachine)" --host="$TARGET" --prefix="$(pwd)/build_readline" \
        --enable-static --disable-shared --with-curses
    make -j"$(nproc)"
    make install
    popd > /dev/null
  fi

  RESULT_DIR="$build_dir"
}

build_libuv() {
  local uv_dir="build/libuv/$TARGET/libuv-v${LIBUV_VERSION}"
  local build_dir="$uv_dir/build_libuv"
  local tarball="$(pwd)/scripts/libuv-v${LIBUV_VERSION}.tar.gz"

  if ! ensure_tarball "$tarball"; then
    return 1
  fi

  extract_if_needed "$tarball" "$uv_dir"

  if [ ! -d "$build_dir" ]; then
    local abs_uv_dir
    abs_uv_dir="$(cd "$uv_dir" && pwd)"
    local abs_prefix="$abs_uv_dir/build_libuv"

    mkdir -p "$build_dir"
    pushd "$build_dir" > /dev/null

    local cmake_system_name=""
    local cmake_android_flags=""

    if [[ "$TARGET" == *"w64-mingw32"* ]]; then
      cmake_system_name="Windows"
    elif [[ "$TARGET" == *"apple-darwin"* ]]; then
      cmake_system_name="Darwin"
    elif [[ "$TARGET" == *"android"* ]]; then
      cmake_system_name="Android"
      if [ -z "$ANDROID_NDK_HOME" ]; then
        echo "ANDROID_NDK_HOME is not set."
        exit 1
      fi
      local api_level="${TARGET##*android}"
      cmake_android_flags="-DCMAKE_ANDROID_NDK=$ANDROID_NDK_HOME -DCMAKE_SYSTEM_VERSION=$api_level -DCMAKE_ANDROID_ARCH_ABI=arm64-v8a"
    elif [[ "$TARGET" == *"linux"* ]]; then
      cmake_system_name="Linux"
    elif [[ "$TARGET" == *"wasm64"* ]]; then
      cmake_system_name="Generic"
    fi

    cmake "$abs_uv_dir" \
      -DCMAKE_SYSTEM_NAME="$cmake_system_name" \
      $cmake_android_flags \
      -DCMAKE_INSTALL_PREFIX="$abs_prefix" \
      -DCMAKE_C_COMPILER="$TARGET_CC" \
      -DCMAKE_C_FLAGS="$TARGET_CPPFLAGS $TARGET_CFLAGS" \
      -DCMAKE_EXE_LINKER_FLAGS="$TARGET_LDFLAGS" \
      -DCMAKE_AR="$TARGET_AR" \
      -DCMAKE_RANLIB="$TARGET_RANLIB" \
      -DBUILD_SHARED_LIBS=OFF \
      -DBUILD_TESTING=OFF

    make -j"$(nproc)"
    make install

    popd > /dev/null
  fi

  RESULT_DIR="$build_dir"
}

build_openssl() {
  local openssl_dir="build/openssl/$TARGET/openssl-${OPENSSL_VERSION}"
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
    if [[ "$TARGET" == *"linux"* ]]; then
      [[ "$TARGET" == *"x86_64"* ]] && os_target="linux-x86_64"
      [[ "$TARGET" == *"aarch64"* ]] && os_target="linux-aarch64"
    elif [[ "$TARGET" == *"windows"* ]]; then
      [[ "$TARGET" == *"x86_64"* ]] && os_target="mingw64"
      [[ "$TARGET" == *"aarch64"* ]] && os_target="mingw64"
    elif [[ "$TARGET" == *"apple-darwin"* ]]; then
      [[ "$TARGET" == *"x86_64"* ]] && os_target="darwin64-x86_64-cc"
      [[ "$TARGET" == *"aarch64"* ]] && os_target="darwin64-arm64-cc"
    elif [[ "$TARGET" == *"android"* ]]; then
      [[ "$TARGET" == *"aarch64"* ]] && os_target="android64-aarch64"
    fi

    local extra_config_flags=""
    if [[ "$TARGET" == *"aarch64"* ]]; then
      extra_config_flags="no-asm"
    fi

    ./Configure "$os_target" \
      --prefix="$abs_prefix" \
      --libdir=lib \
      no-shared no-module no-dso no-tests no-docs no-apps $extra_config_flags \
      CC="$TARGET_CC" AR="$TARGET_AR" RANLIB="$TARGET_RANLIB" RC="$TARGET_RC" CPPFLAGS="$TARGET_CPPFLAGS" CFLAGS="$TARGET_CFLAGS" LDFLAGS="$TARGET_LDFLAGS"

    make -j"$(nproc)"
    make install_sw
    popd > /dev/null
  fi

  RESULT_DIR="$build_dir"
}

build_curl() {
  local openssl_build_dir="$1"
  local curl_dir="build/curl/$TARGET/curl-${CURL_VERSION}"
  local build_dir="$curl_dir/build_curl"
  local tarball="$(pwd)/scripts/curl-${CURL_VERSION}.tar.gz"

  if [ ! -d "$openssl_build_dir" ]; then
    echo "Skipping curl: missing openssl build dir $openssl_build_dir"
    return 1
  fi

  if ! ensure_tarball "$tarball"; then
    return 1
  fi

  local abs_openssl_dir
  abs_openssl_dir="$(cd "$openssl_build_dir" && pwd)"

  extract_if_needed "$tarball" "$curl_dir"

  if [ ! -d "$build_dir" ]; then
    local abs_curl_dir
    abs_curl_dir="$(cd "$curl_dir" && pwd)"
    local abs_prefix="$abs_curl_dir/build_curl"

    mkdir -p "$build_dir"
    pushd "$build_dir" > /dev/null

    local cmake_system_name=""
    local cmake_android_flags=""

    if [[ "$TARGET" == *"w64-mingw32"* ]]; then
      cmake_system_name="Windows"
    elif [[ "$TARGET" == *"apple-darwin"* ]]; then
      cmake_system_name="Darwin"
    elif [[ "$TARGET" == *"android"* ]]; then
      cmake_system_name="Android"
      if [ -z "$ANDROID_NDK_HOME" ]; then
        echo "ANDROID_NDK_HOME is not set."
        exit 1
      fi
      local api_level="${TARGET##*android}"
      cmake_android_flags="-DCMAKE_ANDROID_NDK=$ANDROID_NDK_HOME -DCMAKE_SYSTEM_VERSION=$api_level -DCMAKE_ANDROID_ARCH_ABI=arm64-v8a"
    elif [[ "$TARGET" == *"linux"* ]]; then
      cmake_system_name="Linux"
    elif [[ "$TARGET" == *"wasm64"* ]]; then
      cmake_system_name="Generic"
    fi

    cmake "$abs_curl_dir" \
      -DCMAKE_SYSTEM_NAME="$cmake_system_name" \
      $cmake_android_flags \
      -DCMAKE_INSTALL_PREFIX="$abs_prefix" \
      -DCMAKE_C_COMPILER="$TARGET_CC" \
      -DCMAKE_C_FLAGS="$TARGET_CPPFLAGS $TARGET_CFLAGS" \
      -DCMAKE_EXE_LINKER_FLAGS="$TARGET_LDFLAGS" \
      -DCMAKE_AR="$TARGET_AR" \
      -DCMAKE_RANLIB="$TARGET_RANLIB" \
      -DCURL_USE_OPENSSL=ON \
      -DOPENSSL_ROOT_DIR="$abs_openssl_dir" \
      -DOPENSSL_INCLUDE_DIR="$abs_openssl_dir/include" \
      -DOPENSSL_CRYPTO_LIBRARY="$abs_openssl_dir/lib/libcrypto.a" \
      -DOPENSSL_SSL_LIBRARY="$abs_openssl_dir/lib/libssl.a" \
      -DBUILD_SHARED_LIBS=OFF \
      -DBUILD_STATIC_LIBS=ON \
      -DBUILD_CURL_EXE=OFF \
      -DCURL_ZLIB=OFF \
      -DUSE_LIBIDN2=OFF \
      -DCURL_USE_LIBPSL=OFF \
      -DCURL_USE_LIBSSH2=OFF \
      -DCURL_BROTLI=OFF \
      -DCURL_ZSTD=OFF \
      -DUSE_NGHTTP2=OFF \
      -DENABLE_THREADED_RESOLVER=OFF \
      -DCURL_DISABLE_LDAP=ON \
      -DCURL_DISABLE_LDAPS=ON \
      -DCURL_DISABLE_RTSP=ON \
      -DCURL_DISABLE_DICT=ON \
      -DCURL_DISABLE_TELNET=ON \
      -DCURL_DISABLE_TFTP=ON \
      -DCURL_DISABLE_POP3=ON \
      -DCURL_DISABLE_IMAP=ON \
      -DCURL_DISABLE_SMB=ON \
      -DCURL_DISABLE_SMTP=ON \
      -DCURL_DISABLE_GOPHER=ON \
      -DCURL_DISABLE_MQTT=ON \
      -DCURL_CA_BUNDLE=none \
      -DCURL_CA_PATH=none \
      -DHAVE_STRUCT_TIMEVAL=1

    make -j"$(nproc)"
    make install

    popd > /dev/null
  fi

  RESULT_DIR="$build_dir"
}

setup_linux_libraries() {
  local root
  root="$(pwd)"

  DEPS_CFLAGS=""
  DEPS_LIBS=""

  local ncurses_build=""
  local readline_build=""
  local uv_build=""
  local openssl_build=""
  local curl_build=""

  if build_ncurses; then
    ncurses_build="$RESULT_DIR"
  else
    echo "ncurses support disabled"
  fi

  if [ -n "$ncurses_build" ] && build_readline "$ncurses_build"; then
    readline_build="$RESULT_DIR"
  else
    echo "readline support disabled"
  fi

  if build_libuv; then
    uv_build="$RESULT_DIR"
  else
    echo "libuv support disabled"
  fi

  if build_openssl; then
    openssl_build="$RESULT_DIR"
  else
    echo "openssl support disabled"
  fi

  if [ -n "$openssl_build" ] && build_curl "$openssl_build"; then
    curl_build="$RESULT_DIR"
  else
    echo "curl support disabled"
  fi

  if [ -n "$ncurses_build" ]; then
    DEPS_CFLAGS="${DEPS_CFLAGS:+$DEPS_CFLAGS }-I$root/$ncurses_build/include"
  fi

  if [ -n "$readline_build" ]; then
    DEPS_CFLAGS="${DEPS_CFLAGS:+$DEPS_CFLAGS }-DPROGRAM_USE_READLINE -I$root/$readline_build/include"
  fi

  if [ -n "$uv_build" ]; then
    DEPS_CFLAGS="${DEPS_CFLAGS:+$DEPS_CFLAGS }-I$root/$uv_build/include"
  fi

  if [ -n "$openssl_build" ]; then
    DEPS_CFLAGS="${DEPS_CFLAGS:+$DEPS_CFLAGS }-I$root/$openssl_build/include"
  fi

  if [ -n "$curl_build" ]; then
    DEPS_CFLAGS="${DEPS_CFLAGS:+$DEPS_CFLAGS }-I$root/$curl_build/include -DCURL_STATICLIB"
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
    DEPS_LIBS+=" -ldl"
  fi
}

setup_windows_libraries() {
  local root
  root="$(pwd)"

  DEPS_CFLAGS=""
  DEPS_LIBS=""

  local uv_build=""
  local openssl_build=""
  local curl_build=""

  if build_libuv; then
    uv_build="$RESULT_DIR"
  else
    echo "libuv support disabled"
  fi

  if build_openssl; then
    openssl_build="$RESULT_DIR"
  else
    echo "openssl support disabled"
  fi

  if [ -n "$openssl_build" ] && build_curl "$openssl_build"; then
    curl_build="$RESULT_DIR"
  else
    echo "curl support disabled"
  fi

  if [ -n "$uv_build" ]; then
    DEPS_CFLAGS="${DEPS_CFLAGS:+$DEPS_CFLAGS }-I$root/$uv_build/include"
  fi

  if [ -n "$openssl_build" ]; then
    DEPS_CFLAGS="${DEPS_CFLAGS:+$DEPS_CFLAGS }-I$root/$openssl_build/include"
  fi

  if [ -n "$curl_build" ]; then
    DEPS_CFLAGS="${DEPS_CFLAGS:+$DEPS_CFLAGS }-I$root/$curl_build/include -DCURL_STATICLIB"
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
    DEPS_LIBS+=" -lws2_32 -lgdi32 -lcrypt32 -luser32 -lbcrypt -ladvapi32"
  fi
}

setup_macos_libraries() {
  local root
  root="$(pwd)"

  DEPS_CFLAGS=""
  DEPS_LIBS=""

  local uv_build=""
  local openssl_build=""
  local curl_build=""

  if build_libuv; then
    uv_build="$RESULT_DIR"
  else
    echo "libuv support disabled"
  fi

  if build_openssl; then
    openssl_build="$RESULT_DIR"
  else
    echo "openssl support disabled"
  fi

  if [ -n "$openssl_build" ] && build_curl "$openssl_build"; then
    curl_build="$RESULT_DIR"
  else
    echo "curl support disabled"
  fi

  if [ -n "$uv_build" ]; then
    DEPS_CFLAGS="${DEPS_CFLAGS:+$DEPS_CFLAGS }-I$root/$uv_build/include"
  fi

  if [ -n "$openssl_build" ]; then
    DEPS_CFLAGS="${DEPS_CFLAGS:+$DEPS_CFLAGS }-I$root/$openssl_build/include"
  fi

  if [ -n "$curl_build" ]; then
    DEPS_CFLAGS="${DEPS_CFLAGS:+$DEPS_CFLAGS }-I$root/$curl_build/include -DCURL_STATICLIB"
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
    DEPS_LIBS+=" -framework CoreFoundation -framework CoreServices -framework SystemConfiguration"
  fi
}