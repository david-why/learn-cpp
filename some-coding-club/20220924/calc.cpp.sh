#!/bin/bash
g++ -Wall -Wextra "calc.cpp" -o "calc.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./calc.cpp.out << CASE1
6

CASE1
)"
if [ "$v" = "6
" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
