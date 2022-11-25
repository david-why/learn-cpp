#!/bin/bash
g++ -Wall -Wextra "codeforces_1679D.cpp" -o "codeforces_1679D.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./codeforces_1679D.cpp.out << CASE1
6 7 4
1 10 2 3 4 5
1 2
1 3
3 4
4 5
5 6
6 2
2 5
CASE1
)"
if [ "$v" = "4" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./codeforces_1679D.cpp.out << CASE2
6 7 100
1 10 2 3 4 5
1 2
1 3
3 4
4 5
5 6
6 2
2 5
CASE2
)"
if [ "$v" = "10" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./codeforces_1679D.cpp.out << CASE3
2 1 5
1 1
1 2
CASE3
)"
if [ "$v" = "-1" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 4'
v="$(time -p ./codeforces_1679D.cpp.out << CASE4
1 0 1
1000000000
CASE4
)"
if [ "$v" = "1000000000" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
