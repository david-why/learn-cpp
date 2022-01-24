#ifndef _BIGN_H
#define _BIGN_H

#include <vector>
#include <string>

class bign
{
    typedef unsigned char Word;

    void _from_chars();
    void _norm();
    bign _mult_digit(Word w, size_t shift) const;
    void _incr();
    void _decr();

public:
    bool neg;
    std::vector<Word> sto; // little-endian
};

#endif