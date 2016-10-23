#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int min_x{static_cast<int>(0.5*this->height())};
    int max_x{static_cast<int>(1.0*this->height())};

    int pos_x{static_cast<int>(0.75*this->height())};
    int delta_x{5};

    double cent_x{0.5*this->width()};
    double cent_y{0.5*this->height()};

    double radius{0.25*this->width()};

    double phi{0};

    double dial_x{0};
    double dial_y{0};

    bool init{true};

private slots:
    void on_pushButton_clicked();
    void OnClick();
    void keyPressEvent(QKeyEvent *);
    void paintEvent(QPaintEvent*);
    void shakar(QPainter& painter);
    void circling();

private:    

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
