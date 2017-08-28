#include "status.h"
#include "ui_status.h"
#include "encodings.h"

Status::Status(QWidget *parent) : QDialog(parent), ui(new Ui::Status)
{
    ui->setupUi(this);
}

void Status::on_btn_ok_clicked()
{
    ui->btn_ok->setEnabled(false);
    this->hide();
}

void Status::convert(QStringList inputFiles, int source, int destination) {
    if(inputFiles.isEmpty()) {
        ui->label->setText("Nothing to convert");
        ui->btn_ok->setEnabled(true);
        return;
    }
    if(source == destination) {
        ui->label->setText("Selected encodings are the same");
        ui->btn_ok->setEnabled(true);
        return;
    }

    QString caption = "Select output directory";
    QString defaultDir = QDir::homePath();
    QFileDialog::Options options = QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks;

    QString outputDir = (QFileDialog::getExistingDirectory(this, caption, defaultDir, options));
    if(outputDir.isEmpty()) {
        ui->label->setText("Select the output directory");
        ui->btn_ok->setEnabled(true);
        return;
    }

    outputDir.append("/");
    ui->label->setText("Converting...");

    int numberOfFiles = inputFiles.length();
    char buffer;
    for(int i=0;i<numberOfFiles;i++) {
        QFile inputFile(inputFiles.at(i));
        QString outputFileName = QFileInfo(inputFile).fileName();
        QFile newFile(outputDir+outputFileName);

        inputFile.open(QIODevice::ReadOnly);
        newFile.open(QIODevice::WriteOnly);
        ui->label_2->setText(outputFileName);

        QDataStream input(&inputFile);
        QDataStream output(&newFile);
        Encodings encodings(&output);

        while(input.readRawData(&buffer, 1))
            encodings.universalEncoding(buffer, source, destination);

        inputFile.close();
        newFile.close();
    }

    ui->label->setText("Convertion Complete");
    ui->label_2->setText("");
    ui->btn_ok->setEnabled(true);
    doneConverting();
}

Status::~Status(){delete ui;}
