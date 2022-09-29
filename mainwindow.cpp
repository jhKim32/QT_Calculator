#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <string>

#define FIRST 0
#define SECOND 1
#define RESULT 2

#define INACTIVE 0
#define ACTIVE 1
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    digit = FIRST;
    first_dec_point = INACTIVE;
    second_dec_point = INACTIVE;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_exit_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_00_clicked()
{
    switch(digit)
    {
        case FIRST:
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "0");
        break;

        case SECOND:
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "0");
        break;
    }
}

void MainWindow::on_pushButton_01_clicked()
{
    switch(digit)
    {
        case FIRST:
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "1");
        break;

        case SECOND:
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "1");
        break;
    }
}


void MainWindow::on_pushButton_02_clicked()
{
    switch(digit)
    {
        case FIRST:
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "2");
        break;

        case SECOND:
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "2");
        break;
    }
}

void MainWindow::on_pushButton_03_clicked()
{
    switch(digit)
    {
        case FIRST:
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "3");
        break;

        case SECOND:
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "3");
        break;
    }
}

void MainWindow::on_pushButton_04_clicked()
{
    switch(digit)
    {
        case FIRST:
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "4");
        break;

        case SECOND:
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "4");
        break;
    }
}

void MainWindow::on_pushButton_05_clicked()
{
    switch(digit)
    {
        case FIRST:
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "5");
        break;

        case SECOND:
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "5");
        break;
    }
}

void MainWindow::on_pushButton_06_clicked()
{
    switch(digit)
    {
        case FIRST:
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "6");
        break;

        case SECOND:
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "6");
        break;
    }
}

void MainWindow::on_pushButton_07_clicked()
{
    switch(digit)
    {
        case FIRST:
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "7");
        break;

        case SECOND:
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "7");
        break;
    }
}

void MainWindow::on_pushButton_08_clicked()
{
    switch(digit)
    {
        case FIRST:
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "8");
        break;

        case SECOND:
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "8");
        break;
    }
}

void MainWindow::on_pushButton_09_clicked()
{
    switch(digit)
    {
        case FIRST:
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "9");
        break;

        case SECOND:
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "9");
        break;
    }
}

void MainWindow::on_pushButton_plus_clicked()
{
    digit = SECOND;
    ui->label_operator->setText("+");
}

void MainWindow::on_pushButton_minus_clicked()
{
    digit = SECOND;
    ui->label_operator->setText("-");
}

void MainWindow::on_pushButton_mult_clicked()
{
    digit = SECOND;
    ui->label_operator->setText("x");
}

void MainWindow::on_pushButton_div_clicked()
{
    digit = SECOND;
    ui->label_operator->setText("/");
}

void MainWindow::on_pushButton_back_clicked()
{
    bool dec_point_check;
    switch(digit)
    {
        case FIRST:
            if(ui->lineEdit_first->text() == NULL)  return;
            ui->lineEdit_first->setText(ui->lineEdit_first->text().chopped(1));
            if((dec_point_check = ui->lineEdit_first->text().contains(".")) == false)
                first_dec_point = INACTIVE;
        break;

        case SECOND:
            if(ui->lineEdit_second->text() == NULL) return;
            ui->lineEdit_second->setText(ui->lineEdit_second->text().chopped(1));
            if((dec_point_check = ui->lineEdit_second->text().contains(".")) == false)
                second_dec_point = INACTIVE;
        break;
    }
}

void MainWindow::on_pushButton_clear_clicked()
{
    switch(digit)
    {
        case FIRST:
            ui->lineEdit_first->clear();
            first_dec_point = INACTIVE;
        break;

        case SECOND:
            ui->lineEdit_second->clear();
            second_dec_point = INACTIVE;
        break;

        default:
        ;
        break;

    }
}

void MainWindow::on_pushButton_allclear_clicked()
{
    digit = FIRST;
    first_dec_point = INACTIVE;
    second_dec_point = INACTIVE;
    ui->lineEdit_first->clear();
    ui->lineEdit_second->clear();
    ui->lineEdit_result->clear();
    ui->label_operator->clear();
}

void MainWindow::on_pushButton_equal_clicked()
{
    digit = RESULT;
    QString op;

    first = ui->lineEdit_first->text().toFloat();
    second = ui->lineEdit_second->text().toFloat();
    op = ui->label_operator->text();

    if(op == "+")
    {
        result = first + second;
        ui->lineEdit_result->setText(QString::number(result));
    }
    else if(op == "-")
    {
        result = first - second;
        ui->lineEdit_result->setText(QString::number(result));
    }
    else if(op == "x")
    {
        result = first * second;
        ui->lineEdit_result->setText(QString::number(result));
    }
    else if(op == "/")
    {
        result = first / second;
        ui->lineEdit_result->setText(QString::number(result));
    }
}

void MainWindow::on_pushButton_point_clicked()
{
    switch(digit)
    {
        case FIRST:
            if(first_dec_point == INACTIVE)
            {
                ui->lineEdit_first->setText(ui->lineEdit_first->text() + ".");
                first_dec_point = ACTIVE;
            }
        break;

        case SECOND:
            if(second_dec_point == INACTIVE)
            {
                ui->lineEdit_second->setText(ui->lineEdit_second->text() + ".");
                second_dec_point = ACTIVE;
            }
        break;
    }
}
