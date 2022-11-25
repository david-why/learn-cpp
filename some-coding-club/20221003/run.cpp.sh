#!/bin/bash
g++ -Wall -Wextra "run.cpp" -o "run.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./run.cpp.out << CASE1
4 4 8
8
5
6
10
2 1 2
2 4 1
1 3 4
3 4 3

CASE1
)"
if [ "$v" = "10
" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
