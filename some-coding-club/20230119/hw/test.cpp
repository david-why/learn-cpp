#include <iostream>
using namespace std;

class st
{
public:
    int x;
    st(int y) : x(y) {}
};

void test(st s)
{
    cout << s.x << endl;
};

int main()
{
    test(1);
    return 0;
}