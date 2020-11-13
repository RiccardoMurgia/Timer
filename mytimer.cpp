#include "mytimer.h"
#include "ui_mytimer.h"

MyTimer::MyTimer(QWidget *parent) :QWidget(parent),ui(new Ui::MyTimer) {
    ui->setupUi(this);
    counter = Counter::getInstance();
}

MyTimer::~MyTimer() {
    delete ui;
}
