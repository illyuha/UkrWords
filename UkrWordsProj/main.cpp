#include "firstwidget.h"
#include <secondwidget.h>
#include <QApplication>
#include <QStateMachine>
#include <QEventTransition>

int main(int argc, char *argv[])
{
    // TODO: delete all the unnecessary pointers

    // TODO: decide how to transfer data between two widgets
    // Useful link: stackoverflow.com/questions/6199962/how-to-pass-data-from-one-form-to-another-in-qt

    QApplication a(argc, argv);

    FirstWidget firstWidget;
    SecondWidget secondWidget;

    QStateMachine stateMachine;
    QState firstState, secondState;

    const QPushButton * firstNextButton = firstWidget.getNextButton();
    const QPushButton * firstBackButton = secondWidget.getBackButton();

    QObject::connect(&firstState,SIGNAL(exited()),&firstWidget,SLOT(hide()));
    QObject::connect(&secondState,SIGNAL(entered()),&secondWidget,SLOT(show()));
    QObject::connect(&secondState,SIGNAL(exited()),&secondWidget,SLOT(hide()));
    QObject::connect(&firstState,SIGNAL(entered()),&firstWidget,SLOT(show()));

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
