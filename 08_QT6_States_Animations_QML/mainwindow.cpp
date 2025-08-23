#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPropertyAnimation *animation = new QPropertyAnimation(ui->pushButton, "geometry");
    animation->setDuration(3000);
    animation->setStartValue(ui->pushButton->geometry());
    animation->setEndValue(QRect(50, 200, 100, 50));
    // Easing Curves
    QEasingCurve curve;
    curve.setType(QEasingCurve::OutBounce);
    // Common properties for curve
    curve.setAmplitude(1.00);
    curve.setOvershoot(1.70);
    curve.setPeriod(0.30);
    animation->setEasingCurve(curve);
    // Loop count for repeating animations
    // -1 si se requiere que sea infinito
    //animation->setLoopCount(2);
    // Start para una sola animacion, group para multiples
    //animation->start();

    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->pushButton_2, "geometry");
    animation2->setDuration(3000);
    animation2->setStartValue(ui->pushButton_2->geometry());
    animation2->setEndValue(QRect(150, 200, 100, 50));

    QPropertyAnimation *animation3 = new QPropertyAnimation(ui->pushButton_3, "geometry");
    animation3->setDuration(3000);
    animation3->setStartValue(ui->pushButton_3->geometry());
    animation3->setEndValue(QRect(250, 200, 100, 50));

    animation2->setEasingCurve(curve);
    animation3->setEasingCurve(curve);

    // Ejecutar un conjunto de animaciones en paralelo
    // opcional: QSequentialAnimationGroup -> Ejecutar animaciones en el orden de agrupacion
    // QParallelAnimationGroup *group = new QParallelAnimationGroup;
    // group->addAnimation(animation);
    // group->addAnimation(animation2);
    // group->addAnimation(animation3);

    // group->start();

    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;
    group->addAnimation(animation);
    group->addAnimation(animation2);
    group->addAnimation(animation3);

    group->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
