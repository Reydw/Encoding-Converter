#ifndef STATUS_H
#define STATUS_H

#include <QApplication>
#include <QDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QStringList>
#include <QIcon>

namespace Ui {
class Status;
}

class Status : public QDialog
{
    Q_OBJECT

public:
    explicit Status(QWidget *parent = 0);
    ~Status();

public slots:
    void convert(QStringList,int,int);

signals:
    void doneConverting();

private slots:
    void on_btn_ok_clicked();

private:
    Ui::Status *ui;
};

#endif // STATUS_H
