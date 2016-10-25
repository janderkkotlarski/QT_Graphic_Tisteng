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

        cent_x = 0.5*this->width();
        cent_y = 0.5*this->height();

        if (cent_x < cent_y)
        {
            radius = 0.25*this->width();
        }
        else
        {
            radius = 0.25*this->height();
        }

    }

    // ui->dial->pos()& = new QPoint(9, 9);
    // ui->dial->pos().setY(static_cast<int>(0));
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

void MainWindow::circling()
{
    dial_x = cent_x;
    dial_y = cent_y;


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


    const int radius{ui->dial_2->sliderPosition()};
    const int phi{static_cast<int>(static_cast<float>(ui->dial->sliderPosition())/0.01)};

    const char ratius{static_cast<char>(radius)};

    const int x_pos{static_cast<int>(cent_x + radius*cos(phi))};
    const int y_pos{static_cast<int>(cent_y + radius*sin(phi))};



    painter.drawText(x_pos, y_pos, "*");


    painter.drawRect(400, 200, 100, 50);


    painter.drawArc(cent_x, cent_y, radius, radius, 0, phi);

    painter.drawEllipse(100, 50, 20, 40);

    QPoint m_pos = this->mapFromParent(QCursor::pos());

    QPoint n_pos;

    n_pos.rx() = m_pos.ry();
    n_pos.ry() = m_pos.rx();



    painter.drawText(m_pos, "achterlijk");

    painter.drawText(n_pos, "Choukai suki da!");

    circling();
}

void MainWindow::shakar(QPainter& painter)
{

    painter.setPen(QPen(Qt::yellow, 10, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(300, 250, 50, 100);

}
