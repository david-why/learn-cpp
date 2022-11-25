#!/bin/bash
g++ -Wall -Wextra "cutn.cpp" -o "cutn.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./cutn.cpp.out << CASE1
7 3

CASE1
)"
if [ "$v" = "4
" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
