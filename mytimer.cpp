#include <QtWidgets/QMessageBox>
#include "mytimer.h"
#include "ui_mytimer.h"
#include "QDebug"

MyTimer::MyTimer(QWidget *parent) : QWidget(parent), ui(new Ui::MyTimer), counter(Counter::getInstance()), start(false),
                                    pause(false), setFlag(false) {
    ui->setupUi(this);
    counter->attach(this);
}

MyTimer::~MyTimer() {
    delete ui;
}

void MyTimer::update() {
    if (start && !pause) {
        if (ui->seconds->intValue() <= 4 && ui->minutes->intValue() == 0 && ui->hours->intValue() == 0) {
            QPalette palette = ui->seconds->palette();
            palette.setColor(palette.WindowText, Qt::red);
            ui->seconds->setPalette(palette);
            ui->minutes->setPalette(palette);
            ui->hours->setPalette(palette);

        }
        if (ui->seconds->intValue() > 0) {
            ui->seconds->display(ui->seconds->intValue() - 1);
        } else {
            if (ui->minutes->intValue() > 0) {
                ui->seconds->display(59);
                ui->minutes->display(ui->minutes->intValue() - 1);
            } else {
                if (ui->hours->intValue() > 0) {
                    ui->minutes->display(59);
                    ui->hours->display(ui->hours->intValue() - 1);
                } else {
                    start = false;
                    setFlag = false;
                    QPalette palette = ui->seconds->palette();
                    palette.setColor(palette.WindowText, Qt::black);
                    ui->seconds->setPalette(palette);
                    ui->minutes->setPalette(palette);
                    ui->hours->setPalette(palette);
                }
            }
        }
    }
}

void MyTimer::on_setTimerButton_clicked() {
    if (ui->timeInput->time().hour() != 0 || ui->timeInput->time().minute() != 0 || ui->timeInput->time().second()) {
        ui->hours->display(ui->timeInput->time().hour());
        ui->minutes->display(ui->timeInput->time().minute());
        ui->seconds->display(ui->timeInput->time().second());
        setFlag = true;
    }
}

void MyTimer::on_startButton_clicked() {
    if (setFlag) {
        start = true;
        if (pause) {
            pause = false;
        }
    } else {
        QMessageBox::StandardButton reply = QMessageBox::warning(this, "Waring",
                                                                 "It is necessary to set the timer before starting it");
        if (reply == QMessageBox::Yes) {
            QApplication::quit();
        }
    }
}


void MyTimer::on_pauseButton_clicked() {
    pause = true;
}

void MyTimer::on_resetButton_clicked() {
    ui->hours->display(0);
    ui->minutes->display(0);
    ui->seconds->display(0);
    start = false;
    setFlag = false;
}



