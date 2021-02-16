#!/bin/bash
g++ "$1" -o "$1.out" -static-libstdc++ -static-libgcc -O3 -Wall
export ret="$?"
if [ "$ret" != "0" ]; then exit $ret; fi
unset ret
x86_64-w64-mingw32-g++ "$1" -o "$1.exe" -static-libstdc++ -static-libgcc -O3 --no-warnings
"./$1.out"
exit $?
