//
// Created by Brandon Sibbitt on 3/1/23.
//

#include "Vector3.h"

Vector3::Vector3() {
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

Vector3::Vector3(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector3::Print() {
    cout << "<" << x << ", " << y << ", " << z << ">";
}