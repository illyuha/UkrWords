#ifndef WHEELUKRWORD_H
#define WHEELUKRWORD_H

#include "ukrword.h"

class WheelUkrWord: public UkrWord
{
public:
    WheelUkrWord(QGraphicsView * view):
        UkrWord(view)
    {
    }

    void draw() const;
};

#endif // WHEELUKRWORD_H
