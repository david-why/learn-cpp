#!/bin/bash
g++ -Wall -Wextra "rope.cpp" -o "rope.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./rope.cpp.out << CASE1
4 11
8.02
7.43
4.57
5.39
CASE1
)"
if [ "$v" = "2.00" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
