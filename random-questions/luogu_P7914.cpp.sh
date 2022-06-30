#!/bin/bash
g++ -Wall -Wextra "luogu_P7914.cpp" -o "luogu_P7914.cpp.out" || exit $?
ac=1
echo 'Running testcase 1'
v="$(time -p ./luogu_P7914.cpp.out << CASE1
7 3
(*??*??

CASE1
)"
if [ "$v" = "5
" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 2'
v="$(time -p ./luogu_P7914.cpp.out << CASE2
10 2
???(*??(?)

CASE2
)"
if [ "$v" = "19
" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 3'
v="$(time -p ./luogu_P7914.cpp.out << CASE3
见附件中的 bracket/bracket3.in
CASE3
)"
if [ "$v" = "见附件中的 bracket/bracket3.ans" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
echo 'Running testcase 4'
v="$(time -p ./luogu_P7914.cpp.out << CASE4
见附件中的 bracket/bracket4.in
CASE4
)"
if [ "$v" = "见附件中的 bracket/bracket4.ans" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi
