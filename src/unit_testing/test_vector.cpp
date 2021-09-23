#include "vector.hpp"

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Determine whether two numbers or two vectors are equal
bool eq(const double &a, const double &b, double eps = 1e-6);
bool eq(const Vector &a, const Vector &b);

int main(int argc, char **argv)
{
    double val = 5.0;
    vector<Vector> v1;
    vector<Vector> v2;
    vector<Vector> positive_v1;     // + v1;
    vector<Vector> negative_v1;     // - v1;
    vector<Vector> v1_plus_v2;      // v1 + v2
    vector<Vector> v1_minu_v2;      // v1 - v2
    vector<Vector> v1_mult_v2;      // v1 * v2
    vector<Vector> v1_divi_v2;      // v1 / v2
    vector<Vector> v1_plus_val;     // v1 + val
    vector<Vector> v1_minu_val;     // v1 - val
    vector<Vector> v1_mult_val;     // v1 * val
    vector<Vector> v1_divi_val;     // v1 / val
    vector<Vector> val_plus_v1;     // val + v2
    vector<Vector> val_minu_v1;     // val - v2
    vector<Vector> val_mult_v1;     // val * v2
    vector<Vector> val_divi_v1;     // val / v2
    vector<double> v1_dot_v2;       // v1 dot product v2
    vector<Vector> v1_cross_v2;     // v1 cross product v2

    v1.push_back( Vector(  5.0,   3.3,   2.9) );
    v1.push_back( Vector( -1.0,   1.3,  78.0) );
    v1.push_back( Vector(  0.5,  -2.4,   1.3) );
    v1.push_back( Vector( 12.0,  50.8,  -6.5) );
    v1.push_back( Vector( 20.0, -39.0, -23.5) );
    v1.push_back( Vector(-17.7,   0.3, -24.6) );
    v1.push_back( Vector(-15.7,  -0.9,   2.8) );
    v1.push_back( Vector(-17.0,  -0.3, -24.6) );
    v1.push_back( Vector(  5.0,   3.3,   2.9) );
    v1.push_back( Vector( -1.0,   1.3,  78.0) );
    v1.push_back( Vector(  0.5,  -2.4,   1.3) );
    v1.push_back( Vector( 12.0,  50.8,  -6.5) );
    v1.push_back( Vector( 20.0, -39.0, -23.5) );
    v1.push_back( Vector(-17.7,   0.3, -24.6) );
    v1.push_back( Vector(-15.7,  -0.9,   2.8) );
    v1.push_back( Vector(-17.0,  -0.3, -24.6) );

    v2.push_back( Vector( 20.0, -39.0, -23.5) );
    v2.push_back( Vector(-17.7,   0.3, -24.6) );
    v2.push_back( Vector(-15.7,  -0.9,   2.8) );
    v2.push_back( Vector(-17.0,  -0.3, -24.6) );
    v2.push_back( Vector(  5.0,   3.3,   2.9) );
    v2.push_back( Vector( -1.0,   1.3,  78.0) );
    v2.push_back( Vector(  0.5,  -2.4,   1.3) );
    v2.push_back( Vector( 12.0,  50.8,  -6.5) );
    v2.push_back( Vector(-15.7,  -0.9,   2.8) );
    v2.push_back( Vector(-17.0,  -0.3, -24.6) );
    v2.push_back( Vector( 20.0, -39.0, -23.5) );
    v2.push_back( Vector(-17.7,   0.3, -24.6) );
    v2.push_back( Vector(  0.5,  -2.4,   1.3) );
    v2.push_back( Vector( 12.0,  50.8,  -6.5) );
    v2.push_back( Vector(  5.0,   3.3,   2.9) );
    v2.push_back( Vector( -1.0,   1.3,  78.0) );

    v1_cross_v2.push_back( Vector( (  3.3)*(-23.5) - (  2.9)*(-39.0), (  2.9)*( 20.0) - (  5.0)*(-23.5), (  5.0)*(-39.0) - (  3.3)*( 20.0) ) );
    v1_cross_v2.push_back( Vector( (  1.3)*(-24.6) - ( 78.0)*(  0.3), ( 78.0)*(-17.7) - ( -1.0)*(-24.6), ( -1.0)*(  0.3) - (  1.3)*(-17.7) ) );
    v1_cross_v2.push_back( Vector( ( -2.4)*(  2.8) - (  1.3)*( -0.9), (  1.3)*(-15.7) - (  0.5)*(  2.8), (  0.5)*( -0.9) - ( -2.4)*(-15.7) ) );
    v1_cross_v2.push_back( Vector( ( 50.8)*(-24.6) - ( -6.5)*( -0.3), ( -6.5)*(-17.0) - ( 12.0)*(-24.6), ( 12.0)*( -0.3) - ( 50.8)*(-17.0) ) );
    v1_cross_v2.push_back( Vector( (-39.0)*(  2.9) - (-23.5)*(  3.3), (-23.5)*(  5.0) - ( 20.0)*(  2.9), ( 20.0)*(  3.3) - (-39.0)*(  5.0) ) );
    v1_cross_v2.push_back( Vector( (  0.3)*( 78.0) - (-24.6)*(  1.3), (-24.6)*( -1.0) - (-17.7)*( 78.0), (-17.7)*(  1.3) - (  0.3)*( -1.0) ) );
    v1_cross_v2.push_back( Vector( ( -0.9)*(  1.3) - (  2.8)*( -2.4), (  2.8)*(  0.5) - (-15.7)*(  1.3), (-15.7)*( -2.4) - ( -0.9)*(  0.5) ) );
    v1_cross_v2.push_back( Vector( ( -0.3)*( -6.5) - (-24.6)*( 50.8), (-24.6)*( 12.0) - (-17.0)*( -6.5), (-17.0)*( 50.8) - ( -0.3)*( 12.0) ) );
    v1_cross_v2.push_back( Vector( (  3.3)*(  2.8) - (  2.9)*( -0.9), (  2.9)*(-15.7) - (  5.0)*(  2.8), (  5.0)*( -0.9) - (  3.3)*(-15.7) ) );
    v1_cross_v2.push_back( Vector( (  1.3)*(-24.6) - ( 78.0)*( -0.3), ( 78.0)*(-17.0) - ( -1.0)*(-24.6), ( -1.0)*( -0.3) - (  1.3)*(-17.0) ) );
    v1_cross_v2.push_back( Vector( ( -2.4)*(-23.5) - (  1.3)*(-39.0), (  1.3)*( 20.0) - (  0.5)*(-23.5), (  0.5)*(-39.0) - ( -2.4)*( 20.0) ) );
    v1_cross_v2.push_back( Vector( ( 50.8)*(-24.6) - ( -6.5)*(  0.3), ( -6.5)*(-17.7) - ( 12.0)*(-24.6), ( 12.0)*(  0.3) - ( 50.8)*(-17.7) ) );
    v1_cross_v2.push_back( Vector( (-39.0)*(  1.3) - (-23.5)*( -2.4), (-23.5)*(  0.5) - ( 20.0)*(  1.3), ( 20.0)*( -2.4) - (-39.0)*(  0.5) ) );
    v1_cross_v2.push_back( Vector( (  0.3)*( -6.5) - (-24.6)*( 50.8), (-24.6)*( 12.0) - (-17.7)*( -6.5), (-17.7)*( 50.8) - (  0.3)*( 12.0) ) );
    v1_cross_v2.push_back( Vector( ( -0.9)*(  2.9) - (  2.8)*(  3.3), (  2.8)*(  5.0) - (-15.7)*(  2.9), (-15.7)*(  3.3) - ( -0.9)*(  5.0) ) );
    v1_cross_v2.push_back( Vector( ( -0.3)*( 78.0) - (-24.6)*(  1.3), (-24.6)*( -1.0) - (-17.0)*( 78.0), (-17.0)*(  1.3) - ( -0.3)*( -1.0) ) );

    
    positive_v1.push_back( Vector( +(  5.0), +(  3.3), +(  2.9) ) );
    positive_v1.push_back( Vector( +( -1.0), +(  1.3), +( 78.0) ) );
    positive_v1.push_back( Vector( +(  0.5), +( -2.4), +(  1.3) ) );
    positive_v1.push_back( Vector( +( 12.0), +( 50.8), +( -6.5) ) );
    positive_v1.push_back( Vector( +( 20.0), +(-39.0), +(-23.5) ) );
    positive_v1.push_back( Vector( +(-17.7), +(  0.3), +(-24.6) ) );
    positive_v1.push_back( Vector( +(-15.7), +( -0.9), +(  2.8) ) );
    positive_v1.push_back( Vector( +(-17.0), +( -0.3), +(-24.6) ) );
    positive_v1.push_back( Vector( +(  5.0), +(  3.3), +(  2.9) ) );
    positive_v1.push_back( Vector( +( -1.0), +(  1.3), +( 78.0) ) );
    positive_v1.push_back( Vector( +(  0.5), +( -2.4), +(  1.3) ) );
    positive_v1.push_back( Vector( +( 12.0), +( 50.8), +( -6.5) ) );
    positive_v1.push_back( Vector( +( 20.0), +(-39.0), +(-23.5) ) );
    positive_v1.push_back( Vector( +(-17.7), +(  0.3), +(-24.6) ) );
    positive_v1.push_back( Vector( +(-15.7), +( -0.9), +(  2.8) ) );
    positive_v1.push_back( Vector( +(-17.0), +( -0.3), +(-24.6) ) );

    negative_v1.push_back( Vector( -(  5.0), -(  3.3), -(  2.9) ) );
    negative_v1.push_back( Vector( -( -1.0), -(  1.3), -( 78.0) ) );
    negative_v1.push_back( Vector( -(  0.5), -( -2.4), -(  1.3) ) );
    negative_v1.push_back( Vector( -( 12.0), -( 50.8), -( -6.5) ) );
    negative_v1.push_back( Vector( -( 20.0), -(-39.0), -(-23.5) ) );
    negative_v1.push_back( Vector( -(-17.7), -(  0.3), -(-24.6) ) );
    negative_v1.push_back( Vector( -(-15.7), -( -0.9), -(  2.8) ) );
    negative_v1.push_back( Vector( -(-17.0), -( -0.3), -(-24.6) ) );
    negative_v1.push_back( Vector( -(  5.0), -(  3.3), -(  2.9) ) );
    negative_v1.push_back( Vector( -( -1.0), -(  1.3), -( 78.0) ) );
    negative_v1.push_back( Vector( -(  0.5), -( -2.4), -(  1.3) ) );
    negative_v1.push_back( Vector( -( 12.0), -( 50.8), -( -6.5) ) );
    negative_v1.push_back( Vector( -( 20.0), -(-39.0), -(-23.5) ) );
    negative_v1.push_back( Vector( -(-17.7), -(  0.3), -(-24.6) ) );
    negative_v1.push_back( Vector( -(-15.7), -( -0.9), -(  2.8) ) );
    negative_v1.push_back( Vector( -(-17.0), -( -0.3), -(-24.6) ) );


    v1_plus_v2.push_back( Vector( (  5.0) + ( 20.0) , (  3.3) + (-39.0) , (  2.9) + (-23.5) ) );
    v1_plus_v2.push_back( Vector( ( -1.0) + (-17.7) , (  1.3) + (  0.3) , ( 78.0) + (-24.6) ) );
    v1_plus_v2.push_back( Vector( (  0.5) + (-15.7) , ( -2.4) + ( -0.9) , (  1.3) + (  2.8) ) );
    v1_plus_v2.push_back( Vector( ( 12.0) + (-17.0) , ( 50.8) + ( -0.3) , ( -6.5) + (-24.6) ) );
    v1_plus_v2.push_back( Vector( ( 20.0) + (  5.0) , (-39.0) + (  3.3) , (-23.5) + (  2.9) ) );
    v1_plus_v2.push_back( Vector( (-17.7) + ( -1.0) , (  0.3) + (  1.3) , (-24.6) + ( 78.0) ) );
    v1_plus_v2.push_back( Vector( (-15.7) + (  0.5) , ( -0.9) + ( -2.4) , (  2.8) + (  1.3) ) );
    v1_plus_v2.push_back( Vector( (-17.0) + ( 12.0) , ( -0.3) + ( 50.8) , (-24.6) + ( -6.5) ) );
    v1_plus_v2.push_back( Vector( (  5.0) + (-15.7) , (  3.3) + ( -0.9) , (  2.9) + (  2.8) ) );
    v1_plus_v2.push_back( Vector( ( -1.0) + (-17.0) , (  1.3) + ( -0.3) , ( 78.0) + (-24.6) ) );
    v1_plus_v2.push_back( Vector( (  0.5) + ( 20.0) , ( -2.4) + (-39.0) , (  1.3) + (-23.5) ) );
    v1_plus_v2.push_back( Vector( ( 12.0) + (-17.7) , ( 50.8) + (  0.3) , ( -6.5) + (-24.6) ) );
    v1_plus_v2.push_back( Vector( ( 20.0) + (  0.5) , (-39.0) + ( -2.4) , (-23.5) + (  1.3) ) );
    v1_plus_v2.push_back( Vector( (-17.7) + ( 12.0) , (  0.3) + ( 50.8) , (-24.6) + ( -6.5) ) );
    v1_plus_v2.push_back( Vector( (-15.7) + (  5.0) , ( -0.9) + (  3.3) , (  2.8) + (  2.9) ) );
    v1_plus_v2.push_back( Vector( (-17.0) + ( -1.0) , ( -0.3) + (  1.3) , (-24.6) + ( 78.0) ) );

    v1_minu_v2.push_back( Vector( (  5.0) - ( 20.0) , (  3.3) - (-39.0) , (  2.9) - (-23.5) ) );
    v1_minu_v2.push_back( Vector( ( -1.0) - (-17.7) , (  1.3) - (  0.3) , ( 78.0) - (-24.6) ) );
    v1_minu_v2.push_back( Vector( (  0.5) - (-15.7) , ( -2.4) - ( -0.9) , (  1.3) - (  2.8) ) );
    v1_minu_v2.push_back( Vector( ( 12.0) - (-17.0) , ( 50.8) - ( -0.3) , ( -6.5) - (-24.6) ) );
    v1_minu_v2.push_back( Vector( ( 20.0) - (  5.0) , (-39.0) - (  3.3) , (-23.5) - (  2.9) ) );
    v1_minu_v2.push_back( Vector( (-17.7) - ( -1.0) , (  0.3) - (  1.3) , (-24.6) - ( 78.0) ) );
    v1_minu_v2.push_back( Vector( (-15.7) - (  0.5) , ( -0.9) - ( -2.4) , (  2.8) - (  1.3) ) );
    v1_minu_v2.push_back( Vector( (-17.0) - ( 12.0) , ( -0.3) - ( 50.8) , (-24.6) - ( -6.5) ) );
    v1_minu_v2.push_back( Vector( (  5.0) - (-15.7) , (  3.3) - ( -0.9) , (  2.9) - (  2.8) ) );
    v1_minu_v2.push_back( Vector( ( -1.0) - (-17.0) , (  1.3) - ( -0.3) , ( 78.0) - (-24.6) ) );
    v1_minu_v2.push_back( Vector( (  0.5) - ( 20.0) , ( -2.4) - (-39.0) , (  1.3) - (-23.5) ) );
    v1_minu_v2.push_back( Vector( ( 12.0) - (-17.7) , ( 50.8) - (  0.3) , ( -6.5) - (-24.6) ) );
    v1_minu_v2.push_back( Vector( ( 20.0) - (  0.5) , (-39.0) - ( -2.4) , (-23.5) - (  1.3) ) );
    v1_minu_v2.push_back( Vector( (-17.7) - ( 12.0) , (  0.3) - ( 50.8) , (-24.6) - ( -6.5) ) );
    v1_minu_v2.push_back( Vector( (-15.7) - (  5.0) , ( -0.9) - (  3.3) , (  2.8) - (  2.9) ) );
    v1_minu_v2.push_back( Vector( (-17.0) - ( -1.0) , ( -0.3) - (  1.3) , (-24.6) - ( 78.0) ) );

    v1_mult_v2.push_back( Vector( (  5.0) * ( 20.0) , (  3.3) * (-39.0) , (  2.9) * (-23.5) ) );
    v1_mult_v2.push_back( Vector( ( -1.0) * (-17.7) , (  1.3) * (  0.3) , ( 78.0) * (-24.6) ) );
    v1_mult_v2.push_back( Vector( (  0.5) * (-15.7) , ( -2.4) * ( -0.9) , (  1.3) * (  2.8) ) );
    v1_mult_v2.push_back( Vector( ( 12.0) * (-17.0) , ( 50.8) * ( -0.3) , ( -6.5) * (-24.6) ) );
    v1_mult_v2.push_back( Vector( ( 20.0) * (  5.0) , (-39.0) * (  3.3) , (-23.5) * (  2.9) ) );
    v1_mult_v2.push_back( Vector( (-17.7) * ( -1.0) , (  0.3) * (  1.3) , (-24.6) * ( 78.0) ) );
    v1_mult_v2.push_back( Vector( (-15.7) * (  0.5) , ( -0.9) * ( -2.4) , (  2.8) * (  1.3) ) );
    v1_mult_v2.push_back( Vector( (-17.0) * ( 12.0) , ( -0.3) * ( 50.8) , (-24.6) * ( -6.5) ) );
    v1_mult_v2.push_back( Vector( (  5.0) * (-15.7) , (  3.3) * ( -0.9) , (  2.9) * (  2.8) ) );
    v1_mult_v2.push_back( Vector( ( -1.0) * (-17.0) , (  1.3) * ( -0.3) , ( 78.0) * (-24.6) ) );
    v1_mult_v2.push_back( Vector( (  0.5) * ( 20.0) , ( -2.4) * (-39.0) , (  1.3) * (-23.5) ) );
    v1_mult_v2.push_back( Vector( ( 12.0) * (-17.7) , ( 50.8) * (  0.3) , ( -6.5) * (-24.6) ) );
    v1_mult_v2.push_back( Vector( ( 20.0) * (  0.5) , (-39.0) * ( -2.4) , (-23.5) * (  1.3) ) );
    v1_mult_v2.push_back( Vector( (-17.7) * ( 12.0) , (  0.3) * ( 50.8) , (-24.6) * ( -6.5) ) );
    v1_mult_v2.push_back( Vector( (-15.7) * (  5.0) , ( -0.9) * (  3.3) , (  2.8) * (  2.9) ) );
    v1_mult_v2.push_back( Vector( (-17.0) * ( -1.0) , ( -0.3) * (  1.3) , (-24.6) * ( 78.0) ) );

    v1_divi_v2.push_back( Vector( (  5.0) / ( 20.0) , (  3.3) / (-39.0) , (  2.9) / (-23.5) ) );
    v1_divi_v2.push_back( Vector( ( -1.0) / (-17.7) , (  1.3) / (  0.3) , ( 78.0) / (-24.6) ) );
    v1_divi_v2.push_back( Vector( (  0.5) / (-15.7) , ( -2.4) / ( -0.9) , (  1.3) / (  2.8) ) );
    v1_divi_v2.push_back( Vector( ( 12.0) / (-17.0) , ( 50.8) / ( -0.3) , ( -6.5) / (-24.6) ) );
    v1_divi_v2.push_back( Vector( ( 20.0) / (  5.0) , (-39.0) / (  3.3) , (-23.5) / (  2.9) ) );
    v1_divi_v2.push_back( Vector( (-17.7) / ( -1.0) , (  0.3) / (  1.3) , (-24.6) / ( 78.0) ) );
    v1_divi_v2.push_back( Vector( (-15.7) / (  0.5) , ( -0.9) / ( -2.4) , (  2.8) / (  1.3) ) );
    v1_divi_v2.push_back( Vector( (-17.0) / ( 12.0) , ( -0.3) / ( 50.8) , (-24.6) / ( -6.5) ) );
    v1_divi_v2.push_back( Vector( (  5.0) / (-15.7) , (  3.3) / ( -0.9) , (  2.9) / (  2.8) ) );
    v1_divi_v2.push_back( Vector( ( -1.0) / (-17.0) , (  1.3) / ( -0.3) , ( 78.0) / (-24.6) ) );
    v1_divi_v2.push_back( Vector( (  0.5) / ( 20.0) , ( -2.4) / (-39.0) , (  1.3) / (-23.5) ) );
    v1_divi_v2.push_back( Vector( ( 12.0) / (-17.7) , ( 50.8) / (  0.3) , ( -6.5) / (-24.6) ) );
    v1_divi_v2.push_back( Vector( ( 20.0) / (  0.5) , (-39.0) / ( -2.4) , (-23.5) / (  1.3) ) );
    v1_divi_v2.push_back( Vector( (-17.7) / ( 12.0) , (  0.3) / ( 50.8) , (-24.6) / ( -6.5) ) );
    v1_divi_v2.push_back( Vector( (-15.7) / (  5.0) , ( -0.9) / (  3.3) , (  2.8) / (  2.9) ) );
    v1_divi_v2.push_back( Vector( (-17.0) / ( -1.0) , ( -0.3) / (  1.3) , (-24.6) / ( 78.0) ) );


    v1_plus_val.push_back( Vector(  5.0 + val,   3.3 + val,   2.9 + val) );
    v1_plus_val.push_back( Vector( -1.0 + val,   1.3 + val,  78.0 + val) );
    v1_plus_val.push_back( Vector(  0.5 + val,  -2.4 + val,   1.3 + val) );
    v1_plus_val.push_back( Vector( 12.0 + val,  50.8 + val,  -6.5 + val) );
    v1_plus_val.push_back( Vector( 20.0 + val, -39.0 + val, -23.5 + val) );
    v1_plus_val.push_back( Vector(-17.7 + val,   0.3 + val, -24.6 + val) );
    v1_plus_val.push_back( Vector(-15.7 + val,  -0.9 + val,   2.8 + val) );
    v1_plus_val.push_back( Vector(-17.0 + val,  -0.3 + val, -24.6 + val) );
    v1_plus_val.push_back( Vector(  5.0 + val,   3.3 + val,   2.9 + val) );
    v1_plus_val.push_back( Vector( -1.0 + val,   1.3 + val,  78.0 + val) );
    v1_plus_val.push_back( Vector(  0.5 + val,  -2.4 + val,   1.3 + val) );
    v1_plus_val.push_back( Vector( 12.0 + val,  50.8 + val,  -6.5 + val) );
    v1_plus_val.push_back( Vector( 20.0 + val, -39.0 + val, -23.5 + val) );
    v1_plus_val.push_back( Vector(-17.7 + val,   0.3 + val, -24.6 + val) );
    v1_plus_val.push_back( Vector(-15.7 + val,  -0.9 + val,   2.8 + val) );
    v1_plus_val.push_back( Vector(-17.0 + val,  -0.3 + val, -24.6 + val) );

    v1_minu_val.push_back( Vector(  5.0 - val,   3.3 - val,   2.9 - val) );
    v1_minu_val.push_back( Vector( -1.0 - val,   1.3 - val,  78.0 - val) );
    v1_minu_val.push_back( Vector(  0.5 - val,  -2.4 - val,   1.3 - val) );
    v1_minu_val.push_back( Vector( 12.0 - val,  50.8 - val,  -6.5 - val) );
    v1_minu_val.push_back( Vector( 20.0 - val, -39.0 - val, -23.5 - val) );
    v1_minu_val.push_back( Vector(-17.7 - val,   0.3 - val, -24.6 - val) );
    v1_minu_val.push_back( Vector(-15.7 - val,  -0.9 - val,   2.8 - val) );
    v1_minu_val.push_back( Vector(-17.0 - val,  -0.3 - val, -24.6 - val) );
    v1_minu_val.push_back( Vector(  5.0 - val,   3.3 - val,   2.9 - val) );
    v1_minu_val.push_back( Vector( -1.0 - val,   1.3 - val,  78.0 - val) );
    v1_minu_val.push_back( Vector(  0.5 - val,  -2.4 - val,   1.3 - val) );
    v1_minu_val.push_back( Vector( 12.0 - val,  50.8 - val,  -6.5 - val) );
    v1_minu_val.push_back( Vector( 20.0 - val, -39.0 - val, -23.5 - val) );
    v1_minu_val.push_back( Vector(-17.7 - val,   0.3 - val, -24.6 - val) );
    v1_minu_val.push_back( Vector(-15.7 - val,  -0.9 - val,   2.8 - val) );
    v1_minu_val.push_back( Vector(-17.0 - val,  -0.3 - val, -24.6 - val) );

    v1_mult_val.push_back( Vector(  5.0 * val,   3.3 * val,   2.9 * val) );
    v1_mult_val.push_back( Vector( -1.0 * val,   1.3 * val,  78.0 * val) );
    v1_mult_val.push_back( Vector(  0.5 * val,  -2.4 * val,   1.3 * val) );
    v1_mult_val.push_back( Vector( 12.0 * val,  50.8 * val,  -6.5 * val) );
    v1_mult_val.push_back( Vector( 20.0 * val, -39.0 * val, -23.5 * val) );
    v1_mult_val.push_back( Vector(-17.7 * val,   0.3 * val, -24.6 * val) );
    v1_mult_val.push_back( Vector(-15.7 * val,  -0.9 * val,   2.8 * val) );
    v1_mult_val.push_back( Vector(-17.0 * val,  -0.3 * val, -24.6 * val) );
    v1_mult_val.push_back( Vector(  5.0 * val,   3.3 * val,   2.9 * val) );
    v1_mult_val.push_back( Vector( -1.0 * val,   1.3 * val,  78.0 * val) );
    v1_mult_val.push_back( Vector(  0.5 * val,  -2.4 * val,   1.3 * val) );
    v1_mult_val.push_back( Vector( 12.0 * val,  50.8 * val,  -6.5 * val) );
    v1_mult_val.push_back( Vector( 20.0 * val, -39.0 * val, -23.5 * val) );
    v1_mult_val.push_back( Vector(-17.7 * val,   0.3 * val, -24.6 * val) );
    v1_mult_val.push_back( Vector(-15.7 * val,  -0.9 * val,   2.8 * val) );
    v1_mult_val.push_back( Vector(-17.0 * val,  -0.3 * val, -24.6 * val) );

    v1_divi_val.push_back( Vector(  5.0 / val,   3.3 / val,   2.9 / val) );
    v1_divi_val.push_back( Vector( -1.0 / val,   1.3 / val,  78.0 / val) );
    v1_divi_val.push_back( Vector(  0.5 / val,  -2.4 / val,   1.3 / val) );
    v1_divi_val.push_back( Vector( 12.0 / val,  50.8 / val,  -6.5 / val) );
    v1_divi_val.push_back( Vector( 20.0 / val, -39.0 / val, -23.5 / val) );
    v1_divi_val.push_back( Vector(-17.7 / val,   0.3 / val, -24.6 / val) );
    v1_divi_val.push_back( Vector(-15.7 / val,  -0.9 / val,   2.8 / val) );
    v1_divi_val.push_back( Vector(-17.0 / val,  -0.3 / val, -24.6 / val) );
    v1_divi_val.push_back( Vector(  5.0 / val,   3.3 / val,   2.9 / val) );
    v1_divi_val.push_back( Vector( -1.0 / val,   1.3 / val,  78.0 / val) );
    v1_divi_val.push_back( Vector(  0.5 / val,  -2.4 / val,   1.3 / val) );
    v1_divi_val.push_back( Vector( 12.0 / val,  50.8 / val,  -6.5 / val) );
    v1_divi_val.push_back( Vector( 20.0 / val, -39.0 / val, -23.5 / val) );
    v1_divi_val.push_back( Vector(-17.7 / val,   0.3 / val, -24.6 / val) );
    v1_divi_val.push_back( Vector(-15.7 / val,  -0.9 / val,   2.8 / val) );
    v1_divi_val.push_back( Vector(-17.0 / val,  -0.3 / val, -24.6 / val) );


    val_plus_v1.push_back( Vector( val + (  5.0) , val + (  3.3) , val + (  2.9) ) );
    val_plus_v1.push_back( Vector( val + ( -1.0) , val + (  1.3) , val + ( 78.0) ) );
    val_plus_v1.push_back( Vector( val + (  0.5) , val + ( -2.4) , val + (  1.3) ) );
    val_plus_v1.push_back( Vector( val + ( 12.0) , val + ( 50.8) , val + ( -6.5) ) );
    val_plus_v1.push_back( Vector( val + ( 20.0) , val + (-39.0) , val + (-23.5) ) );
    val_plus_v1.push_back( Vector( val + (-17.7) , val + (  0.3) , val + (-24.6) ) );
    val_plus_v1.push_back( Vector( val + (-15.7) , val + ( -0.9) , val + (  2.8) ) );
    val_plus_v1.push_back( Vector( val + (-17.0) , val + ( -0.3) , val + (-24.6) ) );
    val_plus_v1.push_back( Vector( val + (  5.0) , val + (  3.3) , val + (  2.9) ) );
    val_plus_v1.push_back( Vector( val + ( -1.0) , val + (  1.3) , val + ( 78.0) ) );
    val_plus_v1.push_back( Vector( val + (  0.5) , val + ( -2.4) , val + (  1.3) ) );
    val_plus_v1.push_back( Vector( val + ( 12.0) , val + ( 50.8) , val + ( -6.5) ) );
    val_plus_v1.push_back( Vector( val + ( 20.0) , val + (-39.0) , val + (-23.5) ) );
    val_plus_v1.push_back( Vector( val + (-17.7) , val + (  0.3) , val + (-24.6) ) );
    val_plus_v1.push_back( Vector( val + (-15.7) , val + ( -0.9) , val + (  2.8) ) );
    val_plus_v1.push_back( Vector( val + (-17.0) , val + ( -0.3) , val + (-24.6) ) );

    val_minu_v1.push_back( Vector( val - (  5.0) , val - (  3.3) , val - (  2.9) ) );
    val_minu_v1.push_back( Vector( val - ( -1.0) , val - (  1.3) , val - ( 78.0) ) );
    val_minu_v1.push_back( Vector( val - (  0.5) , val - ( -2.4) , val - (  1.3) ) );
    val_minu_v1.push_back( Vector( val - ( 12.0) , val - ( 50.8) , val - ( -6.5) ) );
    val_minu_v1.push_back( Vector( val - ( 20.0) , val - (-39.0) , val - (-23.5) ) );
    val_minu_v1.push_back( Vector( val - (-17.7) , val - (  0.3) , val - (-24.6) ) );
    val_minu_v1.push_back( Vector( val - (-15.7) , val - ( -0.9) , val - (  2.8) ) );
    val_minu_v1.push_back( Vector( val - (-17.0) , val - ( -0.3) , val - (-24.6) ) );
    val_minu_v1.push_back( Vector( val - (  5.0) , val - (  3.3) , val - (  2.9) ) );
    val_minu_v1.push_back( Vector( val - ( -1.0) , val - (  1.3) , val - ( 78.0) ) );
    val_minu_v1.push_back( Vector( val - (  0.5) , val - ( -2.4) , val - (  1.3) ) );
    val_minu_v1.push_back( Vector( val - ( 12.0) , val - ( 50.8) , val - ( -6.5) ) );
    val_minu_v1.push_back( Vector( val - ( 20.0) , val - (-39.0) , val - (-23.5) ) );
    val_minu_v1.push_back( Vector( val - (-17.7) , val - (  0.3) , val - (-24.6) ) );
    val_minu_v1.push_back( Vector( val - (-15.7) , val - ( -0.9) , val - (  2.8) ) );
    val_minu_v1.push_back( Vector( val - (-17.0) , val - ( -0.3) , val - (-24.6) ) );

    val_mult_v1.push_back( Vector( val * (  5.0) , val * (  3.3) , val * (  2.9) ) );
    val_mult_v1.push_back( Vector( val * ( -1.0) , val * (  1.3) , val * ( 78.0) ) );
    val_mult_v1.push_back( Vector( val * (  0.5) , val * ( -2.4) , val * (  1.3) ) );
    val_mult_v1.push_back( Vector( val * ( 12.0) , val * ( 50.8) , val * ( -6.5) ) );
    val_mult_v1.push_back( Vector( val * ( 20.0) , val * (-39.0) , val * (-23.5) ) );
    val_mult_v1.push_back( Vector( val * (-17.7) , val * (  0.3) , val * (-24.6) ) );
    val_mult_v1.push_back( Vector( val * (-15.7) , val * ( -0.9) , val * (  2.8) ) );
    val_mult_v1.push_back( Vector( val * (-17.0) , val * ( -0.3) , val * (-24.6) ) );
    val_mult_v1.push_back( Vector( val * (  5.0) , val * (  3.3) , val * (  2.9) ) );
    val_mult_v1.push_back( Vector( val * ( -1.0) , val * (  1.3) , val * ( 78.0) ) );
    val_mult_v1.push_back( Vector( val * (  0.5) , val * ( -2.4) , val * (  1.3) ) );
    val_mult_v1.push_back( Vector( val * ( 12.0) , val * ( 50.8) , val * ( -6.5) ) );
    val_mult_v1.push_back( Vector( val * ( 20.0) , val * (-39.0) , val * (-23.5) ) );
    val_mult_v1.push_back( Vector( val * (-17.7) , val * (  0.3) , val * (-24.6) ) );
    val_mult_v1.push_back( Vector( val * (-15.7) , val * ( -0.9) , val * (  2.8) ) );
    val_mult_v1.push_back( Vector( val * (-17.0) , val * ( -0.3) , val * (-24.6) ) );

    val_divi_v1.push_back( Vector( val / (  5.0) , val / (  3.3) , val / (  2.9) ) );
    val_divi_v1.push_back( Vector( val / ( -1.0) , val / (  1.3) , val / ( 78.0) ) );
    val_divi_v1.push_back( Vector( val / (  0.5) , val / ( -2.4) , val / (  1.3) ) );
    val_divi_v1.push_back( Vector( val / ( 12.0) , val / ( 50.8) , val / ( -6.5) ) );
    val_divi_v1.push_back( Vector( val / ( 20.0) , val / (-39.0) , val / (-23.5) ) );
    val_divi_v1.push_back( Vector( val / (-17.7) , val / (  0.3) , val / (-24.6) ) );
    val_divi_v1.push_back( Vector( val / (-15.7) , val / ( -0.9) , val / (  2.8) ) );
    val_divi_v1.push_back( Vector( val / (-17.0) , val / ( -0.3) , val / (-24.6) ) );
    val_divi_v1.push_back( Vector( val / (  5.0) , val / (  3.3) , val / (  2.9) ) );
    val_divi_v1.push_back( Vector( val / ( -1.0) , val / (  1.3) , val / ( 78.0) ) );
    val_divi_v1.push_back( Vector( val / (  0.5) , val / ( -2.4) , val / (  1.3) ) );
    val_divi_v1.push_back( Vector( val / ( 12.0) , val / ( 50.8) , val / ( -6.5) ) );
    val_divi_v1.push_back( Vector( val / ( 20.0) , val / (-39.0) , val / (-23.5) ) );
    val_divi_v1.push_back( Vector( val / (-17.7) , val / (  0.3) , val / (-24.6) ) );
    val_divi_v1.push_back( Vector( val / (-15.7) , val / ( -0.9) , val / (  2.8) ) );
    val_divi_v1.push_back( Vector( val / (-17.0) , val / ( -0.3) , val / (-24.6) ) );


    v1_dot_v2.push_back( (  5.0) * ( 20.0) + (  3.3) * (-39.0) + (  2.9) * (-23.5) );
    v1_dot_v2.push_back( ( -1.0) * (-17.7) + (  1.3) * (  0.3) + ( 78.0) * (-24.6) );
    v1_dot_v2.push_back( (  0.5) * (-15.7) + ( -2.4) * ( -0.9) + (  1.3) * (  2.8) );
    v1_dot_v2.push_back( ( 12.0) * (-17.0) + ( 50.8) * ( -0.3) + ( -6.5) * (-24.6) );
    v1_dot_v2.push_back( ( 20.0) * (  5.0) + (-39.0) * (  3.3) + (-23.5) * (  2.9) );
    v1_dot_v2.push_back( (-17.7) * ( -1.0) + (  0.3) * (  1.3) + (-24.6) * ( 78.0) );
    v1_dot_v2.push_back( (-15.7) * (  0.5) + ( -0.9) * ( -2.4) + (  2.8) * (  1.3) );
    v1_dot_v2.push_back( (-17.0) * ( 12.0) + ( -0.3) * ( 50.8) + (-24.6) * ( -6.5) );
    v1_dot_v2.push_back( (  5.0) * (-15.7) + (  3.3) * ( -0.9) + (  2.9) * (  2.8) );
    v1_dot_v2.push_back( ( -1.0) * (-17.0) + (  1.3) * ( -0.3) + ( 78.0) * (-24.6) );
    v1_dot_v2.push_back( (  0.5) * ( 20.0) + ( -2.4) * (-39.0) + (  1.3) * (-23.5) );
    v1_dot_v2.push_back( ( 12.0) * (-17.7) + ( 50.8) * (  0.3) + ( -6.5) * (-24.6) );
    v1_dot_v2.push_back( ( 20.0) * (  0.5) + (-39.0) * ( -2.4) + (-23.5) * (  1.3) );
    v1_dot_v2.push_back( (-17.7) * ( 12.0) + (  0.3) * ( 50.8) + (-24.6) * ( -6.5) );
    v1_dot_v2.push_back( (-15.7) * (  5.0) + ( -0.9) * (  3.3) + (  2.8) * (  2.9) );
    v1_dot_v2.push_back( (-17.0) * ( -1.0) + ( -0.3) * (  1.3) + (-24.6) * ( 78.0) );

    cout << "Start test class Vecctor..." << endl;
    for ( size_t i = 0; i < v1.size(); i++ ) {
        cout << "Round of tests: " << i << endl;

        if ( !eq(+v1[i], positive_v1[i]) ) {
            cout << "error happened in +Vector." << endl;
            return -1;
        }

        if ( !eq(-v1[i], negative_v1[i]) ) {
            cout << "error happened in -Vector." << endl;
            return -1;
        }

        if ( !eq(v1[i] + v2[i], v1_plus_v2[i]) ) {
            cout << "error happened in Vector + Vector." << endl;
            return -1;
        }

        if ( !eq(v1[i] - v2[i], v1_minu_v2[i]) ) {
            cout << "error happened in Vector - Vector." << endl;
            return -1;
        }

        if ( !eq(v1[i] * v2[i], v1_mult_v2[i]) ) {
            cout << "error happened in Vector * Vector." << endl;
            return -1;
        }

        if ( !eq(v1[i] / v2[i], v1_divi_v2[i]) ) {
            cout << "error happened in Vector / Vector." << endl;
            return -1;
        }

        if ( !eq(v1[i] + val, v1_plus_val[i]) ) {
            cout << "error happened in Vector + value." << endl;
            return -1;
        }

        if ( !eq(v1[i] - val, v1_minu_val[i]) ) {
            cout << "error happened in Vector - value." << endl;
            return -1;
        }

        if ( !eq(v1[i] * val, v1_mult_val[i]) ) {
            cout << "error happened in Vector * value." << endl;
            return -1;
        }

        if ( !eq(v1[i] / val, v1_divi_val[i]) ) {
            cout << "error happened in Vector / value." << endl;
            return -1;
        }

        if ( !eq(val + v1[i], val_plus_v1[i]) ) {
            cout << "error happened in value + Vector." << endl;
            return -1;
        }

        if ( !eq(val - v1[i], val_minu_v1[i]) ) {
            cout << "error happened in value - Vector." << endl;
            return -1;
        }

        if ( !eq(val * v1[i], val_mult_v1[i]) ) {
            cout << "error happened in value * Vector." << endl;
            return -1;
        }

        if ( !eq(val / v1[i], val_divi_v1[i]) ) {
            cout << "error happened in value / Vector." << endl;
            return -1;
        }

        Vector tmp;

        tmp = v1[i];
        tmp += v2[i];
        if ( !eq(tmp, v1_plus_v2[i]) ) {
            cout << "error happened in Vector += Vector." << endl;
            return -1;
        }

        tmp = v1[i];
        tmp -= v2[i];
        if ( !eq(tmp, v1_minu_v2[i]) ) {
            cout << "error happened in Vector -= Vector." << endl;
            return -1;
        }

        tmp = v1[i];
        tmp *= v2[i];
        if ( !eq(tmp, v1_mult_v2[i]) ) {
            cout << "error happened in Vector *= Vector." << endl;
            return -1;
        }

        tmp = v1[i];
        tmp /= v2[i];
        if ( !eq(tmp, v1_divi_v2[i]) ) {
            cout << "error happened in Vector /= Vector." << endl;
            return -1;
        }

        tmp = v1[i];
        tmp += val;
        if ( !eq(tmp, v1_plus_val[i]) ) {
            cout << "error happened in Vector += val." << endl;
            return -1;
        }

        tmp = v1[i];
        tmp -= val;
        if ( !eq(tmp, v1_minu_val[i]) ) {
            cout << "error happened in Vector -= val." << endl;
            return -1;
        }

        tmp = v1[i];
        tmp *= val;
        if ( !eq(tmp, v1_mult_val[i]) ) {
            cout << "error happened in Vector *= val." << endl;
            return -1;
        }

        tmp = v1[i];
        tmp /= val;
        if ( !eq(tmp, v1_divi_val[i]) ) {
            cout << "error happened in Vector /= val." << endl;
            return -1;
        }

        if ( !eq(v1[i] % v2[i], v1_dot_v2[i]) ) {
            cout << "error happened in Vector % Vector." << endl;
            return -1;
        }

        if ( !eq(cross_product(v1[i], v2[i]), v1_cross_v2[i]) ) {
            cout << "error happened in function cross_product." << endl;
            return -1;
        }

        if ( !eq(v1[i] % v1[i], v1[i].len() * v1[i].len()) ) {
            cout << "error happened. Vector % Vector != Vector.len() * Vector.len()" << endl;
            return -1;
        }
    }

    cout << "Test of class Vector is successful." << endl;
    return 0;
}

// Determine whether two numbers or two vectors are equal
bool eq(const double &a, const double &b, double eps)
{
    return std::abs(a-b) < eps;
}

bool eq(const Vector &a, const Vector &b)
{
    return eq(a.x, b.x) && eq(a.y, b.y) && eq(a.z, b.z);
}