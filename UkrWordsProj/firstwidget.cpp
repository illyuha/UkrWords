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

    // allow to enter only the numbers in the specified range
    ui->authorLineEdit->setValidator(new QIntValidator(2,10,this));

    QStringList formsList = QStringList() << "--Не обрано--" << "Коловорот" << "Ґудзик" << "Сніжинка";
    ui->formComboBox->addItems(formsList);

    // TODO: try to avoid redrawing ukrwords after one character was entered

    connect(ui->formComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(onInputChanged()));
    connect(ui->authorLineEdit,SIGNAL(textEdited(QString)),this,SLOT(onInputChanged()));
    connect(ui->aphorismPlainTextEdit,SIGNAL(textChanged()),this,SLOT(onInputChanged()));

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
    disable = disable || (ui->authorLineEdit->text().length() == 0);
    disable = disable || (ui->aphorismPlainTextEdit->toPlainText().length() < 2 * ui->authorLineEdit->text().toInt());

    ui->nextPushButton->setAttribute(Qt::WA_TransparentForMouseEvents,disable);
    ui->nextPushButton->setDisabled(disable);

    if (!disable)
    {
        UkrWord::Bundle bundle;
        bundle.surnameLength() = ui->authorLineEdit->text().toInt();
        bundle.aphorism() = ui->aphorismPlainTextEdit->toPlainText();
        emit ukrwordFormChanged(ui->formComboBox->currentText(),bundle);
    }
}
