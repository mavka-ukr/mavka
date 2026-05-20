#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
cd "$ROOT_DIR"

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
scripts/build_deps.sh: readline, libidn2, and libuv.
EOF

# Official upstream sources
download_file "https://invisible-mirror.net/archives/ncurses/ncurses-6.4.tar.gz" "scripts/ncurses-6.4.tar.gz"
download_file "https://ftp.gnu.org/gnu/readline/readline-8.2.tar.gz" "scripts/readline-8.2.tar.gz"
download_file "https://ftp.gnu.org/gnu/libidn/libidn2-2.3.2.tar.gz" "scripts/libidn2-2.3.2.tar.gz"
download_file "https://dist.libuv.org/dist/v1.51.0/libuv-v1.51.0.tar.gz" "scripts/libuv-v1.51.0.tar.gz"

echo "Download complete. Run 'bash scripts/build.sh <mode> <platform>' after the archives are available."
