#include "geom_vector.h"
#include "math.h"

GeomVector::GeomVector() {}

GeomVector::GeomVector(const point &_p1, const point &_p2):
    p1(_p1), p2(_p2) { }

float GeomVector::multiply(const GeomVector &other) const
{
    auto xd = p2.x - p1.x;
    auto yd = p2.y - p1.y;
    auto zd = p2.z - p1.z;

    auto xd_other = other.p2.x - other.p1.x;
    auto yd_other = other.p2.y - other.p1.y;
    auto zd_other = other.p2.z - other.p1.z;

    return xd * xd_other + yd * yd_other + zd *zd_other;
}

float GeomVector::getLength() const
{
    auto xd = p2.x - p1.x;
    auto yd = p2.y - p1.y;
    auto zd = p2.z - p1.z;

    return sqrt(xd*xd + yd*yd + zd*zd);
}
