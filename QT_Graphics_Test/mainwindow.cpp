#include "mainwindow.h"

#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(OnClick()));
    {
        QTimer * const timer{new QTimer(this)};
        QObject::connect(timer, SIGNAL(timeout()),this,SLOT(repaint()));
        timer->start(100);

        min_x = static_cast<int>(0.5*this->height());
        max_x = static_cast<int>(1.0*this->height());

        pos_x = static_cast<int>(0.75*this->height());
    }
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
    if (init)
    {


        init = false;
    }


    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    painter.drawEllipse(100, 120, 300, 100);


    shakar(painter);





    painter.setPen(QPen(Qt::green, 10, Qt::SolidLine, Qt::RoundCap));

    pos_x += delta_x;
    painter.drawText(pos_x, pos_x, "x");

    if (pos_x < min_x || pos_x > max_x)
    {
        delta_x *= -1;
    }
}

void MainWindow::shakar(QPainter& painter)
{

    painter.setPen(QPen(Qt::yellow, 10, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(300, 250, 50, 100);

}
