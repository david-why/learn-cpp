#!/bin/bash
g++ -Wall -Wextra "yamp.cpp" -o "yamp.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./yamp.cpp.out << CASE1
7 3
1 1 3 3 3 2 1
CASE1
)"
if [ "$v" = "1" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./yamp.cpp.out << CASE2
10 2
1 2 1 2 1 2 1 2 1 2
CASE2
)"
if [ "$v" = "8" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./yamp.cpp.out << CASE3
13 3
1 2 2 2 1 2 1 1 1 2 2 1 1
CASE3
)"
if [ "$v" = "9" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
