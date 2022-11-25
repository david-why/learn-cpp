// https://www.luogu.com.cn/problem/P1617?contestId=85850
// Luogu P1617 爱与愁的一千个伤心的理由
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string N[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string T[] = {"", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string X[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
int main()
{
    int i;
    cin >> i;
    int j = i;
    vector<string> p;
    bool a = false;
    if (i > 999)
        p.push_back(N[i / 1000] + " thousand"), i %= 1000;
    if (i > 99)
        p.push_back(N[i / 100] + " hundred"), i %= 100;
    else if (j > 999)
        a = true;
    if (i > 9)
    {
        if (a)
            p.push_back("and"), a = false;
        if (i < 20)
            p.push_back(X[i - 10]), i = 0;
        else
            p.push_back(T[i / 10]), i %= 10;
    }
    else if (j > 99)
        a = true;
    if (i)
    {
        if (a)
            p.push_back("and");
        p.push_back(N[i]);
    }

    if (p.empty())
        cout << "zero";
    else
        for (string &s : p)
            cout << s << " ";
    cout << endl;

    return 0;
}
