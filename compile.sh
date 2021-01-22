#!/bin/bash
g++ $1 -o $1.out -static-libstdc++ -static-libgcc
x86_64-w64-mingw32-g++ $1 -o $1.exe -static-libstdc++ -static-libgcc
./$1.out
