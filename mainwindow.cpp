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
    //Add click event to all buttons
    buttons_ = ui->centralwidget->findChildren<QPushButton *>();
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

//Update Calculator based on user interaction with UI buttons
void MainWindow::on_push_button_clicked()
{
    //Code snippet supplied by ChatGPT to access text property of QPushButton
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        std::string button_val = clickedButton->text().toStdString();
        for(unsigned int i = 0; i < button_val.length(); i++)
            button_val[i] = tolower(button_val[i]);

        //Check if Enter button has been clicked
        if (button_val.compare("enter") == 0)
        {
            calculator_.eval_expression();
        }
        //Clear calculation
        else if (button_val.compare("clear") == 0)
        {
            calculator_.clear();
        }
        //Add to Calculation
        else
        {
            calculator_.add_symbol(button_val);
        }
        //Update UI
        ui->txt_result->setText(QString::fromStdString(calculator_.get_expression()));
        if (button_val.compare("enter") == 0)
        {
            calculator_.clear();
        }
    }
}


//Update Calculator when user directly changes expression
void MainWindow::on_txt_result_textEdited(const QString &arg1)
{
    //Update calculator
    calculator_.set_expression(arg1.toStdString());
}

