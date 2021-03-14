#include <iostream>
#include "bign.cpp"

using namespace std;

int main()
{
    cout << "bign max digits: " << __BIGN_DIGITS << endl;
    cout << "a = bign(2)" << endl;
    bign a = bign(2);
    cout << "a + 2 = " << a + 2 << "\n"
         << "a - 2 = " << a - 2 << "\n"
         << "a * 2 = " << a * 2 << "\n"
         << "a / 2 = " << (a / 2).quot << "..." << (a / 2).r << endl;
    cout << "b = bign(\"5\")" << endl;
    bign b = bign("5");
    cout << "b + 2 = " << b + 2 << "\n"
         << "b - 2 = " << b - 2 << "\n"
         << "b * 2 = " << b * 2 << "\n"
         << "b / 2 = " << (b / 2).quot << "..." << (b / 2).r << endl;

    cout << "b + a = " << b + a << "\n"
         << "b - a = " << b - a << "\n"
         << "b * a = " << b * a << "\n"
         << "b / a = " << (b / a).quot << "..." << (b / a).r << "\n"
         << "b / a (FRAC) = " << bign::divFrac(b, a) << endl;
    bign c;
    cout << "Input BIGN as c: " << flush;
    cin >> c;
    cout << "c + 2 = " << c + 2 << "\n"
         << "c - 2 = " << c - 2 << "\n"
         << "c * 2 = " << c * 2 << "\n"
         << "c / 2 = " << (c / 2).quot << "..." << (c / 2).r << endl;
    cout << endl;
    cout << "f = fraction<bign>(bign(10), bign(100))" << endl;
    fraction<bign> f = fraction<bign>(bign(10), bign(100));
    cout << "f = " << f << endl;
    cout << "f.simplify()" << endl;
    f.simplify();
    cout << "f = " << f << endl;
    return 0;
}
