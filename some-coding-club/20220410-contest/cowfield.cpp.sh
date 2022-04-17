#!/bin/bash
g++ -Wall -Wextra "cowfield.cpp" -o "cowfield.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./cowfield.cpp.out << CASE1
5 5 3
1 3 5
1 2
2 3
3 4
3 5
2 4
CASE1
)"
if [ "$v" = "3" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./cowfield.cpp.out << CASE2
5 4 2
2 4
1 2
2 3
3 4
4 5
CASE2
)"
if [ "$v" = "3" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
