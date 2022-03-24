#!/bin/bash
g++ -Wall -Wextra "snuke.cpp" -o "snuke.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./snuke.cpp.out << CASE1
3 3
1 2
2 3
3 3
CASE1
)"
if [ "$v" = "3
2
2" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./snuke.cpp.out << CASE2
7 9
1 7
5 9
5 7
5 9
1 1
6 8
3 4
CASE2
)"
if [ "$v" = "7
6
6
5
4
5
5
3
2" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
