#pragma once
#include <iostream>
#include <string>
using namespace std;

class NhanVien
{
  private:
    string ma, ten, gioiTinh, ngaySinh, diaChi, maSoThue, ngayKiHopDong;

  public:
    NhanVien();
    friend istream &operator>>(istream &, NhanVien &);
    friend ostream &operator<<(ostream &, const NhanVien &);
};




