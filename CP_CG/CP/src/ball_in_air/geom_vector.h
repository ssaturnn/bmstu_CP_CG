#ifndef VECTOR_H
#define VECTOR_H

#include "point.h"

class GeomVector
{
public:
    GeomVector();
    GeomVector(const point& _p1, const point& _p2);
    float multiply(const GeomVector& other) const;
    float getLength() const;
    point p1;
    point p2;
};

#endif // VECTOR_H
