#!/bin/bash
g++ -Wall -Wextra "pair.cpp" -o "pair.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./pair.cpp.out << CASE1
5
4 6 9 3 6
CASE1
)"
if [ "$v" = "1 3
2" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./pair.cpp.out << CASE2
5
1 3 5 7 9
CASE2
)"
if [ "$v" = "1 4
1" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./pair.cpp.out << CASE3
5
2 3 5 7 11
CASE3
)"
if [ "$v" = "5 0
1 2 3 4 5" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
