#ifndef MATHLIB_VECTOR_HPP
#define MATHLIB_VECTOR_HPP

#include <cmath>

class Vector {
public:
    double  x, y, z;

    Vector(void) : x(0), y(0), z(0) {}
    Vector(double x, double y, double z) : x(x), y(y), z(z) {}
    Vector(const Vector &vec) : x(vec.x), y(vec.y), z(vec.z) {}
    ~Vector(void) {}

    double  len() const { return std::sqrt(x*x + y*y + z*z); }

    /* operators */
    Vector&  operator= (const Vector &vec);
    Vector&  operator+=(const Vector &vec);
    Vector&  operator-=(const Vector &vec);
    Vector&  operator*=(const Vector &vec);
    Vector&  operator/=(const Vector &vec);
    Vector&  operator+=(const double &val);
    Vector&  operator-=(const double &val);
    Vector&  operator*=(const double &val);
    Vector&  operator/=(const double &val);
};

Vector  operator+(const Vector &vec);
Vector  operator-(const Vector &vec);
Vector  operator+(const Vector &vec1, const Vector &vec2);
Vector  operator-(const Vector &vec1, const Vector &vec2);
Vector  operator*(const Vector &vec1, const Vector &vec2);
Vector  operator/(const Vector &vec1, const Vector &vec2);
Vector  operator+(const Vector &vec, const double &val);
Vector  operator-(const Vector &vec, const double &val);
Vector  operator*(const Vector &vec, const double &val);
Vector  operator/(const Vector &vec, const double &val);
Vector  operator+(const double &val, const Vector &vec);
Vector  operator-(const double &val, const Vector &vec);
Vector  operator*(const double &val, const Vector &vec);
Vector  operator/(const double &val, const Vector &vec);

/* dot product */
double  operator%(const Vector &vec1, const Vector &vec2);

/* cross product */
Vector  cross_product(const Vector &vec1, const Vector &vec2);

#endif  // MATHLIB_VECTOR_HPP