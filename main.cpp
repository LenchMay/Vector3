#include "Vector3.h"

using namespace std;

int main() {
    Vector3 A(17, -16, 41);
    Vector3 B(7, 51, 17);

    cout << "Degree AB: " << acos(A.getScalarProduct(B) / (A.getNorma() * B.getNorma())) << endl;

    cout << "Vector A: " << A;
    cout << "Vector B: " << B;
    cout << "Norma A: " << A.getNorma() << endl;
    cout << "Scalar AB: " << A.getScalarProduct(B) << endl;
    cout << "A * 5: " << A * 5;
    cout << "6 * A: " << 6 * A;
    cout << "A / 5: " << A / 5;
    cout << "A - B: " << A - B;
    cout << "A + B: " << A + B;
    cout << "A == B? " << (A == B) << endl;
    cout << "A[0]: " << A[0] << endl;
    cout << "A /= 5: " << (A /= 5);
    cout << "B *= 5: " << (B *= 5) << endl;
    
    Vector3 C(3);
    cout << "Vector C: " << C;
    double mas[3] = { 3, 4, 5 };
    Vector3 D(mas);
    cout << "Vector D: " << D;
    cout << "C += D: " << (C += D);
    cout << "C -= D: " << (C -= D);
    C = D;
    cout << "C = D. C: " << C << endl;

    A.normalize();
    cout << "Normalize A: " << A;

    cout<< "Normalize B: " << B.getNormalized();

    return 0;
}