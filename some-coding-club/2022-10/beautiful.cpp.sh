#!/bin/bash
g++ -Wall -Wextra "beautiful.cpp" -o "beautiful.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./beautiful.cpp.out << CASE1
10 10 0 0
3 5 1 1

CASE1
)"
if [ "$v" = "0
7
" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
