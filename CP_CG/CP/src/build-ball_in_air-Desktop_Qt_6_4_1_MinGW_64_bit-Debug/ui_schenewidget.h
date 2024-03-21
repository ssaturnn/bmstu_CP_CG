/********************************************************************************
** Form generated from reading UI file 'schenewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHENEWIDGET_H
#define UI_SCHENEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScheneWidget
{
public:

    void setupUi(QWidget *ScheneWidget)
    {
        if (ScheneWidget->objectName().isEmpty())
            ScheneWidget->setObjectName("ScheneWidget");
        ScheneWidget->resize(839, 596);

        retranslateUi(ScheneWidget);

        QMetaObject::connectSlotsByName(ScheneWidget);
    } // setupUi

    void retranslateUi(QWidget *ScheneWidget)
    {
        ScheneWidget->setWindowTitle(QCoreApplication::translate("ScheneWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScheneWidget: public Ui_ScheneWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHENEWIDGET_H
