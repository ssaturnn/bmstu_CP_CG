#ifndef SCHENEWIDGET_H
#define SCHENEWIDGET_H

class GeomVector;

#include <QWidget>
#include "point.h"

namespace Ui {
class ScheneWidget;
}

class ScheneWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScheneWidget(QWidget *parent = 0);
    ~ScheneWidget();

    float m_xView;
    float m_yView;
    float m_zView;

    float m_xRotation;
    float m_yRotation;
    float m_zRotation;

    bool m_leftBPressed;
    bool m_rightBPressed;

    int m_xPressed;
    int m_yPressed;

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::ScheneWidget *ui;
    void paintEvent(QPaintEvent *);

    point m_sphereCenter;
    int m_sphereRadius;

    float m_dist;
    // получить координаты на рамке по координате канвы
    point CanvasToViewport(const QPoint& p, const QRect& rect);
    // пересечение со сферой
    bool intersectsSphere(const point& pov, const point& ray, float& t);
    // получение коэффициента освещения, учитывая тени
    float getLightning(const point& surface_point, const GeomVector& normal, bool with_shadows);
    // найти стенку и её нормаль
    float findWall(const point& pov, const point& ray, point& normal);
};

#endif // SCHENEWIDGET_H
