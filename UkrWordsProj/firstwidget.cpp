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

    // TODO: add more signals

    connect(ui->formComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(onInputChanged()));
    connect(ui->authorLineEdit,SIGNAL(textEdited(QString)),this,SLOT(onInputChanged()));

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

void FirstWidget::onInputChanged()
{
    // If none of the forms was selected then the "next" button will ignore all the mouse events
    bool disable = (ui->formComboBox->currentText() == "--Не обрано--");
    // ... or if the length of the author's surname is one character
    disable = disable || (ui->authorLineEdit->text().length() < 2);

    // TODO: add more validation for the surname

    ui->nextPushButton->setAttribute(Qt::WA_TransparentForMouseEvents,disable);
    ui->nextPushButton->setDisabled(disable);

    UkrWord::Bundle bundle;
    bundle.author() = ui->authorLineEdit->text();
    bundle.aphorism() = ui->aphorismPlainTextEdit->toPlainText();
    emit ukrwordFormChanged(ui->formComboBox->currentText(),bundle);
}
