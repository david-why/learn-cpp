#!/bin/bash
g++ -Wall -Wextra "city.cpp" -o "city.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./city.cpp.out << CASE1
4 5
1 2 3
1 4 5
2 4 7
2 3 6
3 4 8

CASE1
)"
if [ "$v" = "3 6" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
