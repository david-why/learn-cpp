#include <stdexcept>
#include <iostream>
#include "bign_vector.h"
using namespace std;

#define __abs(a) ((a) < 0 ? (a) : -(a))

// --------- gcd
template <typename T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// --------- lcm
template <typename T>
T lcm(T a, T b)
{
    T t = a / gcd(a, b) * b;
    return t;
}

// --------- bign
bign::bign(long long a)
{
    if (neg = a < 0)
        a = -a;
    while (a)
    {
        n.push_back(a % 10);
        a /= 10;
    }
}

bign::bign(string a)
{
    if (neg = a[0] == '-')
        a = a.substr(1, a.length() - 1);
    for (string::reverse_iterator it = a.rbegin(); it != a.rend(); it++)
        n.push_back(*it - '0');
}

bign::bign(pair<bign, bign> a)
{
    n = a.first.n;
    neg = a.first.neg;
}

bign::bign()
{
    neg = false;
}

bign::operator string()
{
    string ret;
    if (neg)
        ret += '-';
    if (!n.size())
        ret = "0";
    for (auto it = n.rbegin(); it != n.rend(); it++)
        ret += *it + '0';
    return ret;
}

bool bign::operator<(bign b)
{
    if (neg && !b.neg)
        return true;
    if (!neg && b.neg)
        return false;
    if (n.size() < b.n.size())
        return !neg;
    else if (n.size() > b.n.size())
        return neg;
    for (long long i = n.size() - 1; i >= 0; i--)
    {
        if (n[i] > b.n[i])
            return neg;
        else if (n[i] < b.n[i])
            return !neg;
    }
    return false;
}

bool bign::operator==(bign b)
{
    if (neg != b.neg)
        return false;
    if (n.size() != b.n.size())
        return false;
    for (long long i = n.size() - 1; i >= 0; i--)
    {
        if (n[i] > b.n[i])
            return false;
        else if (n[i] < b.n[i])
            return false;
    }
    return true;
}

bign &bign::operator<<(unsigned long long b)
{
    if (b == 0 && n.size() == 0)
        return *this;
    if (n.size() <= b)
        n.clear();
    else
        n.erase(n.begin(), n.begin() + b);
    return *this;
}

bign &bign::operator>>(unsigned long long b)
{
    if (b == 0 || n.size() == 0)
        return *this;
    n.insert(n.begin(), b, 0);
    return *this;
}

bign bign::operator+(bign b)
{
    bool negit = false;
    if (neg != b.neg)
        if (neg)
            return b - (-(*this));
        else
            return *this - (-b);
    else if (neg)
    {
        negit = true;
        neg = false;
        b.neg = false;
    }
    bign r = 0;
    short c = 0;
    for (unsigned long long i = 0; i < n.size() || i < b.n.size(); i++)
    {
        short nn = i < n.size() ? n[i] : 0;
        short bn = i < b.n.size() ? b.n[i] : 0;
        nn = nn + bn + c;
        r.n.push_back(nn % 10);
        c = nn > 9 ? 1 : 0;
    }
    if (c)
        r.n.push_back(c);
    if (negit)
        neg = true;
    return r;
}

bign &bign::operator+=(bign b)
{
    bign t = *this + b;
    n = t.n;
    return *this;
}

bign bign::operator-(bign b)
{
    if (*this == b)
        return 0;
    if (neg != b.neg)
        if (neg)
            return -(b + (-(*this)));
        else
            return b + *this;
    else if (neg)
        if (*this < b)
            return -(-(*this) - (-b));
        else
            return -b - (-(*this));
    else if (*this < b)
        return -(b - *this);
    bign r;
    for (unsigned long long i = 0; i < n.size() || i < b.n.size(); i++)
    {
        short bi = i < b.n.size() ? b.n[i] : 0;
        if (n[i] < bi)
        {
            n[i + 1]--;
            n[i] += 10;
        }
        r.n.push_back(n[i] - bi);
    }
    unsigned long long i = r.n.size();
    while (i >= 1 && r.n[i - 1] == 0)
    {
        r.n.pop_back();
        i--;
    }
    r.neg = false;
    return r;
}

bign &bign::operator-=(bign b)
{
    bign t = *this - b;
    n = t.n;
    return *this;
}

bign bign::operator-()
{
    neg = !neg;
    return *this;
}

/*/ --------- fraction
fraction::fraction(bign a, bign b) : n(a), d(b)
{
    simplify();
}

void fraction::simplify()
{
    if (d < 0)
    {
        n = -n;
        d = -d;
    }
    if (n == 0)
        d = 1;
    bign g = gcd(n, d);
    n = n / g;
    d = d / g;
}

bool fraction::operator<(fraction b)
{
    fraction c = *this - b;
    return c.n < 0;
}

bool fraction::operator==(fraction b)
{
    return n == b.n && d == b.d;
}

fraction &fraction::operator+(fraction b)
{
    bign nd = d * b.d;
    bign nn = n * b.d + b.n * d;
    n = nn;
    d = nd;
    simplify();
    return *this;
}

fraction &fraction::operator-(fraction b)
{
    bign nd = d * b.d;
    bign nn = n * b.d - b.n * d;
    n = nn;
    d = nd;
    simplify();
    return *this;
}

fraction &fraction::operator*(fraction b)
{
    n = n * b.n;
    d = d * b.d;
    simplify();
    return *this;
}

fraction &fraction::operator/(fraction b)
{
    if (b.n == 0)
        throw overflow_error("Divide by zero exception");
    n = n * b.d;
    d = d * b.n;
    simplify();
    return *this;
}*/

std::ostream &operator<<(std::ostream &out, bign b)
{
    out << (string)b;
    return out;
}

int main()
{
    bign a = 1246845;
    bign b = 234872845;
    cout << a << " " << b << endl;
    cout << a + b << " " << b + a << endl;
    cout << -a << " " << -b << endl;
    cout << a - b << endl;
    return 0;
}
