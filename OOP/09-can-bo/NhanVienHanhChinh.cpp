#include "NhanVienHanhChinh.h"
#include <iomanip>
#include <limits>

NhanVienHanhChinh::NhanVienHanhChinh()
{
    soNgayCong = 0;
}

int NhanVienHanhChinh::tinhPhuCap() const
{
    if (chucVu == "Truong phong")
        return 2000;
    if (chucVu == "Pho phong")
        return 1000;
    if (chucVu == "Nhan vien")
        return 500;
    return 0;
}

double NhanVienHanhChinh::tinhLuong() const
{
    return heSoLuong * 730 + tinhPhuCap() + soNgayCong * 200;
}

void NhanVienHanhChinh::nhap()
{
    cout << "\nNhap thong tin nhan vien hanh chinh\n";
    CanBo::nhap();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap phong ban: ";
    getline(cin, phongBan);

    int chon;
    cout << "Chon chuc vu:\n";
    cout << "1. Truong phong\n";
    cout << "2. Pho phong\n";
    cout << "3. Nhan vien\n";
    cout << "Nhap lua chon: ";
    cin >> chon;

    if (chon == 1)
        chucVu = "Truong phong";
    else if (chon == 2)
        chucVu = "Pho phong";
    else
        chucVu = "Nhan vien";

    cout << "Nhap so ngay cong: ";
    cin >> soNgayCong;
}

void NhanVienHanhChinh::xuat() const
{
    cout << "\nLoai can bo: Nhan vien hanh chinh\n";
    CanBo::xuat();
    cout << "Phong ban: " << phongBan << endl;
    cout << "Chuc vu: " << chucVu << endl;
    cout << "Phu cap: " << tinhPhuCap() << endl;
    cout << "So ngay cong: " << soNgayCong << endl;
    cout << "Luong: " << fixed << setprecision(2) << tinhLuong() << endl;
}

void NhanVienHanhChinh::ghiFile(ofstream &out) const
{
    out << "NV" << endl;
    out << maSo << endl;
    out << hoTen << endl;
    out << heSoLuong << endl;
    out << phongBan << endl;
    out << chucVu << endl;
    out << soNgayCong << endl;
}

void NhanVienHanhChinh::docFile(ifstream &in)
{
    getline(in, maSo);
    getline(in, hoTen);

    in >> heSoLuong;
    in.ignore();

    getline(in, phongBan);
    getline(in, chucVu);

    in >> soNgayCong;
    in.ignore();
}