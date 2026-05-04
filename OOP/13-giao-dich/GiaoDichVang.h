#include "GiaoDich.h"
#include <string>

class GiaoDichVang : public GiaoDich
{
  private:
    std::string loaiVang;

  public:
    GiaoDichVang(std::string loai = "");
    void nhap();
    void xuat();
    double tinhTien();
};
