#include <exception>
#include <string>
#ifndef BIGN_DIGITS
#define BIGN_DIGITS 100
#endif
/**
 * Big numbers calculation/initiation failure.
 */
struct OverflowException : public std::exception
{
    const char *what() const throw();
};
/**
 * Divide by zero.
 */
struct DivideByZeroException : public std::exception
{
    const char *what() const throw();
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
    divans(_QUOT quot, _R r);
};
template <typename T>
T gcd(T a, T b);
template <typename T>
T lcm(T a, T b);
/**
 * Fraction structure.
 * @tparam T The type to use as numerator and denominator. ONLY USE @c bign
 * HERE!
 */
template <typename T>
struct fraction
{
    T n, d;
    fraction(T n, T d);
    fraction();
    void simplify();
    static fraction fromNum(T n);
    static fraction<T> add(fraction<T> a, fraction<T> b);
};
struct bign
{
    short n[BIGN_DIGITS];
    long long l;
    bign(short *n, long long l);
    bign(long long n);
    bign(long n);
    bign(int n);
    bign(short n);
    bign(const char *str);
    bign(char *str);
    bign();
    bign &operator=(divans<bign, long long> a);
    bign &operator=(divans<bign, bign> a);
    char *toChars();
    std::string toString();
    void pow10(long long n);
    static bign fromChars(char *str);
    static bign fromString(std::string str);
    static int cmp(bign a, bign b);
    static bign add(bign a, bign b);
    static bign sub(bign a, bign b);
    static bign multi(bign a, long long b);
    static bign multi(bign a, bign b);
    static divans<bign, long long> div(bign a, long long b);
    static divans<bign, bign> div(bign a, bign b);
    static fraction<bign> divFrac(bign a, bign b);
    static long long modulo(bign a, long long b);
    static bign convert(divans<bign, long long> a);
    static bign convert(divans<bign, bign> a);
};
bign operator"" _B(unsigned long long i);
/**
 * Big number calculations.
 */
bign operator+(bign a, bign b);
bign operator-(bign a, bign b);
bign operator-(bign a);
bign operator*(bign a, bign b);
divans<bign, bign> operator/(bign a, bign b);
divans<bign, long long> operator/(bign a, long long b);
bign operator%(bign a, bign b);
long long operator%(bign a, long long b);
/**
 * Compare two big numbers.
 */
bool operator<(bign a, bign b);
bool operator<=(bign a, bign b);
bool operator>(bign a, bign b);
bool operator>=(bign a, bign b);
bool operator==(bign a, bign b);
bool operator!=(bign a, bign b);
/**
 * Big number I/O.
 */
std::ostream &operator<<(std::ostream &out, bign n);
std::istream &operator>>(std::istream &in, bign &n);
/**
 * Fraction output.
 */
template <typename T> std::ostream &operator<<(std::ostream &out, fraction<T> f);
//std::ostream &operator<<(std::ostream &out, fraction<int> f);
//std::ostream &operator<<(std::ostream &out, fraction<long> f);
//std::ostream &operator<<(std::ostream &out, fraction<long long> f);
//std::ostream &operator<<(std::ostream &out, fraction<float> f);
//std::ostream &operator<<(std::ostream &out, fraction<double> f);
//std::ostream &operator<<(std::ostream &out, fraction<long double> f);
//std::ostream &operator<<(std::ostream &out, fraction<bign> f);
