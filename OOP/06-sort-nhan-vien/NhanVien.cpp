#include "NhanVien.h"
#include <iomanip>
NhanVien::NhanVien()
{
    ten = gioiTinh = ngaySinh = diaChi = maSoThue = ngayKiHopDong = "";
}
int NhanVien::cnt = 0;
istream &operator>>(istream &is, NhanVien &nv)
{
    ++NhanVien::cnt;
    nv.ma = NhanVien::cnt;
    getline(is >> ws, nv.ten);
    is >> nv.gioiTinh >> nv.ngaySinh;
    getline(is >> ws, nv.diaChi);
    is >> nv.maSoThue >> nv.ngayKiHopDong;
    return is;
}
ostream &operator<<(ostream &os, const NhanVien &nv)
{
    os << setfill('0') << setw(5) << nv.ma  <<" "<< nv.ten << " "<< " " << nv.gioiTinh << " " << nv.ngaySinh << " "
       << nv.diaChi << " " << nv.maSoThue << " " << nv.ngayKiHopDong << endl;
    return os;
}

bool NhanVien::operator<(const NhanVien &other) const
{
    int nam1 = stoi(this->ngaySinh.substr(6, 4));
    int nam2 = stoi(other.ngaySinh.substr(6, 4));

    int ngay1 = stoi(this->ngaySinh.substr(3, 2));
    int ngay2 = stoi(other.ngaySinh.substr(3, 2));

    int thang1 = stoi(this->ngaySinh.substr(0, 2));
    int thang2 = stoi(other.ngaySinh.substr(0, 2));

    if (nam1 != nam2)
        return nam1 < nam2;

    if (thang1 != thang2)
        return thang1 < thang2;

    if (ngay1 != ngay2)
        return ngay1 < ngay2;
    return false;
}
