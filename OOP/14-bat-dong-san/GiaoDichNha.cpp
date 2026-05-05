#include "GiaoDichNha.h"
using namespace std;
GiaoDichNha::GiaoDichNha(string loaiNha, string diaChi)
    : GiaoDich(), loaiNha(loaiNha), diaChi(diaChi)
{
}

void GiaoDichNha::nhap()
{
    GiaoDich::nhap();
    cout << "Nhap loai nha(cao cap, thuong): ";
    getline(cin >> ws, loaiNha);
    cout << "Nhap dia chi: ";
    getline(cin >> ws, diaChi);
}

void GiaoDichNha::xuat()
{
    GiaoDich::xuat();
    cout << "Loai nha: " << loaiNha << endl;
    cout << "Dia chi " << diaChi << endl;
    cout << "Thanh tien: " << thanhTien() << endl;
}

double GiaoDichNha::thanhTien()
{
    if (loaiNha == "cao cap")
    {
        return getDienTich() * getDonGia();
    }
    else
        return 0.9 * getDienTich() * getDonGia();
}