#!/bin/bash
g++ -Wall -Wextra "doremy.cpp" -o "doremy.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./doremy.cpp.out << CASE1
5
1 1
1
2 1
1 2
3 1
1 2 1
4 2
1 4 3 1
5 2
5 1 2 4 3
CASE1
)"
if [ "$v" = "1
11
110
1110
01111" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
