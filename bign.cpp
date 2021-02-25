#include <cstring>
#include <exception>
#include <iostream>
#include <string>
#include <numeric>

#ifndef __BIGN_DIGITS
#define __BIGN_DIGITS 100
#endif

#ifndef __abs
#define __abs(a) (a >= 0 ? a : -a)
#endif

typedef long long LL;
typedef long double LD;

/**
 * Big numbers calculation/initiation failure.
 */
struct OverflowError : public std::exception
{
    const char *what() const throw()
    {
        return "Big number calculations/initiation overflow";
    }
};

/**
 * Division answer structure.
 * @tparam _QUOT The type to use as the quotient. ONLY USE @c bign HERE!
 * @tparam _R The type to use as the remainder. ONLY USE @c bign HERE!
 */
template <typename _QUOT, typename _R>
struct divans
{
    _QUOT quot;
    _R r;
    divans(_QUOT quot, _R r) : quot(quot), r(r) {}
};

template <typename T>
T gcd(T a, T b)
{
    std::cout << "gcd(" << a << ", " << b << ")" << std::endl;
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

/**
 * Fraction structure.
 * @tparam T The type to use as numerator and denominator. ONLY USE @c bign
 * HERE!
 */
template <typename T>
struct fraction
{
    T n, d;
    fraction(T n, T d) : n(n), d(d) {}
    fraction() : n(0), d(0) {}

    void simplify()
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

    static fraction fromNum(T n)
    {
        fraction<T> f = fraction(n, 1);
        return f;
    }
    template <typename _T>
    static fraction<_T> add(fraction<_T> a, fraction<_T> b)
    {
        fraction<_T> ret;
        ret.n = a.n * b.d + b.n * a.d;
        ret.d = a.d * b.d;
        ret.simplify();
        return ret;
    }
};

/**
 * Big number structure.
 */
struct bign
{
    short n[__BIGN_DIGITS];
    LL l;

    bign(short *n, LL l)
    {
        if (l > __BIGN_DIGITS)
            throw OverflowError();
        memcpy(this->n, n, sizeof(short) * l);
        memset(this->n + l, 0, sizeof(short) * (__BIGN_DIGITS - l));
        this->l = l;
    }
    bign(LL n)
    {
        this->l = 0;
        while (n)
        {
            this->n[(this->l)++] = n % 10;
            n /= 10;
        }
        memset(this->n + l, 0, sizeof(short) * (__BIGN_DIGITS - this->l));
    }
    bign(long n)
    {
        this->l = 0;
        while (n)
        {
            this->n[(this->l)++] = n % 10;
            n /= 10;
        }
        memset(this->n + l, 0, sizeof(short) * (__BIGN_DIGITS - this->l));
    }
    bign(int n)
    {
        this->l = 0;
        while (n)
        {
            this->n[(this->l)++] = n % 10;
            n /= 10;
        }
        memset(this->n + l, 0, sizeof(short) * (__BIGN_DIGITS - this->l));
    }
    bign(short n)
    {
        this->l = 0;
        while (n)
        {
            this->n[(this->l)++] = n % 10;
            n /= 10;
        }
        memset(this->n + l, 0, sizeof(short) * (__BIGN_DIGITS - this->l));
    }
    bign(const char *str)
    {
        this->l = strlen(str);
        for (LL i = 0; i < this->l; i++)
        {
            this->n[i] = str[this->l - i - 1] - '0';
        }
        memset(this->n + l, 0, sizeof(short) * (__BIGN_DIGITS - this->l));
    }
    bign(char *str)
    {
        this->l = strlen(str);
        for (LL i = 0; i < this->l; i++)
        {
            this->n[i] = str[this->l - i - 1] - '0';
        }
        memset(this->n + l, 0, sizeof(short) * (__BIGN_DIGITS - this->l));
    }
    bign()
    {
        memset(this->n, 0, sizeof(this->n));
        this->l = 0;
    }

    bign &operator=(divans<bign, LL> a)
    {
        memcpy(n, a.quot.n, a.quot.l);
        l = a.quot.l;
        return *this;
    }
    bign &operator=(divans<bign, bign> a)
    {
        memcpy(n, a.quot.n, a.quot.l);
        l = a.quot.l;
        return *this;
    }

    char *toChars()
    {
        char *ret = new char[this->l + 1];
        for (LL i = 0; i < this->l; i++)
        {
            ret[this->l - i - 1] = this->n[i] + '0';
        }
        ret[this->l] = '\0';
        return ret;
    }
    std::string toString()
    {
        std::string ret;
        for (LL i = 0; i < this->l; i++)
        {
            ret[this->l - i - 1] = this->n[i] + '0';
        }
        ret[this->l] = '\0';
        return ret;
    }
    void pow10(LL n)
    {
        if (this->l + n > __BIGN_DIGITS)
            throw OverflowError();
        if (n == 0)
            return;
        memmove(this->n + n, this->n, sizeof(short) * this->l);
        memset(this->n, 0, sizeof(short) * n);
        this->l += n;
    }

    static bign fromChars(char *str)
    {
        bign res;
        res.l = strlen(str);
        for (LL i = 0; i < res.l; i++)
        {
            res.n[i] = str[res.l - i - 1] - '0';
        }
        return res;
    }
    static bign fromString(std::string str)
    {
        bign res;
        res.l = str.length();
        for (LL i = 0; i < res.l; i++)
        {
            res.n[i] = str[res.l - i - 1] - '0';
        }
        return res;
    }
    static int cmp(bign a, bign b)
    {
        if (a.l > b.l)
            return 1;
        else if (a.l < b.l)
            return -1;
        for (LL i = a.l - 1; i >= 0; i--)
        {
            if (a.n[i] > b.n[i])
                return 1;
            else if (a.n[i] < b.n[i])
                return -1;
        }
        return 0;
    }
    static bign add(bign a, bign b)
    {
        bign r;
        short c = 0;
        for (LL i = 0; i < a.l || i < b.l; i++)
        {
            short t = a.n[i] + b.n[i] + c;
            r.n[r.l++] = t % 10;
            c = t / 10;
        }
        if (c != 0)
            r.n[r.l++] = c;
        return r;
    }
    static bign sub(bign a, bign b)
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
        for (LL i = 0; i < a.l || i < b.l; i++)
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
    static bign multi(bign a, LL b)
    {
        bign r;
        short c = 0;
        for (LL i = 0; i < a.l; i++)
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
    static bign multi(bign a, bign b)
    {
        bign res;
        for (LL i = 0; i < b.l; i++)
        {
            bign t = bign::multi(a, b.n[i]);
            for (LL j = 0; j < i; j++)
            {
                t = bign::multi(t, 10);
            }
            res = bign::add(res, t);
        }
        return res;
    }
    static divans<bign, LL> div(bign a, LL b)
    {
        bign r;
        r.l = a.l;
        LL rem = 0;
        for (LL i = a.l - 1; i >= 0; i--)
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
        divans<bign, LL> ans = divans<bign, LL>(r, rem);
        return ans;
    }
    static divans<bign, bign> div(bign a, bign b)
    {
        std::cout << "DIV" << std::endl;
        bign r = bign(0LL);
        while (bign::cmp(a, b) > -1)
        {
            bign t = b;
            LL l = a.l - b.l;
            if (bign::cmp(a, t) == -1)
            {
                l--;
            }
            t.pow10(l);
            bign e = bign(0LL);
            while (bign::cmp(a, t) > -1)
            {
                a = bign::sub(a, t);
                e = bign::add(e, 1);
            }
            e.pow10(l);
            r = bign::add(r, e);
        }
        divans<bign, bign> ans = divans<bign, bign>(r, a);
        return ans;
    }
    static fraction<bign> divFrac(bign a, bign b)
    {
        fraction<bign> f = fraction<bign>(a, b);
        f.simplify();
        return f;
    }
    static LL modulo(bign a, LL b) {
        LL r = 0;
        for (int i = a.l - 1; i >= 0; i--) {
            r = (r * 10 + a.n[i]) % b;
        }
        return r;
    }

    static bign convert(divans<bign, LL> a)
    {
        return a.quot;
    }
    static bign convert(divans<bign, bign> a)
    {
        return a.quot;
    }
};

/**
 * Big number calculations.
 */
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
divans<bign, LL> operator/(bign a, LL b)
{
    return bign::div(a, b);
}
bign operator%(bign a, bign b)
{
    return bign::div(a, b).r;
}
LL operator%(bign a, LL b)
{
    return bign::modulo(a, b);
}

/**
 * Compare two big numbers.
 */
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
std::ostream &operator<<(std::ostream &out, fraction<int> f)
{
    out << f.n << "/" << f.d;
    return out;
}
std::ostream &operator<<(std::ostream &out, fraction<long> f)
{
    out << f.n << "/" << f.d;
    return out;
}
std::ostream &operator<<(std::ostream &out, fraction<LL> f)
{
    out << f.n << "/" << f.d;
    return out;
}
std::ostream &operator<<(std::ostream &out, fraction<float> f)
{
    out << f.n << "/" << f.d;
    return out;
}
std::ostream &operator<<(std::ostream &out, fraction<double> f)
{
    out << f.n << "/" << f.d;
    return out;
}
std::ostream &operator<<(std::ostream &out, fraction<LD> f)
{
    out << f.n << "/" << f.d;
    return out;
}
std::ostream &operator<<(std::ostream &out, fraction<bign> f)
{
    out << f.n << "/" << f.d;
    return out;
}

int main() { std::cout << gcd(bign("76857486974563674698543789576"), bign(6)) << std::endl; }
