#ifndef FIRSTWIDGET_H
#define FIRSTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <ukrword.h>

namespace Ui
{
    class FirstWidget;
}

class FirstWidget : public QWidget
{
    Q_OBJECT

private:
    Ui::FirstWidget * ui;

private slots:
    void onInputChanged();

public:
    explicit FirstWidget(QWidget * parent = 0);
    ~FirstWidget();
    const QPushButton * getNextButton();

signals:
    void ukrwordFormChanged(const QString &, const UkrWord::Bundle &);
};

#endif // FIRSTWIDGET_H
