#include "mycustomslot.h"

// Un Slot custom, debe de tener de base la clase QObject.
// En este caso, se adjunta en el header
MyCustomSlot::MyCustomSlot(QObject *parent)
    : QObject(parent){}

void MyCustomSlot::doSomething() {
    QMessageBox::information(nullptr, "Hello", "Button has been clicked");
}
