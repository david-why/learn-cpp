#!/bin/bash
g++ -Wall -Wextra "codeforces_1659B.cpp" -o "codeforces_1659B.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./codeforces_1659B.cpp.out << CASE1
6
6 3
100001
6 4
100011
6 0
000000
6 1
111001
6 11
101100
6 12
001110
CASE1
)"
if [ "$v" = "111110
1 0 0 2 0 0 
111110
0 1 1 1 0 1 
000000
0 0 0 0 0 0 
100110
1 0 0 0 0 0 
111111
1 2 1 3 0 4 
111110
1 1 4 2 0 4" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
