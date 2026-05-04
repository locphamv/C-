#include "ChuyenXe.h"

ChuyenXe::ChuyenXe()
{
    hoTenTaiXe = soXe = "";
    maSoChuyen = doanhThu = 0;
}

void ChuyenXe::nhap()
{
    cout << "Nhap ma so chuyen: ";
    cin >> maSoChuyen;

    cout << "Nhap ho ten tai xe: ";
    getline(cin >> ws, hoTenTaiXe);

    cout << "Nhap so xe: ";
    getline(cin, soXe);

    cout << "Nhap doanh thu: ";
    cin >> doanhThu;
}

void ChuyenXe::xuat()
{
    cout << "Ma so chuyen: " << maSoChuyen;
    cout << "\n Ho ten tai xe: " << hoTenTaiXe;
    cout << "\n So xe: " << soXe;
    cout << "\nDoanh thu: " << doanhThu;
}
double ChuyenXe::getDoanhThu()
{
    return doanhThu;
}