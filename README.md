# MathLib

## Description

MathLib is a code implement of commonly used mathematical tools.

## Install

Codes in this repository can be compiled by most C++ compilers. 
Before using these codes, you can test compatibility with the 
following commands.

```bash
cd mathlib
make clean
make
./bin/mathlib-test
```

## Usage

If you want to use any classes or functions in your project, 
you just need to copy `.hpp` file and corresponding `.cpp` file. 
Let's introduce the specific usage of different modules.

### `Vector` class

`Vector` is a class representing vectors in a three-dimensional 
space. In this class, there are three members, `x`, `y` and `z` 
represents the three components in space. There are some methods 
and operators defined in the class. See the example below for 
specific usage.

#### Examples

```cpp
/* define vectors */
Vector v1(1.0, 2.0, 3.0);
Vector v2(4.0, 5.0, 6.0);
Vector v3 = v1;

/* positive and negative */
v3 = +v1;       // v3 --> Vector(1.0, 2.0, 3.0);
v3 = -v1;       // v3 --> Vector(-1.0, -2.0, -3.0);

/* operation between corresponding elements */
v3 = v1 + v2;   // v3 --> Vector(5.0, 7.0, 9.0);
v3 = v1 - v2;   // v3 --> Vector(-3.0, -3.0, -3.0);
v3 = v1 * v2;   // v3 --> Vector(4.0, 10.0, 18.0);
v3 = v1 / v2;   // v3 --> Vector(0.25, 0.4, 0.5);

double val = 5.0;

/* Vector and a double value */
v3 = v1 + val;  // v3 --> Vector(6.0, 7.0, 8.0);
v3 = v1 - val;  // v3 --> Vector(-4.0, -3.0, -1.0);
v3 = v1 * val;  // v3 --> Vector(5.0, 10.0, 15.0);
v3 = v1 / val;  // v3 --> Vector(0.2, 0.4, 0.6);
v3 = val + v1;  // v3 --> Vector(6.0, 7.0, 8.0);
v3 = val - v1;  // v3 --> Vector(4.0, 3.0, 1.0);
v3 = val * v1;  // v3 --> Vector(5.0, 10.0, 15.0);
v3 = val / v1;  // v3 --> Vector(0.5, 2.5, 1.67);

/* += -= *= /= */
v1 += v2;       // v1 --> Vector(5.0, 7.0, 9.0);
v1 -= v2;       // v1 --> Vector(1.0, 2.0, 3.0);
v1 *= v2;       // v1 --> Vector(4.0, 10.0, 18.0);
v1 /= v2;       // v1 --> Vector(1.0, 2.0, 3.0);
v1 += val;      // v1 --> Vector(6.0, 7.0, 8.0);
v1 -= val;      // v1 --> Vector(1.0, 2.0, 3.0);
v1 *= val;      // v1 --> Vector(5.0, 10.0, 15.0);
v1 /= val;      // v1 --> Vector(1.0, 2.0, 3.0);


/* dot product */
double ans = v1 % v2;  // ans --> 32.0

/* cross product */
v3 = cross_product(v1, v2);  // v3 --> Vector(-3.0, 6.0, -3.0);

/* member functions */
double length = v1.len();   // length of v1, length --> 3.74
```

### `Matrix` class

`Matrix` is a class representing Matrices. There are some 
methods and operators defined in the class. See the example 
below for specific usage.

#### Examples

```cpp
double ans = 0.0;

/* define matrices*/
const size_t nRow = 2;
const size_t nCol = 3;
const double data1[] = {1, 2, 3, 3, 2, 1};
const double data2[] = {4, 5, 6, 4, 5, 6};
Matrix m1(nRow, nCol, data1);      // m1 --> [ [1 2 3]; [3 2 1] ]
Matrix m2(nRow, nCol, data2);      // m2 --> [ [4 5 6]; [4 5 6] ]
Matrix m3 = m1;

/* positive and negative */
m3 = +m1;       // m3 --> [ [1 2 3]; [3 2 1] ]
m3 = -m1;       // m3 --> [ [-1 -2 -3]; [-3 -2 -1] ]

/* operation between corresponding elements */
m3 = m1 + m2;   // m3 --> [ [5 7 9]; [7 7 7] ]
m3 = m1 - m2;   // m3 --> [ [-3 -3 -3]; [-1 -3 -5] ]
m3 = m1 * m2;   // m3 --> [ [4 10 18]; [12 10 6] ]
m3 = m1 / m2;   // m3 --> [ [0.25 0.4 0.5]; [0.75 0.4 0.167] ]

double val = 5.0;

/* Matrix and a double value */
m3 = m1 + val;  // m3 --> [ [6 7 8]; [8 7 6] ]
m3 = m1 - val;  // m3 --> [ [-4 -3 -2]; [-2 -3 -4] ]
m3 = m1 * val;  // m3 --> [ [5 10 15]; [15 10 5] ]
m3 = m1 / val;  // m3 --> [ [0.2 0.4 0.6]; [0.6 0.4 0.2] ]
m3 = val + m1;  // m3 --> [ [6 7 8]; [8 7 6] ]
m3 = val - m1;  // m3 --> [ [4 3 2]; [2 3 4] ]
m3 = val * m1;  // m3 --> [ [5 10 15]; [15 10 5] ]
m3 = val / m1;  // m3 --> [ [5 2.5 1.67]; [1.67 2.5 5] ]

/* matrix product */
m3 = m1 % m2.trans();   // m3 --> [ [32 32]; [28 28] ]

/* += -= *= /=  %= */
m1 += m2;           // m1 --> [ [5 7 9]; [7 7 7] ]
m1 -= m2;           // m1 --> [ [1 2 3]; [3 2 1] ]
m1 *= m2;           // m1 --> [ [4 10 18]; [12 10 6] ]
m1 /= m2;           // m1 --> [ [1 2 3]; [3 2 1] ]
m1 += val;          // m1 --> [ [6 7 8]; [8 7 6] ]
m1 -= val;          // m1 --> [ [1 2 3]; [3 2 1] ]
m1 *= val;          // m1 --> [ [5 10 15]; [15 10 5] ]
m1 /= val;          // m1 --> [ [1 2 3]; [3 2 1] ]
m1 %= m2.trans();   // m1 --> [ [32 32]; [28 28] ]

/* member functions */
m3 = m1.trans();    // m3 --> [ [1 3]; [2 2]; [3 1] ]

/* define a square matrix*/
const size_t nDim = 3;
const double data[] = {8, 1, 6, 3, 5, 7, 4, 9, 2};  // magic(3)
Matrix square(nDim, nDim, data);

/* member functions for square matrices*/
m3 = square.inv();      // m3 % square == square % m3 == Identity
ans = square.trace();   // ans --> 15
```

## Author

## Reporting Bugs

## Copyright