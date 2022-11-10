#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QRandomGenerator>

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
    void generateRandomNum();
    void GenerateTimers();
    void on_checkBtn_clicked();
    void UpdateTime();
    void CheckState();
    void Reset();

    void on_spin_guess_editingFinished();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timertimer;
    int m_guess = 0;
    int m_randomNum = -1;
    int m_tries = 0;
    bool m_state = false;
};
#endif // MAINWINDOW_H
