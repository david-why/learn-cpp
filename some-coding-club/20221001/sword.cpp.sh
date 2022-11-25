#!/bin/bash
g++ -Wall -Wextra "sword.cpp" -o "sword.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./sword.cpp.out << CASE1
5 3 3
1 3 2 4 5

CASE1
)"
if [ "$v" = "40" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./sword.cpp.out << CASE2
5 3 3
1 -3 -2 4 5

CASE2
)"
if [ "$v" = "21" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./sword.cpp.out << CASE3
7 4 2
-5 3 -1 -4 7 -6 5

CASE3
)"
if [ "$v" = "17" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 4'
v="$(time -p ./sword.cpp.out << CASE4
5 3 1
-1 -3 -2 -4 -5

CASE4
)"
if [ "$v" = "-15" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
