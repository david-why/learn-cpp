#!/bin/bash
g++ -Wall -Wextra "cows.cpp" -o "cows.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./cows.cpp.out << CASE1
5 
4 
6 
9 
10 
13 

CASE1
)"
if [ "$v" = "8" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
