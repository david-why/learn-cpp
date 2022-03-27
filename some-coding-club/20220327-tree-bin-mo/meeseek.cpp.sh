#!/bin/bash
g++ -Wall -Wextra "meeseek.cpp" -o "meeseek.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./meeseek.cpp.out << CASE1
5
1 3 4 3 3
CASE1
)"
if [ "$v" = "4 2 1 1 1" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./meeseek.cpp.out << CASE2
8
1 5 7 8 1 7 6 1
CASE2
)"
if [ "$v" = "8 4 3 2 1 1 1 1" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
