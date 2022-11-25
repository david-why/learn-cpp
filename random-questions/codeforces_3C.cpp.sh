#!/bin/bash
g++ -Wall -Wextra "codeforces_3C.cpp" -o "codeforces_3C.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./codeforces_3C.cpp.out << CASE1
X0X
.0.
.X.
CASE1
)"
if [ "$v" = "second" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
