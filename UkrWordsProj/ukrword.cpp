#include "ukrword.h"

UkrWord::UkrWord(QGraphicsView * view, const Bundle & bundle):
    _view(view), _surnameLength(bundle.surnameLength()), _aphorism(bundle.aphorism())
{
}

UkrWord::UkrWord(QGraphicsView * view):
    UkrWord(view,Bundle())
{
}

/*UkrWord::UkrWord(const UkrWord & other):
    _view(other.view()), _author(other.author()), _aphorism(other.aphorism())
{
}

UkrWord & UkrWord::operator=(const UkrWord & other)
{
    if (this != &other)
    {
        // ...
    }
    return * this;
}*/

void UkrWord::initWithBundle(const Bundle & bundle)
{
    surnameLength() = bundle.surnameLength();
    aphorism() = bundle.aphorism();
}

