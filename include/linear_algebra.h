#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

typedef double dl;

class Vec3
{
public:
    Vec3();                                         // default constructor
    Vec3(const Vec3& other);                        // copy constructor
    Vec3(const double& vv);                         // parametrized constructor
    Vec3(double xx, double yy, double zz);          // parametrized constructor
    ~Vec3();                                        // destructor
    double x, y, z;                                 // vector elements
public:
    double GetMagnitude();                          // magnitude of vector
    double Norm();                                  // norm of vector
    void ShowElements();                            // function prints vector elements
    Vec3 CrossProduct(const Vec3& vec) const;       // function for calculating cross product
    Vec3& Normalize();
    Vec3 DotProduct(const Vec3& vec) const;         // function for calculating dot product

    Vec3 operator + (const Vec3& vec) const {       // const -> doesnt change state of object
        return Vec3(x+vec.x, y+vec.y, z+vec.z);}
    Vec3 operator - (const Vec3& vec) const {       // const -> doesnt change state of object
        return Vec3(x-vec.x, y-vec.y, z-vec.z);}
    Vec3 operator * (const double& r) const {
        return Vec3(r*x, r*y, r*z);}
};

class Matrix4
{
public:
    Matrix4();                                      // default constructor
    Matrix4(dl a, dl b, dl c, dl d, dl e, dl f, dl g, dl h,
              dl i, dl j, dl k, dl l, dl m, dl n, dl o, dl p);
    Matrix4(const Matrix4& other);                  // copy constructor
    double x[4][4];                                 // matrix elements

    void ShowElements() const;
};




#endif // LINEAR_ALGEBRA_H