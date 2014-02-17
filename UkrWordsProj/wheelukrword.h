#ifndef WHEELUKRWORD_H
#define WHEELUKRWORD_H

#include "ukrword.h"

class WheelUkrWord: public UkrWord
{
public:
    WheelUkrWord(QGraphicsScene * scene):
        UkrWord(scene)
    {
    }
    void draw();
};

#endif // WHEELUKRWORD_H
