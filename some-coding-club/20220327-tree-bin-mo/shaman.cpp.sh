#!/bin/bash
g++ -Wall -Wextra "shaman.cpp" -o "shaman.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./shaman.cpp.out << CASE1
2 1
1 3
1 2
CASE1
)"
if [ "$v" = "-1" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./shaman.cpp.out << CASE2
3 4
2 2 3
1 1
1 2
2 4
3 6
CASE2
)"
if [ "$v" = "3
2
-1
3" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./shaman.cpp.out << CASE3
10 7
0 3 1 4 6 2 7 8 10 1
2 5
1 3
9 36
4 10
4 9
1 2
1 0
CASE3
)"
if [ "$v" = "1
-1
9
-1
4
-1
1" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
