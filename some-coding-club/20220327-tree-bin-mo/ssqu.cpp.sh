#!/bin/bash
g++ -Wall -Wextra "ssqu.cpp" -o "ssqu.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./ssqu.cpp.out << CASE1
6 4 3
1 3 2 1 1 3
1 4
2 6
3 5
5 6
CASE1
)"
if [ "$v" = "6
9
5
2" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
