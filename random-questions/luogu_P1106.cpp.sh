#!/bin/bash
g++ -Wall -Wextra "luogu_P1106.cpp" -o "luogu_P1106.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./luogu_P1106.cpp.out << CASE1
175438 
4

CASE1
)"
if [ "$v" = "13" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
