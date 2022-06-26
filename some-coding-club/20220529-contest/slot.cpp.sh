#!/bin/bash
g++ -Wall -Wextra "slot.cpp" -o "slot.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./slot.cpp.out << CASE1
3
1937458062
8124690357
2385760149
CASE1
)"
if [ "$v" = "6" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./slot.cpp.out << CASE2
5
0123456789
0123456789
0123456789
0123456789
0123456789
CASE2
)"
if [ "$v" = "40" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
