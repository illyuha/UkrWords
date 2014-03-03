#ifndef UKRWORD_H
#define UKRWORD_H

#include <QGraphicsView>

typedef unsigned int uint;

// The base (abstract) class for ukrwords
class UkrWord
{
protected:
    QGraphicsView * _view;
    uint _surnameLength;
    QString _aphorism;
    explicit UkrWord(const UkrWord & other);
    UkrWord & operator=(const UkrWord &);

public:
    class Bundle
    {
    private:
        QString _aphorism;
        // the length of the surname of author of the aphorism
        uint _surnameLength;
        explicit Bundle(const Bundle &);

    public:
        Bundle()
        {
        }

        uint & surnameLength()
        {
            return _surnameLength;
        }

        const uint & surnameLength() const
        {
            return _surnameLength;
        }

        QString & aphorism()
        {
            return _aphorism;
        }

        const QString & aphorism() const
        {
            return _aphorism;
        }
    };

    explicit UkrWord(QGraphicsView * view, const Bundle & bundle);

    explicit UkrWord(QGraphicsView * view);

    virtual ~UkrWord()
    {
    }

    QGraphicsView * view() const
    {
        return _view;
    }

    uint & surnameLength()
    {
        return _surnameLength;
    }

    const uint & surnameLength() const
    {
        return _surnameLength;
    }

    QString & aphorism()
    {
        return _aphorism;
    }

    const QString & aphorism() const
    {
        return _aphorism;
    }

    void initWithBundle(const Bundle & bundle);

    virtual void draw() const = 0;

};

#endif // UKRWORD_H
