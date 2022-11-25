#!/bin/bash
g++ -Wall -Wextra "flower.cpp" -o "flower.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./flower.cpp.out << CASE1
5 1
2 4 5
4 3 3
1 3 2
3 4 3
3 2 5
10 10

CASE1
)"
if [ "$v" = "15
" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
