#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "status.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openFiles_clicked();
    void on_convert_clicked();

public slots:
    void doneConverting();

signals:
    void openDialog(QStringList);

private:
    Ui::MainWindow *ui;
    Status *status;
};

#endif // MAINWINDOW_H
