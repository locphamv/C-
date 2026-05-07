#include "SinhVien.h"
using namespace std;

void SinhVien::nhap()
{
    cout << "Nhap ma so sinh vien: ";
    cin >> maSV;
    cout << "Nhap ho va ten: ";
    getline(cin>>ws,hoTen);
    cout << "Nhap dia chi: ";
    getline(cin >> ws, diaChi);
    cout << "Nhap so tin chi: ";
    cin >> tongTinChi;
    cout << "Nhap diem trung binh: ";
    cin >> dtb;
}

void SinhVien::xuat() const
{
    cout << "Ma so sinh vien: " << maSV << endl;
    cout << "Ho va ten: " << hoTen << endl;
    cout << "Dia chi: " << diaChi << endl;
    cout << "So tin chi: " << tongTinChi << endl;
    cout << "Diem trung binh: " << dtb << endl;
}

int SinhVien::getTinChi() const
{
    return tongTinChi;
}

double SinhVien::getDtb() const
{
    return dtb;
}