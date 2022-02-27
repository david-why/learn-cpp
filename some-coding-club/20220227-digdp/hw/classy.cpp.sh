#!/bin/bash
g++ -Wall -Wextra "classy.cpp" -o "classy.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./classy.cpp.out << CASE1
4
1 1000
1024 1024
65536 65536
999999 1000001
CASE1
)"
if [ "$v" = "1000
1
0
2" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
