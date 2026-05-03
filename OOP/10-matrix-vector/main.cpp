#include <iostream>
#include "CVector.h"
#include "CMatrix.h"
using namespace std;

int main()
{
    CVector v1, v2, v3;
    CMatrix A, B, C;

    cout << "Nhap vector v1:" << endl;
    cin >> v1;

    cout << "\nNhap vector v2:" << endl;
    cin >> v2;

    cout << "\nNhap ma tran A:" << endl;
    cin >> A;

    cout << "\nNhap ma tran B:" << endl;
    cin >> B;

    cout << "\nVector v1 = " << v1 << endl;
    cout << "Vector v2 = " << v2 << endl;

    cout << "\nMa tran A:" << endl;
    cout << A << endl;

    cout << "Ma tran B:" << endl;
    cout << B << endl;

    v3 = v1 + v2;
    cout << "v1 + v2 = " << v3 << endl;

    v3 = v1 - v2;
    cout << "v1 - v2 = " << v3 << endl;

    C = A + B;
    cout << "\nA + B:" << endl;
    cout << C << endl;

    C = A - B;
    cout << "A - B:" << endl;
    cout << C << endl;

    cout << "A * v1 = " << nhan(A, v1) << endl;

    C = nhan(A, B);
    cout << "\nA * B:" << endl;
    cout << C << endl;

    cout << "\nMinh hoa da hinh:" << endl;
    CDoiTuongToanHoc* ds[2];
    ds[0] = &v1;
    ds[1] = &A;

    for (int i = 0; i < 2; i++)
    {
        ds[i]->xuat(cout);
        cout << endl;
    }

    return 0;
}