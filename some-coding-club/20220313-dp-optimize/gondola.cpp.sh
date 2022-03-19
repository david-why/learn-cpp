#!/bin/bash
g++ -Wall -Wextra "gondola.cpp" -o "gondola.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./gondola.cpp.out << CASE1
5 2
0 0 1 1 1
0 0 1 1 1
1 1 0 0 0
1 1 0 0 0
1 1 0 0 0
CASE1
)"
if [ "$v" = "0" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./gondola.cpp.out << CASE2
8 3
0 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1
1 1 0 1 1 1 1 1
1 1 1 0 1 1 1 1
1 1 1 1 0 1 1 1
1 1 1 1 1 0 1 1
1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 0
CASE2
)"
if [ "$v" = "7" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./gondola.cpp.out << CASE3
3 2
0 2 0
2 0 3
0 3 0
CASE3
)"
if [ "$v" = "2" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
