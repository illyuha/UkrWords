#ifndef UKRWORD_H
#define UKRWORD_H

#include <QGraphicsScene>

// The base (abstract) class for ukrwords
class UkrWord
{
protected:
    QGraphicsScene * _scene;

public:
    explicit UkrWord(QGraphicsScene * scene):
        _scene(scene)
    {
    }

    virtual ~UkrWord()
    {
    }

    virtual void draw() = 0;

};

#endif // UKRWORD_H
