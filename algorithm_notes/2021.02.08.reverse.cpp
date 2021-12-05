#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char s[101];
    fgets(s, 100, stdin);
    char res[51][101] = {};
    int startIndex = 0, resIndex = 0;
    bool first = false;
    for (int i = 0; i <= strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            //printf("%i %i\n", startIndex, i);
            if (first)
                memcpy(res[resIndex], s + startIndex, sizeof(char) * (i - startIndex));
            else
            {
                memcpy(res[resIndex], s, sizeof(char) * (i - startIndex));
                first = true;
            }
            resIndex++;
            startIndex = i + 1;
        }
        else if (s[i] == '\0')
        {
            //printf("%i %i\n", startIndex, i);
            memcpy(res[resIndex], s + startIndex, sizeof(char) * (i - startIndex - 1));
            resIndex++;
        }
    }
    for (int i = resIndex - 1; i >= 0; i--)
    {
        printf("%s", res[i]);
        if (i != 0)
            printf(" ");
    }
    puts("");
    return 0;
}
