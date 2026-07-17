#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
cd "$ROOT_DIR"

NCURSES_VERSION="$(cat "$SCRIPT_DIR/NCURSES_VERSION")"
READLINE_VERSION="$(cat "$SCRIPT_DIR/READLINE_VERSION")"
LIBUV_VERSION="$(cat "$SCRIPT_DIR/LIBUV_VERSION")"
OPENSSL_VERSION="$(cat "$SCRIPT_DIR/OPENSSL_VERSION")"
CURL_VERSION="$(cat "$SCRIPT_DIR/CURL_VERSION")"

if command -v curl >/dev/null 2>&1; then
  FETCH="curl -L --fail -o"
elif command -v wget >/dev/null 2>&1; then
  FETCH="wget -O"
else
  echo "Error: install curl or wget to download dependencies." >&2
  exit 1
fi

download_file() {
  local url="$1"
  local dest="$2"

  if [ -f "$dest" ]; then
    echo "Already downloaded: $(basename "$dest")"
    return
  fi

  mkdir -p "$(dirname "$dest")"
  echo "Downloading $(basename "$dest")..."
  if command -v curl >/dev/null 2>&1; then
    curl -L --fail -o "$dest" "$url"
  else
    wget -O "$dest" "$url"
  fi
}

cat <<'EOF'
This script downloads the third-party source archives required by
scripts/build_deps.sh: ncurses, readline, libuv, openssl, curl.
EOF

download_file "https://ftp.gnu.org/gnu/ncurses/ncurses-${NCURSES_VERSION}.tar.gz" "scripts/ncurses-${NCURSES_VERSION}.tar.gz"
download_file "https://ftp.gnu.org/gnu/readline/readline-${READLINE_VERSION}.tar.gz" "scripts/readline-${READLINE_VERSION}.tar.gz"
download_file "https://dist.libuv.org/dist/v${LIBUV_VERSION}/libuv-v${LIBUV_VERSION}.tar.gz" "scripts/libuv-v${LIBUV_VERSION}.tar.gz"
download_file "https://github.com/openssl/openssl/releases/download/openssl-${OPENSSL_VERSION}/openssl-${OPENSSL_VERSION}.tar.gz" "scripts/openssl-${OPENSSL_VERSION}.tar.gz"
download_file "https://curl.se/download/curl-${CURL_VERSION}.tar.gz" "scripts/curl-${CURL_VERSION}.tar.gz"

echo "Download complete."