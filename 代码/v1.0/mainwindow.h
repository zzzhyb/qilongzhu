#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    QPushButton *DataImport;
    QPushButton *Run;
    QPushButton *Quicker;
    QPushButton *Slower;

private slots:
    void on_DataImport_clicked(bool checked);

    void on_Run_clicked(bool checked);

    void on_Quicker_clicked(bool checked);

    void on_Slower_clicked(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
