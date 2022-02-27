#!/bin/bash
g++ -Wall -Wextra "makeeq.cpp" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./a.out << CASE1
4
4 4
1 7 5 2
2 6 5 2
3 0
3 5 2
5 4 7
5 9
5 2 5 6 3
5 9 1 9 7
6 14
11 4 6 2 8 16
43 45 9 41 15 38
CASE1
)"
if [ "$v" = "9
0
30
167" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
