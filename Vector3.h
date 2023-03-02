//
// Created by Brandon Sibbitt on 3/1/23.
//

#ifndef VECTORCALCULATOR_VECTOR3_H
#define VECTORCALCULATOR_VECTOR3_H

using namespace std;
#include <iostream>

class Vector3 {
    double x;
    double y;
    double z;

public:
    Vector3();
    Vector3(double x, double y, double z);

    void Print();
};


#endif //VECTORCALCULATOR_VECTOR3_H
