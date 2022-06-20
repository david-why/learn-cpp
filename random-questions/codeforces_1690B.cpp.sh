#!/bin/bash
g++ -Wall -Wextra "codeforces_1690B.cpp" -o "codeforces_1690B.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./codeforces_1690B.cpp.out << CASE1
6
4
3 5 4 1
1 3 2 0
3
1 2 1
0 1 0
4
5 3 7 2
1 1 1 1
5
1 2 3 4 5
1 2 3 4 6
1
8
0
1
4
6
CASE1
)"
if [ "$v" = "YES
YES
NO
NO
YES
NO" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
