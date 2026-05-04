#include "GiaoDichTienTe.h"
using namespace std;

GiaoDichTienTe::GiaoDichTienTe(double gia, string tien) : GiaoDich(), tiGia(gia), loaiTien(tien)
{
}

void GiaoDichTienTe::nhap()
{
    GiaoDich::nhap();
    cout << "Nhap ti gia: ";
    cin >> tiGia;
    cout << "Nhap loai tien te: ";
    cin >> loaiTien;
}

void GiaoDichTienTe::xuat()
{
    GiaoDich::xuat();
    cout << "Ti gia: " << tiGia << endl;
    cout << "Loai tien te: " << loaiTien << endl;
    cout << "Thanh tien: " << tinhTien() << endl;
}

double GiaoDichTienTe::tinhTien()
{

    if (loaiTien == "VN")
    {
        return getDonGia() * getSoLuong();
    }

      return getDonGia() * getSoLuong() * tiGia;
}

string GiaoDichTienTe::getLoaiTien()
{
    return loaiTien;
}