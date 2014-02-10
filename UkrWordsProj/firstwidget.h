#ifndef FIRSTWIDGET_H
#define FIRSTWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui
{
    class FirstWidget;
}

class FirstWidget : public QWidget
{
    Q_OBJECT

private:
    Ui::FirstWidget * ui;
    QPushButton * nextButton;

public:
    explicit FirstWidget(QWidget * parent = 0);
    ~FirstWidget();
    const QPushButton * getNextButton();

};

#endif // FIRSTWIDGET_H
