#include "mytimer.h"
#include "ui_mytimer.h"

MyTimer::MyTimer(QWidget *parent) : QWidget(parent), ui(new Ui::MyTimer) {
    ui->setupUi(this);
    counter = Counter::getInstance();
    counter->attach(this);
}

MyTimer::~MyTimer() {
    delete ui;
}

void MyTimer::update() {
    //todo
}


void MyTimer::on_startButton_clicked() {
    int h, m, s;
    QTime timeInput = ui->timeInput->time();
    h = timeInput.hour();
    m = timeInput.minute();
    s = timeInput.second();

}

void MyTimer::on_stopButton_clicked() {

}

void MyTimer::on_restButton_clicked() {

}
