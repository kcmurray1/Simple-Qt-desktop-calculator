#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "calculator.h"
#include <QMainWindow>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_push_button_clicked();

private:
    Ui::MainWindow *ui;
    Calculator calculator_;
    QList<QPushButton*> buttons_;
};
#endif // MAINWINDOW_H
