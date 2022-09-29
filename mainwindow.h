#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_00_clicked();

    void on_pushButton_01_clicked();

    void on_pushButton_02_clicked();

    void on_pushButton_03_clicked();

    void on_pushButton_04_clicked();

    void on_pushButton_05_clicked();

    void on_pushButton_06_clicked();

    void on_pushButton_07_clicked();

    void on_pushButton_08_clicked();

    void on_pushButton_09_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_mult_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_allclear_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_point_clicked();

private:
    Ui::MainWindow *ui;

    int digit;
    int first_dec_point;
    int second_dec_point;
    double first;
    double second;
    std::string op;
    double result;
};
#endif // MAINWINDOW_H
