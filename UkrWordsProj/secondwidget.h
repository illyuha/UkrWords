#ifndef SECONDWIDGET_H
#define SECONDWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGraphicsScene>
#include "ukrword.h"

namespace Ui
{
    class SecondWidget;
}

class SecondWidget : public QWidget
{
    Q_OBJECT

private:
    Ui::SecondWidget * ui;
    QGraphicsScene * scene;
    // UkrWord * ukrword;
    UkrWord * createUkrWord(const QString &);

public:
    explicit SecondWidget(QWidget *parent = 0);
    ~SecondWidget();
    const QPushButton * getNextButton();
    const QPushButton * getBackButton();

};

#endif // SECONDWIDGET_H
