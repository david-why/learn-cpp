#!/bin/bash
g++ -Wall -Wextra "z.cpp" -o "z.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./z.cpp.out << CASE1
5 5 3 2
1 2
2 3
3 1
1 4
4 5
4 2 1
4 1 2
CASE1
)"
if [ "$v" = "No
Yes" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
