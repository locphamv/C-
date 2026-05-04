#pragma once
#include <iostream>
#include <string>
using namespace std;

class ChuyenXe
{
  private:
    string hoTenTaiXe, soXe;
    double maSoChuyen, doanhThu;

  public:
    ChuyenXe();

    virtual void nhap();
    virtual void xuat();
    double getDoanhThu();
};
