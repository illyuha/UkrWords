#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QVector>
#include <QStringList>
//#include <QEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Not sure whether the language of the UI should be modifiable
    QStringList langsList = QStringList()/* << "English"*/ << "Українська";
    ui->langComboBox->addItems(langsList);
    ui->aphorismLabel->setText("Введіть текст афоризму");
    ui->authorLabel->setText("Введіть прізвище автора афоризму");
    ui->formLabel->setText("Оберіть форму укрворда");
    QStringList formsList = QStringList() << "Коловорот" << "Ґудзик" << "Сніжинка";
    ui->formComboBox->addItems(formsList);
    ui->nextPushButton->setText("ДАЛІ");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_langComboBox_currentIndexChanged(int index)
{
//    QVector<QString> v(2);
//    v[0] = "Choose the language";
//    v[1] = "Оберіть мову";
//    ui->langLabel->setText(v[index]);
}
