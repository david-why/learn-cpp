#!/bin/bash
g++ -Wall -Wextra "perm.cpp" -o "perm.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./perm.cpp.out << CASE1
2
2
3
CASE1
)"
if [ "$v" = "2
1 2
3
2 1 3" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
