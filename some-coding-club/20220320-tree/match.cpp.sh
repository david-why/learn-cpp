#!/bin/bash
g++ -Wall -Wextra "match.cpp" -o "match.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./match.cpp.out << CASE1
4
2 3 1 4
3 2 1 4

CASE1
)"
if [ "$v" = "1" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./match.cpp.out << CASE2
4
1 3 4 2
1 7 2 4
CASE2
)"
if [ "$v" = "2" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
