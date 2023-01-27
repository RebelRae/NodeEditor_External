#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    nodeScene = new NodeScene(this);
    ui->graphicsView->setScene(nodeScene);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_styleBox_currentIndexChanged(int index) {
    nodeScene->setStyle(index);
}

