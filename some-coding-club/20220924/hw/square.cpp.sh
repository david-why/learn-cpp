#!/bin/bash
g++ -Wall -Wextra "square.cpp" -o "square.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./square.cpp.out << CASE1
3 4
1 -1 3 2
2 -1 4 -1
-2 2 -3 -1

CASE1
)"
if [ "$v" = "9" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./square.cpp.out << CASE2
2 5
-1 -1 -3 -2 -7
-2 -1 -4 -1 -2

CASE2
)"
if [ "$v" = "-10" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
