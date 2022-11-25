#!/bin/bash
g++ -Wall -Wextra "portal.cpp" -o "portal.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./portal.cpp.out << CASE1
4 5
1 2 3
1 3 6
2 3 4
2 4 7
3 4 2

CASE1
)"
if [ "$v" = "14" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
