#!/bin/bash
g++ -Wall -Wextra "jongmah.cpp" -o "jongmah.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./jongmah.cpp.out << CASE1
10 6
2 3 3 3 4 4 4 5 5 6
CASE1
)"
if [ "$v" = "3" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./jongmah.cpp.out << CASE2
12 6
1 5 3 3 3 4 3 5 3 2 3 3
CASE2
)"
if [ "$v" = "3" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./jongmah.cpp.out << CASE3
13 5
1 1 5 1 2 3 3 2 4 2 3 4 5
CASE3
)"
if [ "$v" = "4" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
