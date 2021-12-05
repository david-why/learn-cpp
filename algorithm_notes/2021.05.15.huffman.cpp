#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

struct HuffmanNode
{
    unsigned char c;
    int a;
    HuffmanNode *left = nullptr, *right = nullptr;
};

HuffmanNode *chars[256];

bitset<8> toBits(char c)
{
    return bitset<8>(c);
}

char toChar(bitset<8> bits)
{
    return (char)stoi(bits.to_string(), nullptr, 2);
}

int main()
{
    for (unsigned char c = 0; c < 255; c++)
    {
        chars[c] = new HuffmanNode();
        chars[c]->c = c;
        chars[c]->a = 0;
    }
    while (1)
    {
        char x;
        cin.read(&x, 1);
        if (cin.eof())
            break;
        cout << toBits(x) << endl;
    }
    return 0;
}
