#include "GiaoDich.h"

class GiaoDichTienTe:public GiaoDich
{
  private:
    double tiGia;
    std::string loaiTien;

  public:
    GiaoDichTienTe(double gia = 0, std::string tien = "");
    void nhap();
    void xuat();
    double tinhTien();
    std:: string getLoaiTien();
};