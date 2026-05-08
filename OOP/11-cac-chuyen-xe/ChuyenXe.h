#pragma once
#include <iostream>
#include <string>
using namespace std;

class ChuyenXe
{
  private:
    string hoTenTaiXe, soXe;
    double doanhThu;
    int maSoChuyen;

  public:
    ChuyenXe();

    virtual void nhap();
    virtual void xuat()const;
    double getDoanhThu() const;
};
