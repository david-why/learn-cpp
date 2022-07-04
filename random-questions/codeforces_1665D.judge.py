import os
import sys
from math import gcd
from subprocess import PIPE, Popen

print('Compiling')
c = os.system('g++ -Wall -Wextra codeforces_1665D.cpp -o codeforces_1665D.out')
if c:
    sys.exit(c)

print('Testing')

TESTCASES = [4, 1000000000]

p = Popen('./codeforces_1665D.out', stdin=PIPE, stdout=PIPE)
p.stdin.write(b'%d\n' % len(TESTCASES))
p.stdin.flush()
for t in TESTCASES:
    print('TESTCASE:', t)
    for i in range(31):
        l = p.stdout.readline().split()
        if l[0] == b'?':
            a, b = map(int, l[1:])
            if a == b:
                exit('Wrong answer: a cannot be equal to b')
            if a > 2e9 or a < 1:
                exit('Wrong answer: a is out of range (%d)' % a)
            if b > 2e9 or b < 1:
                exit('Wrong answer: b is out of range (%d)' % b)
            p.stdin.write(b'%d\n' % gcd(t + a, t + b))
            p.stdin.flush()
        elif l[0] == b'!':
            x = int(l[1])
            if x != t:
                exit('Wrong answer: expected %d, got %d' % (t, x))
            else:
                print('AC on %d' % t)
                break
        else:
            exit('Wrong answer: unknown operation %r' % l[0])
    else:
        exit('Wrong answer: too many guesses')
print('Accepted')
