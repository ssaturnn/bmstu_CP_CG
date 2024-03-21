#ifndef POINT_H
#define POINT_H


class point
{
public:
    point();
    point(float _x, float _y, float _z);
    // вращение вокруг X
    point& rotateX(float angle);
    // вращение вокург Y
    point& rotateY(float angle);
    // вращение вокруг Z
    point& rotateZ(float angle);
    float x;
    float y;
    float z;
};

#endif // POINT_H
