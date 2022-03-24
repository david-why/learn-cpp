#!/bin/bash
g++ -Wall -Wextra "rev.cpp" -o "rev.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./rev.cpp.out << CASE1
6
5 4 2 6 3 1

CASE1
)"
if [ "$v" = "11" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
