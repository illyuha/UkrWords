#include "secondwidget.h"
#include "ui_secondwidget.h"
#include "wheelukrword.h"

SecondWidget::SecondWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecondWidget)
{
    ui->setupUi(this);

    ui->nextPushButton->setText("ДАЛІ");
    ui->backPushButton->setText("НАЗАД");

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

}

SecondWidget::~SecondWidget()
{
    delete ui;
}

const QPushButton * SecondWidget::getNextButton()
{
    return ui->nextPushButton;
}

const QPushButton * SecondWidget::getBackButton()
{
    return ui->backPushButton;
}

// Factory method
UkrWord * SecondWidget::createUkrWord(const QString & type)
{
    ukrword = NULL;
    // TODO: avoid the "hardcoding", e.g. store somewhere the strings as constants
    if (type == "Коловорот")
        ukrword = new WheelUkrWord(scene);
    return ukrword;
}

void SecondWidget::onUkrwordFormChanged(const QString &text)
{
    ukrword = createUkrWord(text);
}
