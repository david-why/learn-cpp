#!/bin/bash
g++ -Wall -Wextra "codeforces_1690C.cpp" -o "codeforces_1690C.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./codeforces_1690C.cpp.out << CASE1
4
3
0 3 7
2 10 11
2
10 15
11 16
9
12 16 90 195 1456 1569 3001 5237 19275
13 199 200 260 9100 10000 10914 91066 5735533
1
0
1000000000
CASE1
)"
if [ "$v" = "2 7 1 
1 1 
1 183 1 60 7644 900 914 80152 5644467 
1000000000" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
