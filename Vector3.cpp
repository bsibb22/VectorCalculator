//
// Created by Brandon Sibbitt on 3/1/23.
//

#include "Vector3.h"
#include <cmath>

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

double Vector3::dot(Vector3 &rhs) {
    return x * rhs.x + y * rhs.y + z * rhs.z;
}

Vector3 Vector3::operator+(Vector3 &rhs) {
    return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3 Vector3::operator-(Vector3 &rhs) {
    return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3 Vector3::cross(Vector3 &rhs) {
    return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
}

double Vector3::mag() {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector3 Vector3::getUnit() {
    double m = mag();
    return Vector3(x / m, y / m, z / m);
}
