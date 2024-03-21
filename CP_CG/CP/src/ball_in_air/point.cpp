#include "point.h"
#include "math.h"

point::point() {}

point::point(float _x, float _y, float _z):
    x(_x), y(_y), z(_z) { }

point &point::rotateX(float angle)
{
    float newy = y* std::cos(angle) - z * std::sin(angle);
    float newz = y * std::sin(angle) + z * std::cos(angle);
    y = newy;
    z = newz;
    return *this;
}

point &point::rotateY(float angle)
{
    float newx = x* std::cos(angle) - z * std::sin(angle);
    float newz = x * std::sin(angle) + z * std::cos(angle);
    x = newx;
    z = newz;
    return *this;
}

point &point::rotateZ(float angle)
{
    float newx = x* std::cos(angle) - y * std::sin(angle);
    float newy = x * std::sin(angle) + y * std::cos(angle);
    x = newx;
    y = newy;
    return *this;
}
