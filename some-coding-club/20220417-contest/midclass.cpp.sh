#!/bin/bash
g++ -Wall -Wextra "midclass.cpp" -o "midclass.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./midclass.cpp.out << CASE1
4
4 3
5 1 2 1
4 10
11 9 11 9
2 5
4 3
3 7
9 4 9
CASE1
)"
if [ "$v" = "2
4
0
3" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
