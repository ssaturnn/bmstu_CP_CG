#include "schenewidget.h"
#include "ui_schenewidget.h"
#include "QPainter"
#include "point.h"
#include "geom_vector.h"
#include "math.h"
#include "QWheelEvent"

// радиус сферы
const int c_sphere_radius = 50;
// координата сферы по оси Z
const int c_sphere_z = 150;
// расстояние до рамки от точки обзора
const float dist = 50;
// кордината стены
const int wall_coord = 400;

ScheneWidget::ScheneWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScheneWidget),
    m_dist(dist),
    m_xView(0),
    m_yView(0),
    m_zView(0),
    m_xRotation(0),
    m_yRotation(0),
    m_zRotation(0),
    m_sphereCenter(0, 0, c_sphere_z),
    m_sphereRadius(c_sphere_radius),
    m_leftBPressed(false),
    m_rightBPressed(false)
{
    ui->setupUi(this);
}

ScheneWidget::~ScheneWidget()
{
    delete ui;
}

void ScheneWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor coordLineColor(255, 0, 0, 255);

    QPen apen = QPen(coordLineColor);
    apen.setWidth(1);
    painter.setPen(apen);

    QRect wnd_bounds = painter.window();

    for(int i= -wnd_bounds.width()/2; i < wnd_bounds.width()/2; i++) {
        for(int j= -wnd_bounds.height()/2; j < wnd_bounds.height()/2; j++) {
            point d = CanvasToViewport(QPoint(i, j), wnd_bounds)
                    .rotateX(m_xRotation)
                    .rotateY(m_yRotation)
                    .rotateZ(m_zRotation);
            point pov(m_xView,m_yView,m_zView);
            float t;
            if (intersectsSphere(pov, d, t) && t>=1) {
               point inters_point(pov.x + d.x * t, pov.y + d.y * t, pov.z + d.z *t);
               float ints = getLightning(
                           inters_point,
                           GeomVector(m_sphereCenter, inters_point), false);
               if ((inters_point.x - m_sphereCenter.x > 0 &&
                       inters_point.z - m_sphereCenter.z < 0) ||
                       (inters_point.x - m_sphereCenter.x < 0 &&
                       inters_point.z - m_sphereCenter.z > 0)) {
                    painter.setPen(QColor(255 * ints, 0, 0, 255));
               } else {
                   painter.setPen(QColor(0, 255 * ints, 0, 255));
               }
            } else {
               point normal;
               t = findWall(pov, d, normal);
               point inters_point(pov.x + d.x * t, pov.y + d.y * t,pov.z +  d.z *t);

               float ints = getLightning(
                           inters_point,
                           GeomVector(point(0,0,0), normal), true);

               painter.setPen(QColor(0, 0, 255 * ints, 255));
            }
            painter.drawPoint(wnd_bounds.width()/2 + i, wnd_bounds.height()/2 - j);
        }
    }
}

point ScheneWidget::CanvasToViewport(const QPoint &p, const QRect& rect)
{
    int vh = 140;
    int vw = 200;
    return point(
                p.x() * vw / (float)rect.width(),
                p.y() * vh / (float)rect.height(), (
                    float)m_dist);
}

bool ScheneWidget::intersectsSphere(const point &pov, const point &ray, float& t)
{
    GeomVector pov_to_center(m_sphereCenter, pov); // OC
    GeomVector ray_vector(point(0,0,0), ray); // D
    auto k1 = ray_vector.multiply(ray_vector);
    auto k2 = 2*pov_to_center.multiply(ray_vector);
    auto k3 = pov_to_center.multiply(pov_to_center) -
            m_sphereRadius * m_sphereRadius;
    auto discriminant = k2*k2 - 4*k1*k3;
    if (discriminant < 0) return false;
    auto t1 = (-k2 + sqrt(discriminant)) / (2*k1);
    auto t2 = (-k2 - sqrt(discriminant)) / (2*k1);
    //if (t1 < 1 || t2 < 1) return false;
    t = std::min(t1, t2);
    return true;
}

float ScheneWidget::findWall(const point& pov, const point& ray, point& normal) {
    normal.x = 0;
    normal.y = 0;
    normal.z = 0;
    float t1 = (wall_coord - pov.x) / ray.x;
    float t2 = (-wall_coord - pov.x) / ray.x;
    float t3 = (wall_coord - pov.y) / ray.y;
    float t4 = (-wall_coord - pov.y) / ray.y;
    float t5 = (wall_coord - pov.z) / ray.z;
    float t6 = (-wall_coord - pov.z) / ray.z;
    float final = 10000000;
    if (t1 < final && t1 >= 1) {
        final = t1;
        normal.y = 0;
        normal.z = 0;
        normal.x = -1;
    }
    if (t2 < final && t2 >= 1) {
        final = t2;
        normal.y = 0;
        normal.z = 0;
        normal.x = 1;
    }
    if (t3 < final && t3 >= 1) {
        final = t3;
        normal.x = 0;
        normal.z = 0;
        normal.y = -1;
    }
    if (t4 < final && t4 >= 1) {
        final = t4;
        normal.x = 0;
        normal.z = 0;
        normal.y = 1;
    }
    if (t5 < final && t5 >= 1) {
        final = t5;
        normal.y = 0;
        normal.x = 0;
        normal.z = -1;
    }
    if (t6 < final && t6 >= 1) {
        final = t6;
        normal.y = 0;
        normal.x = 0;
        normal.z = 1;
    }
    return final;
}

void ScheneWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_leftBPressed = true;
    } else if (event->button() == Qt::RightButton) {
        m_rightBPressed = true;
    }
    m_xPressed = event->x();
    m_yPressed = event->y();
}

void ScheneWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_leftBPressed = false;
    } else if (event->button() == Qt::RightButton) {
        m_rightBPressed = false;
    }
}

void ScheneWidget::mouseMoveEvent(QMouseEvent *event)
{
    point p(m_xPressed - event->x(), m_yPressed - event->y(), 0);
    p.rotateX(m_xRotation).rotateY(m_yRotation).rotateZ(m_zRotation);
    if (m_rightBPressed) {
        m_xView += p.x;
        m_yView += p.y;
        m_zView += p.z;
    } else if (m_leftBPressed) {
        m_xRotation += p.y / 360;
        m_yRotation += p.z / 360;
        m_zRotation += p.x / 360;
    }
    repaint();
    m_xPressed = event->x();
    m_yPressed = event->y();
}

// освещение и цени
float ScheneWidget::getLightning(const point &surface_point, const GeomVector& normal, bool with_shadows)
{
    float final = 0.2;
    const float intensity = 0.4;

    {
        const point light_position(200, -100, 100);
        point ray(light_position.x - surface_point.x,
                  light_position.y - surface_point.y,
                  light_position.z - surface_point.z); // L
        float f_dummy = 0;
        if (with_shadows && !intersectsSphere(surface_point, ray, f_dummy) || f_dummy > 1 || f_dummy == 0) {
            GeomVector light_vector(surface_point, light_position);
            auto n_dot_l = normal.multiply(light_vector) / normal.getLength();
            if (n_dot_l > 0) {
                final += intensity * n_dot_l / light_vector.getLength();
            }
        }
    }

    {
        const point light_position(-100, 100, 100);
        point ray(light_position.x - surface_point.x,
                  light_position.y - surface_point.y,
                  light_position.z - surface_point.z);
        float f_dummy = 0;
        if (with_shadows && !intersectsSphere(surface_point, ray, f_dummy) || f_dummy > 1 || f_dummy == 0) {
            GeomVector light_vector(surface_point, light_position);
            auto n_dot_l = normal.multiply(light_vector) / normal.getLength();
            if (n_dot_l > 0) {
                final += intensity * n_dot_l / light_vector.getLength();
            }
       }
    }
    return final;
}

