#!/bin/bash
g++ -Wall -Wextra "mark.cpp" -o "mark.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./mark.cpp.out << CASE1
3
3 6
1 3 9 10 12 16
3 1
2 5 2 2 2 5
1 2
8 6
CASE1
)"
if [ "$v" = "YES
NO
YES" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
