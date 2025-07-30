#!/usr/bin/env sh
set -e

ScriptDir=$(dirname "$0")
Target="$1"

if [ ! -d "$ScriptDir/$Target" ]
then
  echo "No such directory $ScriptDir/$Target"
  exit 1
fi

Triple=""

if [ "$Target" = "linux-x86_64" ]
then
  Triple="x86_64-pc-linux-gnu"
fi

if [ "$Target" = "windows-x86_64" ]
then
  Triple="x86_64-pc-windows-gnu"
fi

if [ -z "$TSIL" ]
then
  TSIL="ціль"
fi
BuildDir="build/$Target"
BuildFilesDir="$ScriptDir/$Target"
CompilationFiles="$(cat ФайлиКомпіляції)"
LLCompilationFiles=""

mkdir -p "$BuildDir/source/external"
mkdir -p "$BuildDir/source/турбо"
mkdir -p "$BuildDir/source/біб"

while IFS='' read -r CompilationFile
do
  case "$CompilationFile" in
    *".ц")
      LLCompilationFile="$CompilationFile.ll"
      mkdir -p "$(dirname "$BuildDir/source/$LLCompilationFile")"
      Command="$TSIL $BuildDir/source/$LLCompilationFile --формат=ллвмір --архітектура=ікс86_64 --система=лінукс скомпілювати $CompilationFile --біб=./БЦ"
      echo "$Command"
      $Command
      if [ -z "$LLCompilationFiles" ]; then
        LLCompilationFiles=$(printf "%s" "source/$LLCompilationFile")
      else
        LLCompilationFiles=$(printf "$LLCompilationFiles %s" "source/$LLCompilationFile")
      fi
      ;;
    *)
      mkdir -p "$(dirname "$BuildDir/source/$CompilationFile")"
      Command="cp $CompilationFile $BuildDir/source/$CompilationFile"
      echo "$Command"
      $Command
      if [ -z "$LLCompilationFiles" ]; then
        LLCompilationFiles=$(printf "%s" "source/$CompilationFile")
      else
        LLCompilationFiles=$(printf "$LLCompilationFiles %s" "source/$CompilationFile")
      fi
      ;;
  esac
done <<CompilationFiles_HEREDOC_INPUT
$CompilationFiles
CompilationFiles_HEREDOC_INPUT

Command="cp $BuildFilesDir/* $BuildDir"
echo "$Command"
$Command
Command="cp -a external $BuildDir/source"
echo "$Command"
$Command
Command="cp -a визначення $BuildDir"
echo "$Command"
$Command
Command="cp Версія $BuildDir/Version"
echo "$Command"
$Command
printf "%s" "$LLCompilationFiles"> "$BuildDir/SourceFiles"