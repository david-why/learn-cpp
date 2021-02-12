#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[101];
    cin.getline(s, 100);
    for (int i = strlen(s); i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            for (int c = i + 1; s[c] != ' ' && s[c] != '\0'; c++)
            {
                cout << s[c];
            }
            cout << " ";
        }
    }
    for (int j = 0; s[j] != ' ' && s[j] != '\0'; j++) {
        cout << s[j];
    }
    cout << endl;
    return 0;
}
