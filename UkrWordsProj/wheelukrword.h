#ifndef WHEELUKRWORD_H
#define WHEELUKRWORD_H

#include "ukrword.h"

class WheelUkrWord: public UkrWord
{
public:
    // C++11 rules!
    using UkrWord::UkrWord;
    void draw() const;
};

#endif // WHEELUKRWORD_H
