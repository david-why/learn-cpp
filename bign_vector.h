#include <string>
#include <vector>
#include <utility>
template <typename T>
T gcd(T, T);
template <typename T>
T lcm(T, T);
/**
 * Fraction structure.
 */
class bign
{
    std::vector<short> n;
    bool neg;

public:
    bign(long long);
    bign(std::string);
    bign(std::pair<bign, bign>);
    bign();
    operator std::string();
    bool operator<(bign);
    bool operator==(bign);
    bign &operator<<(unsigned long long);
    bign &operator>>(unsigned long long);
    bign operator+(bign);
    bign &operator+=(bign);
    bign operator-(bign);
    bign &operator-=(bign);
    bign operator-();
    //bign &operator*(bign);
    //bign &operator/(bign);
    //bign &operator%(bign);
};
//bign operator"" _B(unsigned long long);
std::ostream &operator<<(std::ostream &, bign);
//std::istream &operator>>(std::istream &, bign &);
/*class fraction
{
    bign n, d;

public:
    fraction(bign = 0, bign = 1);
    void simplify();
    bool operator<(fraction);
    bool operator==(fraction);
    fraction &operator+(fraction);
    fraction &operator-(fraction);
    fraction &operator*(fraction);
    fraction &operator/(fraction);
};*/
//std::ostream &operator<<(std::ostream &, fraction);
