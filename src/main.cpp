
#include <iostream>
#include "linear_algebra.h"

int main(){

    Vec3 vec(10.2, 28.4, -23.5);
    Vec3 vec2(62.3,-0.3,00.5);
    vec.ShowElements();
    vec2.ShowElements();
    vec2.Normalize();
    vec2.ShowElements();
    
    // std::cout << vec.GetMagnitude() << std::endl;
    // (vec.CrossProduct(vec2)).ShowElements(); 

    // Matrix4 matrix;
    // matrix.ShowElements();

    return 0;
}