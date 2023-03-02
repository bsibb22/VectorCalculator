//
// Created by Brandon Sibbitt on 3/1/23.
//

#ifndef VECTORCALCULATOR_VECTOR3_H
#define VECTORCALCULATOR_VECTOR3_H

#include <iostream>
#include <ostream>

using namespace std;

class Vector3 {
    double x;
    double y;
    double z;

public:
    Vector3();
    Vector3(double x, double y, double z);

    void Print();
    Vector3 operator+(Vector3& rhs);
    Vector3 operator-(Vector3& rhs);
    Vector3 cross(Vector3& rhs);
    double dot(Vector3& rhs);

    double mag();

    Vector3 getUnit();
};


#endif //VECTORCALCULATOR_VECTOR3_H
