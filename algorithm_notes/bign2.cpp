#ifndef _BIGN_HPP
#define _BIGN_HPP

#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <type_traits>

class bign
{
    typedef unsigned char Word;

    void _from_chars(const char *s)
    {
        neg = false;
        if (*s == '-')
        {
            neg = true;
            s++;
        }
        else if (*s == '+')
            s++;
        while (*s >= '0' && *s <= '9')
        {
            sto.push_back(*s - '0');
            s++;
        }
        std::reverse(sto.begin(), sto.end());
    }
    void _norm()
    {
        while (!sto.empty() && *(sto.rbegin()) == 0)
            sto.pop_back();
        if (sto.empty())
            neg = false;
    }
    bign _mult_digit(Word w, size_t shift) const
    {
        if (w == 0)
            return 0LL;
        bign r;
        r.sto.resize(shift);
        std::memset(r.sto.data(), 0, shift);
        Word c = 0;
        size_t s = sto.size();
        for (size_t i = 0; i < s; i++)
        {
            Word v = sto[i] * w + c;
            r.sto.push_back(v % 10);
            c = v / 10;
        }
        if (c)
            r.sto.push_back(c);
        return r;
    }
    void _incr()
    {
        size_t i = 0, s = sto.size();
        while (i < s)
        {
            Word &x = sto[i];
            if (x == 9)
            {
                x = 0;
            }
            else
            {
                x++;
                return;
            }
        }
        sto.push_back(1);
    }
    void _decr()
    {
        if (!cmp(0LL))
        {
            sto.resize(0);
            neg = false;
            return;
        }
        for (auto it = sto.begin(); it != sto.end(); it++)
        {
            if (*it == 0)
            {
                (*it) = 9;
            }
            else
            {
                (*it)--;
                return;
            }
        }
    }

public:
    bool neg;
    std::vector<Word> sto; // little-endian

    bign(long long val = 0) : sto()
    {
        if (val < 0)
        {
            val = -val;
            neg = true;
        }
        else
            neg = false;
        while (val)
        {
            sto.push_back(val % 10);
            val /= 10;
        }
    }
    bign(const bign &x) : neg(x.neg), sto(x.sto) {}
    explicit bign(const char *s) { _from_chars(s); }
    explicit bign(const std::string &s) { _from_chars(s.c_str()); }

    long long to_llong() const
    {
        long long a = 0;
        for (auto it = sto.rbegin(); it != sto.rend(); it++)
            a = a * 10 + *it;
        return neg ? -a : a;
    }
    explicit operator long long() const { return to_llong(); }

    std::string to_string() const
    {
        std::string s;
        if (neg)
            s += '-';
        size_t x = sto.size();
        if (!x)
            s += '0';
        for (size_t i = x; i; i--)
            s += static_cast<char>(sto[i - 1] + '0');
        return s;
    }
    explicit operator std::string() const { return to_string(); }

    int cmp(const bign &x) const
    {
        int r = neg ? -1 : 1;
        if (neg != x.neg)
            return r;
        size_t as = sto.size(), bs = x.sto.size();
        if (as > bs)
            return r;
        else if (as < bs)
            return -r;
        for (size_t i = as; i; i--)
        {
            Word a = sto[i - 1], b = x.sto[i - 1];
            if (a > b)
                return r;
            else if (a < b)
                return -r;
        }
        return 0;
    }
#if __cplusplus >= 202002L
    int operator<=>(const bign &x) const
    {
        return cmp(x);
    }
#else
    bool operator<(const bign &x) const
    {
        return cmp(x) < 0;
    }
    bool operator>(const bign &x) const
    {
        return cmp(x) > 0;
    }
    bool operator==(const bign &x) const
    {
        return cmp(x) == 0;
    }
    bool operator!=(const bign &x) const
    {
        return cmp(x) != 0;
    }
    bool operator<=(const bign &x) const
    {
        return cmp(x) <= 0;
    }
    bool operator>=(const bign &x) const
    {
        return cmp(x) >= 0;
    }
#endif

    bign &operator++()
    {
        if (neg)
            _decr();
        else
            _incr();
        return *this;
    }
    bign operator++(int)
    {
        bign t = *this;
        ++*this;
        return t;
    }
    bign &operator--()
    {
        if (neg)
            _incr();
        else
            _decr();
        return *this;
    }
    bign operator--(int)
    {
        bign t = *this;
        --*this;
        return t;
    }

    bign operator+(const bign &x) const
    {
        if (neg)
        {
            if (x.neg)
                return -((-*this) + (-x));
            return x - (-*this);
        }
        if (x.neg)
            return *this - (-x);
        bign r;
        Word c = 0;
        size_t al = sto.size(), bl = x.sto.size();
        for (size_t i = 0; i < al || i < bl; i++)
        {
            Word t = c;
            if (i < al)
                t += sto[i];
            if (i < bl)
                t += x.sto[i];
            r.sto.push_back(t % 10);
            c = t / 10;
        }
        if (c)
            r.sto.push_back(c);
        return r;
    }
    bign operator-(const bign &x) const
    {
        if (neg)
        {
            if (x.neg)
                return (-x) - (-*this);
            return -(x + (-*this));
        }
        if (x.neg)
            return *this + (-x);
        switch (cmp(x))
        {
        case -1:
            return -(x - *this);
        case 0:
            return 0LL;
        }
        bign r;
        Word c = 0;
        size_t al = sto.size(), bl = x.sto.size();
        for (size_t i = 0; i < al || i < bl; i++)
        {
            Word nc = 0;
            Word ax = 0, bx = 0;
            if (i < al)
                ax = sto[i];
            if (i < bl)
                bx = x.sto[i];
            if (ax < bx + c)
            {
                nc = 1;
                ax += 10;
            }
            r.sto.push_back(ax - bx - c);
            c = nc;
        }
        r._norm();
        size_t rl = r.sto.size();
        while (rl && *(r.sto.rbegin()) == 0)
        {
            rl--;
            r.sto.pop_back();
        }
        return r;
    }
    bign operator-() const
    {
        bign r(*this);
        r.neg = !r.neg;
        return r;
    }
    bign operator*(const bign &x) const
    {
        if (!cmp(0LL))
            return 0LL;
        bign r;
        size_t as = sto.size(), bs = x.sto.size();
        if (as < bs)
            return x * *this;
        for (size_t i = 0; i < bs; i++)
            r = r + _mult_digit(x.sto[i], i);
        return neg == x.neg ? r : -r;
    }
    std::pair<bign, bign> div(const bign &x) const
    {
        if (neg)
        {
            if (x.neg)
                return (-*this).div(-x);
            std::pair<bign, bign> a = (-*this).div(x);
            a.first = -a.first;
            a.second = -a.second;
            a.first._norm();
            a.second._norm();
            return a;
        }
        if (x.neg)
        {
            std::pair<bign, bign> a = div(-x);
            a.first = -a.first;
            a.second = -a.second;
            a.first._norm();
            a.second._norm();
            return a;
        }
        if (cmp(x) < 0)
            return std::make_pair(bign(0LL), x);
        if (cmp(x) == 0)
            return std::make_pair(bign(1LL), bign(0LL));
        bign r, dd;
        auto it = sto.rbegin();
        size_t i = sto.size();
        r.sto.resize(i);
        for (;; it++)
        {
            Word &xt = r.sto[i--];
            while (dd >= x)
            {
                dd = dd - x;
                xt++;
            }
            if (it == sto.rend())
                break;
            dd.sto.insert(dd.sto.begin(), *it);
        }
        r._norm();
        dd._norm();
        return std::make_pair(r, dd);
    }
    bign operator/(const bign &x) const { return div(x).first; }
    bign operator%(const bign &x) const { return div(x).second; }

    bign &operator+=(const bign &x) { return *this = *this + x; }
    bign &operator-=(const bign &x) { return *this = *this - x; }
    bign &operator*=(const bign &x) { return *this = *this * x; }
    bign &operator/=(const bign &x) { return *this = *this / x; }
    bign &operator%=(const bign &x) { return *this = *this % x; }

    bign pow(const bign &x) const
    {
        bign r(1LL);
        for (bign i = 0; i < x; ++i)
            r *= x;
        return r;
    }
};
bign operator""_B(unsigned long long n) { return bign(n); }

namespace std
{
    string to_string(const bign &val) { return static_cast<string>(val); }
}

template <typename T>
T gcd(T a, T b)
{
    while (b)
    {
        T t = a % b;
        a = b;
        b = t;
    }
    return a;
}

template <typename T>
T lcm(T a, T b)
{
    return a * b / gcd<T>(a, b);
}

template <typename T>
class fraction
{
    bool neg;
    T n, d;

public:
    fraction() : n(0), d(1), neg(false) {}
    fraction(T n, T d) : n(n < 0 ? -n : n), d(d < 0 ? -d : d), neg((n < 0) != (d < 0)) {}
    fraction(const fraction &f) : n(f.n), d(f.d), neg(f.neg) {}

    std::string to_string() const
    {
        return std::to_string(n) + '/' + std::to_string(d);
    }
    explicit operator std::string() const
    {
        return to_string();
    }

    void simplify()
    {
        neg = (n < 0) != (d < 0);
        n = n < 0 ? -n : n;
        d = d < 0 ? -d : d;
        T g = gcd(n, d);
        n /= g;
        d /= g;
        if (n == 0)
            d = 1;
    }

    fraction operator+(const fraction &x) const
    {
        T g = lcm(d, x.d);

        fraction r;
        r.n = n * g / d + x.n * g / x.d;
        r.d = g;
        r.simplify();
        return r;
    }
    fraction operator-(const fraction &x)
};

template <typename T>
struct __bign_types : public std::false_type
{
};

template <>
struct __bign_types<bign> : public std::true_type
{
};

template <typename Tp>
struct __bign_types<fraction<Tp>> : public std::true_type
{
};


template<typename T>
constexpr bool __bign_types_v = __bign_types<T>::value;

namespace std
{
    
    template <typename T>
    enable_if_t<__bign_types_v<T>, string> to_string(const T &val) { return static_cast<string>(val); }
}

std::ostream &operator<<(std::ostream &out, const bign &n)
{
    return out << static_cast<std::string>(n);
}
std::istream &operator>>(std::istream &in, bign &n)
{
    std::string s;
    in >> s;
    n = static_cast<bign>(s);
    return in;
}

#endif