#include "mainwindow.h"

#include <QKeyEvent>
#include <QPainter>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(OnClick()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("Konnichiwa");
}

void MainWindow::OnClick()
{
    ui->label->setText("Konbanwa");
}


void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_1)
    {
        ui->label->setText("Umai");
    }

    if (event->key() == Qt::Key_Escape)
    {
        close();
    }

}


void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    painter.drawEllipse(100, 120, 300, 100);

    painter.setPen(QPen(Qt::green, 10, Qt::SolidLine, Qt::RoundCap));

    painter.drawText(100, 100, "x");


}
