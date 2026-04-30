#include "GiangVien.h"
#include <iomanip>
#include <limits>

GiangVien::GiangVien()
{
    soTietDay = 0;
}

int GiangVien::tinhPhuCap() const
{
    if (trinhDo == "Cu nhan")
        return 300;
    if (trinhDo == "Thac si")
        return 500;
    if (trinhDo == "Tien si")
        return 1000;
    return 0;
}

double GiangVien::tinhLuong() const
{
    return heSoLuong * 730 + tinhPhuCap() + soTietDay * 45;
}

void GiangVien::nhap()
{
    cout << "\nNhap thong tin giang vien\n";
    CanBo::nhap();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap khoa: ";
    getline(cin, khoa);

    int chon;
    cout << "Chon trinh do:\n";
    cout << "1. Cu nhan\n";
    cout << "2. Thac si\n";
    cout << "3. Tien si\n";
    cout << "Nhap lua chon: ";
    cin >> chon;

    if (chon == 1)
        trinhDo = "Cu nhan";
    else if (chon == 2)
        trinhDo = "Thac si";
    else
        trinhDo = "Tien si";

    cout << "Nhap so tiet day: ";
    cin >> soTietDay;
}

void GiangVien::xuat() const
{
    cout << "\nLoai can bo: Giang vien\n";
    CanBo::xuat();
    cout << "Khoa: " << khoa << endl;
    cout << "Trinh do: " << trinhDo << endl;
    cout << "Phu cap: " << tinhPhuCap() << endl;
    cout << "So tiet day: " << soTietDay << endl;
    cout << "Luong: " << fixed << setprecision(2) << tinhLuong() << endl;
}

void GiangVien::ghiFile(ofstream &out) const
{
    out << "GV" << endl;
    out << maSo << endl;
    out << hoTen << endl;
    out << heSoLuong << endl;
    out << khoa << endl;
    out << trinhDo << endl;
    out << soTietDay << endl;
}

void GiangVien::docFile(ifstream &in)
{
    getline(in, maSo);
    getline(in, hoTen);

    in >> heSoLuong;
    in.ignore();

    getline(in, khoa);
    getline(in, trinhDo);

    in >> soTietDay;
    in.ignore();
}