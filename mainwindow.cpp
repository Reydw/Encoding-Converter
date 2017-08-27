#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

QStringList inputFiles;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList encodings;
    encodings<<"UTF-8"<<"ISO 8859-1"<<"ISO 8859-2"<<"ISO 8859-3"<<"ISO 8859-4"<<"ISO 8859-5"<<"ISO 8859-6"<<"ISO 8859-7"<<"ISO 8859-8"<<"ISO 8859-9"<<"ISO 8859-10"<<"ISO 8859-13"<<"ISO 8859-14"<<"ISO 8859-15"<<"ISO 8859-16";
    ui->sourceEncoding->addItems(encodings);
    ui->destinationEncoding->addItems(encodings);
    status = new Status(this);
    status->setModal(true);
    connect(this, SIGNAL(openDialog(QStringList)), status, SLOT(convert(QStringList)));
    connect(status, SIGNAL(doneConverting()), this, SLOT(doneConverting()));
}

void MainWindow::on_openFiles_clicked()
{
    QString caption = "Select files";
    QString dir = QDir::homePath();
    QString filter = "Files (*.*)";

    inputFiles = QFileDialog::getOpenFileNames(this, caption, dir, filter);
    if(inputFiles.isEmpty())return;
    ui->selectedFiles->clear();
    ui->selectedFiles->addItems(inputFiles);
}

void MainWindow::on_convert_clicked()
{
    status->show();
    openDialog(inputFiles);
}

void MainWindow::doneConverting() {
    ui->selectedFiles->clear();
    inputFiles.clear();
}

MainWindow::~MainWindow(){delete ui;}
