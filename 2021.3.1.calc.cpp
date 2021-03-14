#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int main()
{
    char s[201];
    cin.getline(s, 200);
    stringstream ss(s);
    string p;
    stack<string> ops;
    queue<string> st;
    while (ss >> p)
    {
        if (p == "+" || p == "-")
        {
            if (!ops.empty() && (ops.top() == "+" || ops.top() == "-"))
            {
                st.push(ops.top());
                ops.pop();
            }
            ops.push(p);
        }
        else if (p == "*" || p == "/")
        {
            if (!ops.empty() && (ops.top() == "*" || ops.top() == "/"))
            {
                st.push(ops.top());
                ops.pop();
            }
            ops.push(p);
        }
        else
            st.push(p);
    }
    while (!ops.empty())
    {
        st.push(ops.top());
        ops.pop();
    }
    stack<double> nums;
    while (!st.empty())
    {
        string x = st.front();
        st.pop();
        if (x == "+")
        {
            double a = nums.top();
            nums.pop();
            double b = nums.top();
            nums.pop();
            nums.push(a + b);
        }
        else if (x == "-")
        {
            double a = nums.top();
            nums.pop();
            double b = nums.top();
            nums.pop();
            nums.push(b - a);
        }
        else if (x == "*")
        {
            double a = nums.top();
            nums.pop();
            double b = nums.top();
            nums.pop();
            nums.push(a * b);
        }
        else if (x == "/")
        {
            double a = nums.top();
            nums.pop();
            double b = nums.top();
            nums.pop();
            nums.push(b / a);
        }
        else
            nums.push(atof(x.c_str()));
    }
    cout << fixed << setprecision(2) << nums.top() << endl;
    return 0;
}
