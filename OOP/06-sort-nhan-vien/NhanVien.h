#pragma once
#include <iostream>
#include <string>
using namespace std;

class NhanVien
{
  private:
    string ten, gioiTinh, ngaySinh, diaChi, maSoThue, ngayKiHopDong;
    int ma;

  public:
    static int cnt;
    NhanVien();
    friend istream &operator>>(istream &, NhanVien &);
    friend ostream &operator<<(ostream &, const NhanVien &);
    bool operator<(const NhanVien &other) const;
};
