#!/usr/bin/env sh
set -e

ScriptDir=$(dirname "$0")
Target="$1"

if [ ! -d "$ScriptDir/$Target" ]
then
  echo "No such directory $ScriptDir/$Target"
  exit 1
fi

if [ -z "$TSIL" ]
then
  TSIL="ціль"
fi
OutDir="build/$Target"
BuildFilesDir="$ScriptDir/$Target"
CompilationFiles="$(cat ФайлиКомпіляції)"
LLCompilationFiles=""

mkdir -p "$OutDir/source/external"

while IFS='' read -r CompilationFile
do
  case "$CompilationFile" in
    *".ц")
      LLCompilationFile="${CompilationFile%.ц}.ll"
      Command="$TSIL $OutDir/source/$LLCompilationFile скомпілювати $CompilationFile"
      echo "$Command"
      $Command
      if [ -z "$LLCompilationFiles" ]; then
        LLCompilationFiles=$(printf "%s" "source/$LLCompilationFile")
      else
        LLCompilationFiles=$(printf "$LLCompilationFiles %s" "source/$LLCompilationFile")
      fi
      ;;
    *)
      Command="cp $CompilationFile $OutDir/source/$CompilationFile"
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

Command="cp $BuildFilesDir/* $OutDir"
echo "$Command"
$Command
printf "%s" "$LLCompilationFiles"> "$OutDir/SourceFiles"