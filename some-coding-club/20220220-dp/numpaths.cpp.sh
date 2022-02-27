#!/bin/bash
g++ -Wall -Wextra "numpaths.cpp" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./a.out << CASE1
4 5
2 4
1 2
2 3
1 3
3 4
CASE1
)"
if [ "$v" = "2" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./a.out << CASE2
4 3
1 3
2 3
2 4
CASE2
)"
if [ "$v" = "1" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./a.out << CASE3
2 0
CASE3
)"
if [ "$v" = "0" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 4'
v="$(time -p ./a.out << CASE4
7 8
1 3
1 4
2 3
2 4
2 5
2 6
5 7
6 7
CASE4
)"
if [ "$v" = "4" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
