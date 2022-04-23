#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include <tset.h>

TSet<int> int_set;
TSet<int> int_set_2;
TSet<QString> str_set;
TSet<QString> str_set_2;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->set_1_text->setReadOnly(true);
    ui->set_2_text->setReadOnly(true);
    ui->result_text->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//ADD
{
    if(ui->comboBox->currentText() == "Integers") {
        if(ui->line1->text() != ""){
            int_set.AddElement(ui->line1->text().toInt(0,10));
            QString buffer;
            for (auto el : int_set.Get()){
                buffer += QString::number(el) + '\n';
            }
            ui->set_1_text->setPlainText(buffer);
        }
        if(ui->line2->text() != ""){
            int_set_2.AddElement(ui->line2->text().toInt(0,10));
            QString buffer;
            for (auto el : int_set_2.Get()){
                buffer += QString::number(el) + '\n';
            }
            ui->set_2_text->setPlainText(buffer);
        }
    } else {
        if(ui->line1->text() != ""){
            str_set.AddElement(ui->line1->text());
            QString buffer;
            std::vector<QString> vec = str_set.Get();
            for (size_t i = 0; i < vec.size(); ++i){
                buffer += vec[i] + '\n';
            }
            ui->set_1_text->setPlainText(buffer);
        }
        if(ui->line2->text() != ""){
            str_set_2.AddElement(ui->line2->text());
            QString buffer;
            std::vector<QString> vec = str_set_2.Get();
            for (size_t i = 0; i < vec.size(); ++i){
                buffer += vec[i] + '\n';
            }
            ui->set_2_text->setPlainText(buffer);
        }
    }

    if(ui->line1->text() == "" && ui->line2->text() == ""){
        QMessageBox::about(this, "Warning", "You didn't enter anything!");

    }
}

void MainWindow::on_pushButton_2_clicked()//UNION
{
    if(ui->comboBox->currentText() == "Integers") {
       TSet<int> result = int_set.add(int_set_2);
       QString buffer;
       for (auto el : result.Get()){
           buffer += QString::number(el) + '\n';
       }
       ui->result_text->setPlainText(buffer);
    } else {
        TSet<QString> result = str_set.add(str_set_2);
        QString buffer;
        std::vector<QString> vec = result.Get();
        for (size_t i = 0; i < vec.size(); ++i){
            buffer += vec[i] + '\n';
        }
        ui->result_text->setPlainText(buffer);
    }

    if(ui->line1->text() == "" && ui->line2->text() == ""){
        QMessageBox::about(this, "Warning", "You didn't enter anything!");

    }

}

void MainWindow::on_pushButton_3_clicked()//INTERSECT
{
    if(ui->comboBox->currentText() == "Integers") {
       TSet<int> result = int_set.mult(int_set_2);
       QString buffer;
       for (auto el : result.Get()){
           buffer += QString::number(el) + '\n';
       }
       ui->result_text->setPlainText(buffer);
    } else {
        TSet<QString> result = str_set.mult(str_set_2);
        QString buffer;
        std::vector<QString> vec = result.Get();
        for (size_t i = 0; i < vec.size(); ++i){
            buffer += vec[i] + '\n';
        }
        ui->result_text->setPlainText(buffer);
    }

    if(ui->line1->text() == "" && ui->line2->text() == ""){
        QMessageBox::about(this, "Warning", "You didn't enter anything!");

    }
}

void MainWindow::on_pushButton_4_clicked()//SIM SUB
{
    if(ui->comboBox->currentText() == "Integers") {
       TSet<int> result = int_set.sim_sub(int_set_2);
       QString buffer;
       for (auto el : result.Get()){
           buffer += QString::number(el) + '\n';
       }
       ui->result_text->setPlainText(buffer);
    } else {
        TSet<QString> result = str_set.sim_sub(str_set_2);
        QString buffer;
        std::vector<QString> vec = result.Get();
        for (size_t i = 0; i < vec.size(); ++i){
            buffer += vec[i] + '\n';
        }
        ui->result_text->setPlainText(buffer);
    }

    if(ui->line1->text() == "" && ui->line2->text() == ""){
        QMessageBox::about(this, "Warning", "You didn't enter anything!");

    }
}



void MainWindow::on_pushButton_7_clicked()//Clean set_1
{
    ui->set_1_text->setPlainText("");
    str_set.Clear();
    int_set.Clear();
}


void MainWindow::on_pushButton_5_clicked()//Clean set_2
{
    ui->set_2_text->setPlainText("");
    str_set_2.Clear();
    int_set_2.Clear();
}

void MainWindow::on_pushButton_6_clicked()//Clean result
{
    ui->result_text->setPlainText("");
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Integers"){
        ui->pushButton_7->click();
        ui->pushButton_5->click();
    } else {
        ui->pushButton_7->click();
        ui->pushButton_5->click();
    }
}
