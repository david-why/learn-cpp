#!/bin/bash
g++ -Wall -Wextra "cards2.cpp" -o "cards.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./cards.cpp.out << CASE1
3
1 2 3
2 1 3
CASE1
)"
if [ "$v" = "3" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./cards.cpp.out << CASE2
5
2 3 5 4 1
4 2 1 3 5
CASE2
)"
if [ "$v" = "12" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./cards.cpp.out << CASE3
8
1 2 3 4 5 6 7 8
1 2 3 4 5 6 7 8
CASE3
)"
if [ "$v" = "1" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
