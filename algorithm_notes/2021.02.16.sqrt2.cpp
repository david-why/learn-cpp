#include <iostream>
#include <iomanip>

using namespace std;

bool equal(const double a, const double b) {
    // return (a > b && a - b < 0.0000000000002) || (a < b && b - a < 0.0000000000002) || (a == b);
    return a == b;
}

double sqrt(double n, double left, double right)
{
    double mid = 1, pow = 1;
    while (1) {
        if (pow < n) left = mid;
        else right = mid;
        mid = (left + right) / (double)(2.0);
        if (mid == left || mid == right) return mid;
        pow = mid * mid;
    }
    return mid;
}

int main()
{
    cout << fixed << setprecision(40) << sqrt(2.0, 0.0, 2.0) << endl;
}
