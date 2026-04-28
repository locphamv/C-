#include "NhanVien.h"

NhanVien::NhanVien()
{
    ma = ten = gioiTinh = ngaySinh = diaChi = maSoThue = ngayKiHopDong = "";
}

istream &operator>>(istream &is, NhanVien &nv)
{
    nv.ma = "00001";
    getline(is >> ws, nv.ten);
    is >> nv.gioiTinh >> nv.ngaySinh;
    getline(is >> ws, nv.diaChi);
    is >> nv.maSoThue >> nv.ngayKiHopDong;
    return is;
}
ostream &operator<<(ostream &os, const NhanVien &nv)
{
    os << nv.ma << " " << nv.gioiTinh << " " << nv.ngaySinh << " " << nv.diaChi << " "
       << nv.maSoThue << " " << nv.ngayKiHopDong << endl;
    return os;
}
