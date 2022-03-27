#!/bin/bash
g++ -Wall -Wextra "xor.cpp" -o "xor.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./xor.cpp.out << CASE1
6 2 3
1 2 1 1 0 3
1 6
3 5
CASE1
)"
if [ "$v" = "7
0" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./xor.cpp.out << CASE2
5 3 1
1 1 1 1 1
1 5
2 4
1 3
CASE2
)"
if [ "$v" = "9
4
4" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
