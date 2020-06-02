#include "Vector3.h"
#include "cmath"


Vector3::Vector3() {
    elem[0] = elem[1] = elem[2] = 0;
}

Vector3::~Vector3() {
}

Vector3::Vector3(double arg) {
    for (int i = 0; i < n; i++) {
        elem[i] = arg;
    }
}

Vector3::Vector3(const double arg[3]) {
    for (int i = 0; i < n; i++) {
        elem[i] = arg[i];
    }
}

Vector3::Vector3(const Vector3& other) {
    for (int i = 0; i < n; i++) {
        elem[i] = other.elem[i];
    }
}
Vector3::Vector3(double arg1, double arg2, double arg3) {
    elem[0] = arg1;
    elem[1] = arg2;
    elem[2] = arg3;
}


double& Vector3::operator[](unsigned int i) {
    return elem[i];
}

double Vector3::operator[](unsigned int i) const {
    return elem[i];
}


Vector3& Vector3::operator=(const Vector3& other) {
    for (int i = 0; i < n; i++) {
        elem[i] = other.elem[i];
    }
    return *this;
}

Vector3& Vector3::operator+=(const Vector3& other) {
    for (int i = 0; i < n; i++) {
        elem[i] += other.elem[i];
    }
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& other) {
    for (int i = 0; i < n; i++) {
        elem[i] -= other.elem[i];
    }
    return *this;
}

Vector3& Vector3::operator*=(const double number) {
    for (int i = 0; i < n; i++) {
        elem[i] *= number;
    }
    return *this;
}

Vector3& Vector3::operator/=(const double number) {
    for (int i = 0; i < n; i++) {
        elem[i] /= number;
    }
    return *this;
}

bool operator==(const Vector3& lhs, const Vector3& rhs) {
    return (lhs.elem[0] == rhs.elem[0] && lhs.elem[1] == rhs.elem[1] && lhs.elem[2] == rhs.elem[2]) ? true : false;
}
    
Vector3 operator+(const Vector3& our, const Vector3& other) {
    Vector3 otv;
    for (int i = 0; i < Vector3::n; i++) {
        otv.elem[i] = our.elem[i] + other.elem[i];
    }
    return otv;
}
    
Vector3 operator-(const Vector3& our, const Vector3& other) {
    Vector3 otv;
    for (int i = 0; i < Vector3::n; i++) {
        otv.elem[i] = our.elem[i] - other.elem[i];
    }
    return otv;
}
Vector3 operator*(const Vector3& our, double number) {
    Vector3 otv;
    for (int i = 0; i < Vector3::n; i++) {
        otv.elem[i] = our.elem[i] * number;
    }
    return otv;
}
    
Vector3 operator*(const double number, const Vector3& our) {
    Vector3 otv = our*number;
    return otv;
}
    
Vector3 operator/(const Vector3& our, const double number){
    Vector3 otv;
    for (int i = 0; i < Vector3::n; i++) {
        otv.elem[i] = our.elem[i] / number;
    }
    return otv;
}


double Vector3::getNorma() const {
    return (sqrt(elem[0] * elem[0] + elem[1] * elem[1] + elem[2] * elem[2]));
}

void Vector3::normalize() {
    double length = this->getNorma();
    for (int i = 0; i < n; i++) {
        elem[i] /= length;
    }
}


Vector3 Vector3::getNormalized()const {
    Vector3 otv = *this;
    otv.normalize();
    return otv;
}


double Vector3::getScalarProduct(const Vector3& other) const {
    return elem[0] * other.elem[0] + elem[1] * other.elem[1] + elem[2] * other.elem[2];
}

Vector3 getVectorProduct(const Vector3& our, const Vector3& other) {
    Vector3 otv;
    otv.elem[0] = our.elem[1] * other.elem[2] - our.elem[2] * other.elem[1];
    otv.elem[1] = our.elem[2] * other.elem[0] - our.elem[0] * other.elem[2];
    otv.elem[2] = our.elem[0] * other.elem[1] - our.elem[1] * other.elem[0];
    return otv;
}


Vector3 Vector3::operator-()const {
    Vector3 otv;
    for (int i = 0; i < n; i++) {
        otv.elem[i] = -elem[i];
    }
    return otv;
}

std::ostream& operator<<(std::ostream& stream, const Vector3& V) {
    std::cout << "{" << V.elem[0] << ", " << V.elem[1] << ", " << V.elem[2] << "}" << std::endl;
    return stream;
}
   
const double* Vector3::getElements() {
    double *otv;
    otv = new double[3];
    for (int i = 0; i < n; i++) {
        otv[i] = elem[i];
    }
    return otv;
}

bool operator!=(const Vector3& our, const Vector3& other) {
    return !(our == other);
}