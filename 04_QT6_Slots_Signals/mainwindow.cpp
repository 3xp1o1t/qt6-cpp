#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyCustomSlot* myCustomSlot = new MyCustomSlot;
    // Quien envia, que envia 			Quien recibe   Que recibe.
    connect(this, &MainWindow::doNow, myCustomSlot, &MyCustomSlot::doSomething);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //QMessageBox::information(this, "Hello", "Button has been clicked!");
    emit doNow();
}

