/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSlider *zMoveSlider;
    QSlider *xMoveSlider;
    QSlider *yMoveSlider;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSlider *zRotate;
    QSlider *xRotate;
    QSlider *yRotate;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1082, 619);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(840, 10, 231, 111));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 21, 17));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 50, 21, 17));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 70, 16, 17));
        zMoveSlider = new QSlider(groupBox);
        zMoveSlider->setObjectName("zMoveSlider");
        zMoveSlider->setGeometry(QRect(30, 70, 160, 16));
        zMoveSlider->setMinimum(-400);
        zMoveSlider->setMaximum(400);
        zMoveSlider->setSingleStep(1);
        zMoveSlider->setOrientation(Qt::Horizontal);
        xMoveSlider = new QSlider(groupBox);
        xMoveSlider->setObjectName("xMoveSlider");
        xMoveSlider->setGeometry(QRect(30, 30, 160, 16));
        xMoveSlider->setMinimum(-400);
        xMoveSlider->setMaximum(400);
        xMoveSlider->setOrientation(Qt::Horizontal);
        yMoveSlider = new QSlider(groupBox);
        yMoveSlider->setObjectName("yMoveSlider");
        yMoveSlider->setGeometry(QRect(30, 50, 160, 16));
        yMoveSlider->setMinimum(-400);
        yMoveSlider->setMaximum(400);
        yMoveSlider->setOrientation(Qt::Horizontal);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(840, 140, 231, 111));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 30, 21, 17));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 50, 21, 17));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 70, 16, 17));
        zRotate = new QSlider(groupBox_2);
        zRotate->setObjectName("zRotate");
        zRotate->setGeometry(QRect(30, 70, 160, 16));
        zRotate->setMinimum(-314);
        zRotate->setMaximum(314);
        zRotate->setSingleStep(0);
        zRotate->setOrientation(Qt::Horizontal);
        xRotate = new QSlider(groupBox_2);
        xRotate->setObjectName("xRotate");
        xRotate->setGeometry(QRect(30, 30, 160, 16));
        xRotate->setMinimum(-314);
        xRotate->setMaximum(314);
        xRotate->setOrientation(Qt::Horizontal);
        yRotate = new QSlider(groupBox_2);
        yRotate->setObjectName("yRotate");
        yRotate->setGeometry(QRect(30, 50, 160, 16));
        yRotate->setMinimum(-314);
        yRotate->setMaximum(314);
        yRotate->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(840, 260, 231, 25));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Z:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Z:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\265 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
