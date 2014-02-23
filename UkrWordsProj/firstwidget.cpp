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
    ui->nextPushButton->setText("ДАЛІ");

    QStringList formsList = QStringList() << "--Не обрано--" << "Коловорот" << "Ґудзик" << "Сніжинка";
    ui->formComboBox->addItems(formsList);

    // results in changing the form of the ukrword
    connect(ui->formComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(onUkrwordFormChanged()));

    // prevents from cliclking the button (by default)
    ui->nextPushButton->setAttribute(Qt::WA_TransparentForMouseEvents);
}

FirstWidget::~FirstWidget()
{
    delete ui;
}

const QPushButton * FirstWidget::getNextButton()
{
    return ui->nextPushButton;
}

void FirstWidget::onUkrwordFormChanged()
{
    // If none of the forms was selected then the "next" button will ignore all the mouse events
    bool disable = (ui->formComboBox->currentText() == "--Не обрано--");
    ui->nextPushButton->setAttribute(Qt::WA_TransparentForMouseEvents,disable);
    ui->nextPushButton->setDisabled(disable);
    emit ukrwordFormChanged(ui->formComboBox->currentText());
}

/*void MainWindow::on_langComboBox_currentIndexChanged(int index)
{
//    QVector<QString> v(2);
//    v[0] = "Choose the language";
//    v[1] = "Оберіть мову";
//    ui->langLabel->setText(v[index]);
}*/
