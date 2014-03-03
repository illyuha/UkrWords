#ifndef UKRWORD_H
#define UKRWORD_H

#include <QGraphicsView>

// The base (abstract) class for ukrwords
class UkrWord
{
protected:
    QGraphicsView * _view;
    QString _author;
    QString _aphorism;

public:
    class Bundle
    {
    private:
        QString _author;
        QString _aphorism;

    public:
        Bundle()
        {
        }

        QString & author()
        {
            return _author;
        }

        const QString & author() const
        {
            return _author;
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


    explicit UkrWord(QGraphicsView * view, const Bundle & bundle):
        _view(view), _author(bundle.author()), _aphorism(bundle.aphorism())
    {
    }

    explicit UkrWord(QGraphicsView * view):
        UkrWord(view,Bundle())
    {
    }

    virtual ~UkrWord()
    {
    }

    QString & author()
    {
        return _author;
    }

    const QString & author() const
    {
        return _author;
    }

    QString & aphorism()
    {
        return _aphorism;
    }

    const QString & aphorism() const
    {
        return _aphorism;
    }

    void initWithBundle(const Bundle & bundle)
    {
        author() = bundle.author();
        aphorism() = bundle.aphorism();
    }

    virtual void draw() const = 0;

};

#endif // UKRWORD_H
