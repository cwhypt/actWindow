#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QWidget *mp;
    QWidget *ap;
    QWidget *currentPage;


private slots:

    void on_mainButton_clicked();

    void on_autoButton_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
