#include "SinhVienCaoDang.h"
using namespace std;

void SinhVienCaoDang::nhap()
{
    SinhVien::nhap();
    cout << "Nhap diem tot nghiep: ";
    cin >> dtn;
}

void SinhVienCaoDang::xuat() const
{
    SinhVien::xuat();
    cout << "Diem tot nghiep: " << dtn << endl;
}

bool SinhVienCaoDang::duDieuKien() const
{
    return getTinChi() >= 110 && getDtb() >= 5.0 && dtn >= 5;
}
