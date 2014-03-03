#include "firstwidget.h"
#include <secondwidget.h>
#include <QApplication>
#include <QStateMachine>
#include <QEventTransition>

int main(int argc, char *argv[])
{
    // TODO: delete all the unnecessary pointers

    // TODO: implement copy constructors and assignment operators for UkrWord class
    // NB: Don't forget to read Boublik's article (distedu.ukma.kiev.ua/file.php/11/Ch_04_zmist.htm#_Toc378584795)

    QApplication a(argc, argv);

    FirstWidget firstWidget;
    SecondWidget secondWidget;

    QStateMachine stateMachine;
    QState firstState, secondState;

    const QPushButton * firstNextButton = firstWidget.getNextButton();
    const QPushButton * firstBackButton = secondWidget.getBackButton();

    QObject::connect(&firstState,SIGNAL(exited()),&secondWidget,SLOT(show()));
    QObject::connect(&secondState,SIGNAL(entered()),&firstWidget,SLOT(hide()));
    QObject::connect(&secondState,SIGNAL(exited()),&firstWidget,SLOT(show()));
    QObject::connect(&firstState,SIGNAL(entered()),&secondWidget,SLOT(hide()));

    QObject::connect(&firstWidget,SIGNAL(ukrwordFormChanged(const QString &,const UkrWord::Bundle &)),&secondWidget,SLOT(onUkrwordFormChanged(const QString &,const UkrWord::Bundle &)));

    QEventTransition toSecondWidgetTransition(const_cast<QPushButton *>(firstNextButton),QEvent::MouseButtonPress);
    QEventTransition toFirstWidgetTransition(const_cast<QPushButton *>(firstBackButton),QEvent::MouseButtonPress);

    toSecondWidgetTransition.setTargetState(&secondState);
    firstState.addTransition(&toSecondWidgetTransition);
    toFirstWidgetTransition.setTargetState(&firstState);
    secondState.addTransition(&toFirstWidgetTransition);

    stateMachine.addState(&firstState);
    stateMachine.addState(&secondState);
    stateMachine.setInitialState(&firstState);
    stateMachine.start();

    firstWidget.show();

    return a.exec();
}
