#include "secondwidget.h"
#include "ui_secondwidget.h"

SecondWidget::SecondWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecondWidget)
{
    ui->setupUi(this);
    ui->nextPushButton->setText("ДАЛІ");
    ui->backPushButton->setText("НАЗАД");
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
