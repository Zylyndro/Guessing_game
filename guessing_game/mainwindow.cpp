#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    generateRandomNum();
    GenerateTimers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateTime()
{
    ui->timebar->setValue(timer->remainingTime());
}

void MainWindow::generateRandomNum()
{
    m_randomNum = QRandomGenerator::global()->generate()%100;
    std::cout << "randomnum = " << m_randomNum << std::endl;
}

void MainWindow::GenerateTimers()
{
    timer = new QTimer(this);
    timertimer = new QTimer(this);
    connect(timertimer, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    connect(timer, SIGNAL(timeout()), this, SLOT(CheckState()));
    timer->start(10000);
    timertimer->start(10);
}

void MainWindow::on_checkBtn_clicked()
{
    m_guess = ui->spin_guess->value();
    if(ui->checkBtn->text() == "Check")
    {
        if(m_randomNum > m_guess)
        {
            std::cout << "TOO LOW" << std::endl;
            ui->label_tipp->setText("TOO LOW");
        }
        else if(m_randomNum < m_guess)
        {
            std::cout << "TOO HIGH" << std::endl;
            ui->label_tipp->setText("TOO HIGH");
        }
        else
        {
            std::cout << "CORRECT, time remaining: " << timer->remainingTime() << "ms" << std::endl;
            m_state = true;
            timer->stop();
            CheckState();
        }
    }
    else
    {
        Reset();
    }
}

void MainWindow::Reset()
{
    generateRandomNum();
    m_state = false;
    ui->spin_guess->setEnabled(true);
    ui->label_tipp->setText("Your guess is...");
    ui->label_guess->setText("Take a guess");
    ui->checkBtn->setText("Check");
    timer->start(10000);
}

void MainWindow::CheckState()
{
    timer->stop();
    if(m_state == false)
    {
        ui->spin_guess->setDisabled(true);
        ui->label_tipp->setText("Too slow :(");
        ui->label_guess->setText("Game Over");
        ui->checkBtn->setText("Retry");
    }
    else
    {
        ui->spin_guess->setDisabled(true);
        ui->label_tipp->setText("CORRECT");
        ui->label_guess->setText("GOOD JOB!!!!");
        ui->checkBtn->setText("Retry");
    }
}

void MainWindow::on_spin_guess_editingFinished()
{
    //on_checkBtn_clicked();
}

