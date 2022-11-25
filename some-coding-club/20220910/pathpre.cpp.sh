#!/bin/bash
g++ -Wall -Wextra "pathpre.cpp" -o "pathpre.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./pathpre.cpp.out << CASE1
4
9
1 5 6
4 5 1
2 9 10
4 2 1
1 2 1
2 3 3
6 4 3
8 1 3
4
1 1 100
2 1 1
3 101 1
4
1 100 1
2 1 1
3 1 101
10
1 1 4
2 3 5
2 5 1
3 4 3
3 1 5
5 3 5
5 2 1
1 3 2
6 2 1
CASE1
)"
if [ "$v" = "0 3 1 2 1 1 2 3 
0 0 3 
1 2 2 
0 1 2 1 1 2 2 1 1" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
