#!/bin/bash
g++ -Wall -Wextra "codeforces_1666L.cpp" -o "codeforces_1666L.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./codeforces_1666L.cpp.out << CASE1
5 5 1
1 2
2 3
1 4
4 3
3 5
CASE1
)"
if [ "$v" = "Possible
3
1 2 3
3
1 4 3" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./codeforces_1666L.cpp.out << CASE2
5 5 1
1 2
2 3
3 4
2 5
5 4
CASE2
)"
if [ "$v" = "Impossible" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./codeforces_1666L.cpp.out << CASE3
3 3 2
1 2
2 3
3 1
CASE3
)"
if [ "$v" = "Impossible" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
