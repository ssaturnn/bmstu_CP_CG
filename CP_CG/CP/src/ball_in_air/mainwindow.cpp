#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_sw(new ScheneWidget(this)),
    m_freeze(false)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_xMoveSlider_valueChanged(int value)
{
    m_sw->m_xView = value;
    if(!m_freeze) m_sw->repaint();
}

void MainWindow::on_yMoveSlider_valueChanged(int value)
{
    m_sw->m_yView = value;
    if(!m_freeze) m_sw->repaint();
}

void MainWindow::on_zMoveSlider_valueChanged(int value)
{
    m_sw->m_zView = value;
    if(!m_freeze) m_sw->repaint();
}

void MainWindow::on_zRotate_valueChanged(int value)
{
    m_sw->m_zRotation = value / 100.0;
    if(!m_freeze) m_sw->repaint();
}

void MainWindow::on_xRotate_valueChanged(int value)
{
    m_sw->m_xRotation = value / 100.0;
    if(!m_freeze) m_sw->repaint();
}

void MainWindow::on_yRotate_valueChanged(int value)
{
    m_sw->m_yRotation = value / 100.0;
    if(!m_freeze) m_sw->repaint();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    m_sw->mousePressEvent(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_sw->mouseReleaseEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    m_sw->mouseMoveEvent(event);
}

void MainWindow::on_pushButton_clicked()
{
    m_freeze = true;
    ui->xMoveSlider->setValue(0);
    m_sw->m_xView = 0;
    m_sw->m_yView = 0;
    m_sw->m_zView = 0;
    ui->yMoveSlider->setValue(0);
    ui->zMoveSlider->setValue(0);
    ui->xRotate->setValue(0);
    ui->yRotate->setValue(0);
    ui->zRotate->setValue(0);
    m_sw->m_xRotation = 0;
    m_sw->m_yRotation = 0;
    m_sw->m_zRotation = 0;
    m_freeze = false;
    m_sw->repaint();
}
