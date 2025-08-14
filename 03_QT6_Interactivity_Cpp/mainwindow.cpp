#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // INTERACTURAR CON PROPIEDADES DINAMICAS DE LOS STYLESHEETS
    ui->button1->setProperty("pagematches", true); // pagematches es una propiedad dinamica agregada a un qPushButton en el UI.
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Click derecho a un QWidget y luego en Go To Slot... para generar sus metodos, igual se genera en su mainwindow.h
void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->button1->setProperty("pagematches", false);
    ui->button2->setProperty("pagematches", false);
    ui->button3->setProperty("pagematches", false);

    if(0 == index) {
        ui->button1->setProperty("pagematches", true);
    } else if (index == 1) {
        ui->button2->setProperty("pagematches", true);
    } else {
        ui->button3->setProperty("pagematches", true);
    }

    // Actualizar el stylo de los botones
    ui->button1->style()->polish(ui->button1);
    ui->button2->style()->polish(ui->button2);
    ui->button3->style()->polish(ui->button3);
}


void MainWindow::on_button1_clicked()
{
    QMessageBox::information(nullptr, "Titulo del MessageBox", "Mensaje del messagebox");
}

