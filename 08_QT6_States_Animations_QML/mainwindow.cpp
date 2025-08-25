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
    animation->setEndValue(QRect(50, 50, 100, 50));
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
    animation2->setEndValue(QRect(150, 50, 100, 50));

    QPropertyAnimation *animation3 = new QPropertyAnimation(ui->pushButton_3, "geometry");
    animation3->setDuration(3000);
    animation3->setStartValue(ui->pushButton_3->geometry());
    animation3->setEndValue(QRect(250, 50, 100, 50));

    QPropertyAnimation *animation4 = new QPropertyAnimation(ui->pushButton_4, "geometry");
    animation4->setDuration(3000);
    animation4->setStartValue(ui->pushButton_4->geometry());
    animation4->setEndValue(QRect(50, 200, 100, 50));

    QPropertyAnimation *animation5 = new QPropertyAnimation(ui->pushButton_5, "geometry");
    animation5->setDuration(3000);
    animation5->setStartValue(ui->pushButton_5->geometry());
    animation5->setEndValue(QRect(150, 200, 100, 50));

    QPropertyAnimation *animation6 = new QPropertyAnimation(ui->pushButton_6, "geometry");
    animation6->setDuration(3000);
    animation6->setStartValue(ui->pushButton_6->geometry());
    animation6->setEndValue(QRect(250,200,100,50));


    animation2->setEasingCurve(curve);
    animation3->setEasingCurve(curve);
    animation4->setEasingCurve(curve);
    animation5->setEasingCurve(curve);
    animation6->setEasingCurve(curve);

    // Ejecutar un conjunto de animaciones en paralelo
    // opcional: QSequentialAnimationGroup -> Ejecutar animaciones en el orden de agrupacion
    // QParallelAnimationGroup *group = new QParallelAnimationGroup;
    // group->addAnimation(animation);
    // group->addAnimation(animation2);
    // group->addAnimation(animation3);

    // group->start();

    // QSequentialAnimationGroup *group = new QSequentialAnimationGroup;
    // group->addAnimation(animation);
    // group->addAnimation(animation2);
    // group->addAnimation(animation3);

    // group->start();

    // Crear una secuencia de secuencias.
    QParallelAnimationGroup *group1 = new QParallelAnimationGroup;
    group1->addAnimation(animation);
    group1->addAnimation(animation2);
    group1->addAnimation(animation3);

    QParallelAnimationGroup *group2 = new QParallelAnimationGroup;
    group2->addAnimation(animation4);
    group2->addAnimation(animation5);
    group2->addAnimation(animation6);

    QSequentialAnimationGroup *groupAll = new QSequentialAnimationGroup;
    groupAll->addAnimation(group1);
    groupAll->addAnimation(group2);
    groupAll->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
