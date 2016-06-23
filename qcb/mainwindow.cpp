#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qcb = QApplication::clipboard();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    // delete qcb;
}

void MainWindow::on_btnLoad_clicked()
{
    QString data = qcb->text();
    ui->txData->setText(data);
}


void MainWindow::on_btnSave_clicked()
{
    qcb->setText(ui->txData->text());
}
