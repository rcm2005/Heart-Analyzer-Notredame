

#include "point.h"



#ifndef POINT_H_
#define POINT_H_

class point {
private:
    int m_x;
    int m_y;

public:
    // Default constructor
    point() : m_x(0), m_y(0) {}

    // Parameterized constructor
    point(int x, int y) : m_x(x), m_y(y) {}
};

#endif  // POINT_H_
