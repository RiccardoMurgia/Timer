#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "iostream"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    counter = Counter::getInstance();
    counter->attach(this);
    ui->selectTimeFormat->addItem("12h Form");
    ui->selectTimeFormat->addItem("24h Form");
    ui->selectDateFormat->addItem("Extended Format");
    ui->selectDateFormat->addItem("DD-MM-YYYY");
    ui->selectDateFormat->addItem("DD-MM-YY");
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_openTimer_clicked() {
    myTimer = new MyTimer();
    myTimer->show();

}

void MainWindow::update() {
    QWidget::update();
    ui->dateLabel->setText(QString::fromStdString(counter->getStringDate()));
    ui->timeLabel->setText(QString::fromStdString(counter->getStringTime()));
}

void MainWindow::on_selectTimeFormat_currentTextChanged(const QString &arg1) {
    string timeFormat = ui->selectTimeFormat->currentText().toStdString();
    counter->setTimeFormat(timeFormat);
}

void MainWindow::on_selectDateFormat_currentTextChanged(const QString &arg1) {
    string dateFormat = ui->selectDateFormat->currentText().toStdString();
    counter->setDateFormat(dateFormat);
}
