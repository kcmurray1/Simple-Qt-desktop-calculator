#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"
#include <iostream>
#include <QPushButton>

//Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Add event to all buttons
    buttons_ = ui->widget->findChildren<QPushButton *>();
    std::cout << "Found " << buttons_.size() << " Buttons" << std::endl;
    for(int i = 0; i < buttons_.size(); i++)
    {
        QObject::connect(buttons_[i], SIGNAL(clicked()), this, SLOT(on_push_button_clicked()));
    }


}

//Destructor
MainWindow::~MainWindow()
{
    std::cout << "Closing window.." << std::endl;
    delete ui;
}

//Update Calculator based on user input
void MainWindow::on_push_button_clicked()
{
    //Code snippet supplied by ChatGPT to access text property of QPushButton
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        std::string button_val = clickedButton->text().toStdString();
        //Check if Enter button has been clicked
        if (button_val.compare("Enter") == 0)
        {
            calculator_.evalExpression();
            return;
        }
        //Clear calculation
        if (button_val.compare("CLEAR") == 0)
        {
            calculator_.clear();
        }
        //Add to Calculation
        else
        {
            calculator_.addSymbol(button_val);
        }
        //Update UI
        ui->txt_result->setText(QString::fromStdString(calculator_.getExpression()));
    }
}


