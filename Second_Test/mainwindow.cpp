#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(OnClick()));

    // QObject::connect(ui->checkBox,SIGNAL(toggled(bool)),this,SLOT(showMaximized()));
    // QObject::connect(ui->checkBox,SIGNAL(isChecked(bool)),this,SLOT(showMaximized()));
    // QObject::connect(ui->checkBox,SIGNAL(isUnchecked(bool)),this,SLOT(showMaximized()));
    // QObject::connect(ui->checkBox,SIGNAL(released()),this,SLOT(showNormal()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
