#pragma once
#include "PhuongTien.h"

class XeKhach : public PhuongTien {
  private:
    int soChoNgoi;
    int soTuyenMoiNgay;
    string loaiTuyen;

  public:
    XeKhach();

    XeKhach(const string &ma, const string &hang, int nam, double gia, int soCho, int soTuyen,
            const string &loaiTuyen);

    ~XeKhach();

    int getSoChoNgoi() const;
    int getSoTuyenMoiNgay() const;
    string getLoaiTuyen() const;

    void setSoChoNgoi(int soCho);
    void setSoTuyenMoiNgay(int soTuyen);
    void setLoaiTuyen(const string &loaiTuyen);

    void nhap(istream &in) override;
    void xuat(ostream &out) const override;
    double tinhChiPhi() const override;
    string danhGiaKhaiThac() const override;
};
