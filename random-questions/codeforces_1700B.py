p = int(input())
for _ in range(p):
    n = int(input())
    s = input()
    v = int(s)
    if s[0] == '9':
        print(int('1' * (n + 1)) - v)
    else:
        print(int('9' * n) - v)
