#include "vector.hpp"

/* operators of class Vector */
Vector&  Vector::operator= (const Vector &vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    return *this;
}

Vector&  Vector::operator+=(const Vector &vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}

Vector&  Vector::operator-=(const Vector &vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    return *this;
}

Vector&  Vector::operator*=(const Vector &vec)
{
    x *= vec.x;
    y *= vec.y;
    z *= vec.z;
    return *this;
}

Vector&  Vector::operator/=(const Vector &vec)
{
    x /= vec.x;
    y /= vec.y;
    z /= vec.z;
    return *this;
}

Vector&  Vector::operator+=(const double &val)
{
    x += val;
    y += val;
    z += val;
    return *this;
}

Vector&  Vector::operator-=(const double &val)
{
    x -= val;
    y -= val;
    z -= val;
    return *this;
}

Vector&  Vector::operator*=(const double &val)
{
    x *= val;
    y *= val;
    z *= val;
    return *this;
}

Vector&  Vector::operator/=(const double &val)
{
    x /= val;
    y /= val;
    z /= val;
    return *this;
}

Vector  operator+(const Vector &vec)
{ return Vector(vec); }

Vector  operator-(const Vector &vec)
{ return Vector(-vec.x, -vec.y, -vec.z); }

Vector  operator+(const Vector &vec1, const Vector &vec2)
{ return Vector(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z); }

Vector  operator-(const Vector &vec1, const Vector &vec2)
{ return Vector(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z); }

Vector  operator*(const Vector &vec1, const Vector &vec2)
{ return Vector(vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z); }

Vector  operator/(const Vector &vec1, const Vector &vec2)
{ return Vector(vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z); }

Vector  operator+(const Vector &vec, const double &val)
{ return Vector(vec.x + val, vec.y + val, vec.z + val); }

Vector  operator-(const Vector &vec, const double &val)
{ return Vector(vec.x - val, vec.y - val, vec.z - val); }

Vector  operator*(const Vector &vec, const double &val)
{ return Vector(vec.x * val, vec.y * val, vec.z * val); }

Vector  operator/(const Vector &vec, const double &val)
{ return Vector(vec.x / val, vec.y / val, vec.z / val); }

Vector  operator+(const double &val, const Vector &vec)
{ return Vector(val + vec.x, val + vec.y, val + vec.z); }

Vector  operator-(const double &val, const Vector &vec)
{ return Vector(val - vec.x, val - vec.y, val - vec.z); }

Vector  operator*(const double &val, const Vector &vec)
{ return Vector(val * vec.x, val * vec.y, val * vec.z); }

Vector  operator/(const double &val, const Vector &vec)
{ return Vector(val / vec.x, val / vec.y, val / vec.z); }

/* dot product */
double  operator%(const Vector &vec1, const Vector &vec2)
{ return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z; }

/* cross product */
Vector  cross_product(const Vector &vec1, const Vector &vec2)
{
    return Vector( vec1.y * vec2.z - vec1.z * vec2.y,
                   vec1.z * vec2.x - vec1.x * vec2.z,
                   vec1.x * vec2.y - vec1.y * vec2.x );
}