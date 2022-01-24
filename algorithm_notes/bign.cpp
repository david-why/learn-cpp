#ifndef __BIGN_IMPORTED
#define __BIGN_IMPORTED 1

#include <cstring>
#include <exception>
#include <iostream>
#include <string>
#include <numeric>
#include "bign.h"

#ifndef __abs
#define __abs(a) (a >= 0 ? a : -a)
#endif

const char *OverflowException::what() const throw()
{
    return "Big number calculations/initiation overflow";
}

const char *DivideByZeroException::what() const throw()
{
    return "Cannot divide by zero";
}

template <typename _QUOT, typename _R>
divans<_QUOT, _R>::divans(_QUOT quot, _R r) : quot(quot), r(r) {}

template <typename T>
T gcd(T a, T b)
{
    // std::cout << "gcd(" << a << ", " << b << ")" << (b == 0) << std::endl;
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

template <typename T>
T lcm(T a, T b)
{
    T t = a / gcd(a, b) * b;
    return t;
}

template <typename T>
fraction<T>::fraction(T n, T d) : n(n), d(d) {}

template <typename T>
fraction<T>::fraction() : n(0), d(0) {}

template <typename T>
void fraction<T>::simplify()
{
    if (this->d < 0)
    {
        this->n = -this->n;
        this->d = -this->d;
    }
    if (this->n == 0)
        this->d = 1;
    T g = gcd<T>(__abs(this->n), __abs(this->d));
    this->n = T::convert(this->n / g);
    this->d = T::convert(this->d / g);
}

template <typename T>
fraction<T> fraction<T>::fromNum(T n)
{
    fraction<T> f = fraction(n, 1);
    return f;
}

template <typename T>
fraction<T> fraction<T>::add(fraction<T> a, fraction<T> b)
{
    fraction<T> ret;
    ret.n = a.n * b.d + b.n * a.d;
    ret.d = a.d * b.d;
    ret.simplify();
    return ret;
}

bign::bign(short *n, long long l)
{
    if (l > BIGN_DIGITS)
        throw OverflowException();
    memcpy(this->n, n, sizeof(short) * l);
    memset(this->n + l, 0, sizeof(short) * (BIGN_DIGITS - l));
    this->l = l;
}
bign::bign(long long n)
{
    this->l = 0;
    while (n)
    {
        this->n[(this->l)++] = n % 10;
        n /= 10;
    }
    memset(this->n + l, 0, sizeof(short) * (BIGN_DIGITS - this->l));
}
bign::bign(long n)
{
    this->l = 0;
    while (n)
    {
        this->n[(this->l)++] = n % 10;
        n /= 10;
    }
    memset(this->n + l, 0, sizeof(short) * (BIGN_DIGITS - this->l));
}
bign::bign(int n)
{
    this->l = 0;
    while (n)
    {
        this->n[(this->l)++] = n % 10;
        n /= 10;
    }
    memset(this->n + l, 0, sizeof(short) * (BIGN_DIGITS - this->l));
}
bign::bign(short n)
{
    this->l = 0;
    while (n)
    {
        this->n[(this->l)++] = n % 10;
        n /= 10;
    }
    memset(this->n + l, 0, sizeof(short) * (BIGN_DIGITS - this->l));
}
bign::bign(const char *str)
{
    this->l = strlen(str);
    for (long long i = 0; i < this->l; i++)
    {
        this->n[i] = str[this->l - i - 1] - '0';
    }
    memset(this->n + l, 0, sizeof(short) * (BIGN_DIGITS - this->l));
}
bign::bign(char *str)
{
    this->l = strlen(str);
    for (long long i = 0; i < this->l; i++)
    {
        this->n[i] = str[this->l - i - 1] - '0';
    }
    memset(this->n + l, 0, sizeof(short) * (BIGN_DIGITS - this->l));
}
bign::bign()
{
    memset(this->n, 0, sizeof(this->n));
    this->l = 0;
}

bign &bign::operator=(divans<bign, long long> a)
{
    memcpy(n, a.quot.n, a.quot.l);
    l = a.quot.l;
    return *this;
}
bign &bign::operator=(divans<bign, bign> a)
{
    memcpy(n, a.quot.n, a.quot.l);
    l = a.quot.l;
    return *this;
}

char *bign::toChars()
{
    char *ret = new char[this->l + 2];
    for (long long i = 0; i < this->l; i++)
    {
        ret[this->l - i - 1] = this->n[i] + '0';
    }
    ret[this->l] = '\0';
    if (!l)
    {
        ret[0] = '0';
        ret[1] = '\0';
    }
    return ret;
}
std::string bign::toString()
{
    std::string ret = toChars();
    /*for (long long i = 0; i < this->l; i++)
    {
        ret[this->l - i - 1] = this->n[i] + '0';
    }
    ret[this->l] = '\0';*/
    return ret;
}
void bign::pow10(long long n)
{
    if (this->l + n > BIGN_DIGITS)
        throw OverflowException();
    if (n == 0)
        return;
    if (n > 0)
    {
        memmove(this->n + n, this->n, sizeof(short) * this->l);
        memset(this->n, 0, sizeof(short) * n);
        this->l += n;
    }
    else if (this->l <= -n)
    {
        this->l = 1;
        this->n[0] = 0;
    }
    else
    {
        this->l += n;
        memmove(this->n, this->n - n, sizeof(short) * this->l);
    }
}

bign bign::fromChars(char *str)
{
    bign res;
    res.l = strlen(str);
    for (long long i = 0; i < res.l; i++)
    {
        res.n[i] = str[res.l - i - 1] - '0';
    }
    return res;
}
bign bign::fromString(std::string str)
{
    bign res;
    res.l = str.length();
    for (long long i = 0; i < res.l; i++)
    {
        res.n[i] = str[res.l - i - 1] - '0';
    }
    return res;
}
int bign::cmp(bign a, bign b)
{
    //std::cout << a << " " << b << std::endl;
    if (a.l > b.l)
        return 1;
    else if (a.l < b.l)
        return -1;
    for (long long i = a.l - 1; i >= 0; i--)
    {
        if (a.n[i] > b.n[i])
            return 1;
        else if (a.n[i] < b.n[i])
            return -1;
    }
    return 0;
}
bign bign::add(bign a, bign b)
{
    bign r;
    short c = 0;
    for (long long i = 0; i < a.l || i < b.l; i++)
    {
        short t = a.n[i] + b.n[i] + c;
        r.n[r.l++] = t % 10;
        c = t / 10;
    }
    if (c != 0)
        r.n[r.l++] = c;
    return r;
}
bign bign::sub(bign a, bign b)
{
    bign t;
    switch (bign::cmp(a, b))
    {
    case -1:
        t = a;
        a = b;
        b = t;
        break;
    case 0:
        t = bign(0LL);
        return t;
    }
    bign r;
    for (long long i = 0; i < a.l || i < b.l; i++)
    {
        if (a.n[i] < b.n[i])
        {
            a.n[i + 1]--;
            a.n[i] += 10;
        }
        r.n[r.l++] = a.n[i] - b.n[i];
    }
    while (r.l >= 2 && r.n[r.l - 1] == 0)
        r.l--;
    return r;
}
bign bign::multi(bign a, long long b)
{
    if (a == 0 || b == 0)
        return bign(0);
    bign r;
    short c = 0;
    for (long long i = 0; i < a.l; i++)
    {
        int t = a.n[i] * b + c;
        r.n[r.l++] = t % 10;
        c = t / 10;
    }
    while (c != 0)
    {
        r.n[r.l++] = c % 10;
        c /= 10;
    }
    return r;
}
bign bign::multi(bign a, bign b)
{
    if (a == 0 || b == 0)
        return bign(0);
    bign res;
    for (long long i = 0; i < b.l; i++)
    {
        bign t = bign::multi(a, b.n[i]);
        for (long long j = 0; j < i; j++)
        {
            t = bign::multi(t, 10);
        }
        res = bign::add(res, t);
    }
    return res;
}
divans<bign, long long> bign::div(bign a, long long b)
{
    if (b == 0)
        throw DivideByZeroException();
    bign r;
    r.l = a.l;
    long long rem = 0;
    for (long long i = a.l - 1; i >= 0; i--)
    {
        rem = rem * 10 + a.n[i];
        if (rem < b)
            r.n[i] = 0;
        else
        {
            r.n[i] = rem / b;
            rem = rem % b;
        }
    }
    while (r.l >= 2 && r.n[r.l - 1] == 0)
    {
        r.l--;
    }
    divans<bign, long long> ans = divans<bign, long long>(r, rem);
    return ans;
}
divans<bign, bign> bign::div(bign a, bign b)
{
    // std::cout << "DIV" << std::endl;
    bign r = bign(0LL);
    while (bign::cmp(a, b) > -1)
    {
        bign t = b;
        long long l = a.l - b.l;
        t.pow10(l);
        if (bign::cmp(a, t) == -1)
        {
            l--;
            t.pow10(-1);
        }
        bign e = 0;
        while (bign::cmp(a, t) > -1)
        {
            a = bign::sub(a, t);
            e = bign::add(e, 1);
        }
        e.pow10(l);
        //std::cout << "-- " << a << " " << b << " " << t << " " << l << " " << e << std::endl;
        r = bign::add(r, e);
    }
    divans<bign, bign> ans = divans<bign, bign>(r, a);
    return ans;
}
fraction<bign> bign::divFrac(bign a, bign b)
{
    fraction<bign> f = fraction<bign>(a, b);
    f.simplify();
    return f;
}
long long bign::modulo(bign a, long long b)
{
    long long r = 0;
    for (int i = a.l - 1; i >= 0; i--)
    {
        r = (r * 10 + a.n[i]) % b;
    }
    return r;
}

bign operator"" _B(unsigned long long i)
{
    return bign((long long)i);
}
bign operator"" _B(const char *s)
{
    return bign(s);
}

bign bign::convert(divans<bign, long long> a)
{
    return a.quot;
}
bign bign::convert(divans<bign, bign> a)
{
    return a.quot;
}

bign operator+(bign a, bign b)
{
    return bign::add(a, b);
}
bign operator-(bign a, bign b)
{
    return bign::sub(a, b);
}
bign operator-(bign a)
{
    return 0 - a;
}
bign operator*(bign a, bign b)
{
    return bign::multi(a, b);
}
divans<bign, bign> operator/(bign a, bign b)
{
    return bign::div(a, b);
}
divans<bign, long long> operator/(bign a, long long b)
{
    return bign::div(a, b);
}
bign operator%(bign a, bign b)
{
    return bign::div(a, b).r;
}
long long operator%(bign a, long long b)
{
    return bign::modulo(a, b);
}

bool operator<(bign a, bign b)
{
    return bign::cmp(a, b) == -1;
}
bool operator<=(bign a, bign b)
{
    return bign::cmp(a, b) != 1;
}
bool operator>(bign a, bign b)
{
    return bign::cmp(a, b) == 1;
}
bool operator>=(bign a, bign b)
{
    return bign::cmp(a, b) != -1;
}
bool operator==(bign a, bign b)
{
    return bign::cmp(a, b) == 0;
}
bool operator!=(bign a, bign b)
{
    return bign::cmp(a, b) != 0;
}

/**
 * Big number I/O.
 */
std::ostream &operator<<(std::ostream &out, bign n)
{
    char *s = n.toChars();
    out << s;
    delete[] s;
    return out;
}
std::istream &operator>>(std::istream &in, bign &n)
{
    std::string input;
    in >> input;
    n = bign::fromString(input);
    return in;
}

/**
 * Fraction output.
 */
template <typename T>
std::ostream &operator<<(std::ostream &out, fraction<T> f)
{
    out << f.n << "/" << f.d;
    return out;
}

#endif
