#pragma once
#include "PhuongTien.h"

class XeTai : public PhuongTien {
  private:
    double taiTrong;
    int soChuyenMoiNgay;
    string loaiHangHoa;

  public:
    XeTai();
    XeTai(const string &ma, const string &hang, int nam, double gia, double taiTrong, int soChuyen,
          const string &loaiHang);

    ~XeTai();

    double getTaiTrong() const;
    int getSoChuyenMoiNgay() const;
    string getLoaiHangHoa() const;

    void setTaiTrong(double taiTrong);
    void setSoChuyenMoiNgay(int soChuyen);
    void setLoaiHangHoa(const string &loaiHang);

    void nhap(std::istream &in) override;
    void xuat(std::ostream &out) const override;
    double tinhChiPhi() const override;
    string danhGiaKhaiThac() const override;
};
