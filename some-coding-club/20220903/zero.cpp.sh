#!/bin/bash
g++ -Wall -Wextra "zero.cpp" -o "zero.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./zero.cpp.out << CASE1
5
1 1
1
1 2
1 -1
1 4
1 -1 1 -1
3 4
1 -1 -1 -1
-1 1 1 -1
1 1 1 -1
3 4
1 -1 1 1
-1 1 -1 1
1 -1 1 1
CASE1
)"
if [ "$v" = "NO
YES
YES
YES
NO" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
