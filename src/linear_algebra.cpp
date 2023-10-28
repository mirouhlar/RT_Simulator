
#include <iostream>
#include <cmath>
#include"linear_algebra.h"

Vec3::Vec3() : x(double(0)), y(double(0)), z(double(0)) {}
Vec3::Vec3(const Vec3& other) {
    x = other.x; y = other.y; z = other.z;}

Vec3::Vec3(const double& vv) : x{double(vv)}, y{double(vv)}, z{double(vv)} {}
Vec3::Vec3(double xx, double yy, double zz) : x{double(xx)}, y{double(yy)}, z{double(zz)} {}
Vec3::~Vec3() {}

void Vec3::ShowElements(){
    std::cout<< "[" << x << ", " << y << ", " << z << "]" << std::endl;}
Vec3 Vec3::DotProduct(const Vec3& vec) const {
        return Vec3(x+vec.x, y+vec.y, z+vec.z);}

double Vec3::GetMagnitude(){
    return std::sqrt(Vec3::Norm());}
double Vec3::Norm(){
    return (x*x + y*y +z*z);}

Vec3 Vec3::CrossProduct(const Vec3& vec) const {
    return Vec3(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x); }

Vec3& Vec3::Normalize()
{
    double mag = Norm();
        if (mag != 0.0) {
            double invMag = 1.0 / mag;
            // multiplication is generally faster than division 
            x *= invMag; y *= invMag; z *= invMag;
        }
        return *this;
}


Matrix4::Matrix4(){x[0][0] = 1;
    x[0][1] = 0;
    x[0][2] = 0;
    x[0][3] = 0;

    x[1][0] = 0;
    x[1][1] = 1;
    x[1][2] = 0;
    x[1][3] = 0;

    x[2][0] = 0;
    x[2][1] = 0;
    x[2][2] = 1;
    x[2][3] = 0;

    x[3][0] = 0;
    x[3][1] = 0;
    x[3][2] = 0;
    x[3][3] = 1;}
Matrix4::Matrix4(dl a, dl b, dl c, dl d, dl e, dl f, dl g, dl h,
              dl i, dl j, dl k, dl l, dl m, dl n, dl o, dl p) {
                x[0][0] = a;
        x[0][1] = b;
        x[0][2] = c;
        x[0][3] = d;
        x[1][0] = e;
        x[1][1] = f;
        x[1][2] = g;
        x[1][3] = h;
        x[2][0] = i;
        x[2][1] = j;
        x[2][2] = k;
        x[2][3] = l;
        x[3][0] = m;
        x[3][1] = n;
        x[3][2] = o;
        x[3][3] = p;
              }


void Matrix4::ShowElements() const {
        std::cout << "[" ; //<< std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << "  [";
            for (int j = 0; j < 4; j++) {
                std::cout << x[i][j];
                if (j < 3) {
                    std::cout << ", ";
                }
            }
            std::cout << "]";
            if (i < 3) {
                std::cout << "," << std::endl;
            }
        }
        std::cout << " ]" << std::endl;
    }