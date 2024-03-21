#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class GeomVector;

#include <QMainWindow>
#include <schenewidget.h>
//#include "point.h"


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

    void on_xMoveSlider_valueChanged(int value);

    void on_yMoveSlider_valueChanged(int value);

    void on_zMoveSlider_valueChanged(int value);

    void on_zRotate_valueChanged(int value);

    void on_xRotate_valueChanged(int value);

    void on_yRotate_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    ScheneWidget* m_sw;

    bool m_freeze;

    // QObject interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
