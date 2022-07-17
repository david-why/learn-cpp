#!/bin/bash
g++ -Wall -Wextra "tree.cpp" -o "tree.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./tree.cpp.out << CASE1
10
1 106465
4 1
1 317721
1 460929
1 644985
1 84185
1 89851
6 81968
1 492737
5 493598
CASE1
)"
if [ "$v" = "106465
84185
492737" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
