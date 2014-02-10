#ifndef SECONDWIDGET_H
#define SECONDWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui
{
    class SecondWidget;
}

class SecondWidget : public QWidget
{
    Q_OBJECT

private:
    Ui::SecondWidget *ui;

public:
    explicit SecondWidget(QWidget *parent = 0);
    ~SecondWidget();
    const QPushButton * getNextButton();
    const QPushButton * getBackButton();

};

#endif // SECONDWIDGET_H
