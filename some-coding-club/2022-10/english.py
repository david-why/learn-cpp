N = ['', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
T = ['', 'ten', 'twenty', 'thirty', 'fourty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']
X = ['ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']

i = int(input())
j = i
p = []
a = False

if i > 999:
    p.append(N[i//1000] + ' thousand')
    i %= 1000
if i > 99:
    p.append(N[i//100] + ' hundred')
    i %= 100
elif j > 999:
    a = True
if i > 9:
    if a:
        p.append('and')
        a = False
    if i < 20:
        p.append(X[i-10])
        i = 0
    else:
        p.append(T[i//10])
        i %= 10
elif j > 99:
    a = True
if i:
    if a:
        p.append('and')
    p.append(N[i])

print(*(p or ['zero']))
