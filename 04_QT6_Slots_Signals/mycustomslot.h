#ifndef MYCUSTOMSLOT_H
#define MYCUSTOMSLOT_H

#include <QObject>
#include <QMainWindow>
#include <QMessageBox>

class MyCustomSlot : public QObject
{
    Q_OBJECT
public:
    explicit MyCustomSlot(QObject *parent = nullptr);

public slots:
    void doSomething();

signals:
};

#endif // MYCUSTOMSLOT_H
