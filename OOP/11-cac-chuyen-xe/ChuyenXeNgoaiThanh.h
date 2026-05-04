#include "ChuyenXe.h"

class ChuyenXeNgoaiThanh : public ChuyenXe
{
  private:
    string noiDen;
    int soNgayDi;

  public:
    ChuyenXeNgoaiThanh();
    void nhapXeNgoaiThanh();
    void xuatXeNgoaiThanh();
};

