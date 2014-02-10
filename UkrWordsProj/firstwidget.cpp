#include "firstwidget.h"
#include "ui_firstwidget.h"

FirstWidget::FirstWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FirstWidget)
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

FirstWidget::~FirstWidget()
{
    delete ui;
}

const QPushButton * FirstWidget::getNextButton()
{
    return ui->nextPushButton;
}

/*void MainWindow::on_langComboBox_currentIndexChanged(int index)
{
//    QVector<QString> v(2);
//    v[0] = "Choose the language";
//    v[1] = "Оберіть мову";
//    ui->langLabel->setText(v[index]);
}*/
