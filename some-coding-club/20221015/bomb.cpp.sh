#!/bin/bash
g++ -Wall -Wextra "bomb.cpp" -o "bomb.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./bomb.cpp.out << CASE1
6 6
1 2
2 3
2 4
3 5
4 5
5 6
CASE1
)"
if [ "$v" = "1 2
5 6" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
