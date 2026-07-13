#pragma once
#include <iostream>
#include <string>
using namespace std;
class PhuongTien {
  protected:
    string maPhuongTien;
    string hangSanXuat;
    int namSanXuat;
    double giaThueCoBan;

  public:
    PhuongTien();
    PhuongTien(const string &ma, const string &hang, int nam, double gia);
    virtual ~PhuongTien();

    string getMaPhuongTien() const;
    string getHangSanXuat() const;
    int getNamSanXuat() const;
    double getGiaThueCoBan() const;

    void setMaPhuongTien(const string &ma);
    void setHangSanXuat(const string &hang);
    void setNamSanXuat(int nam);
    void setGiaThueCoBan(double gia);

    virtual void nhap(istream &in);
    virtual void xuat(ostream &out) const;
    virtual double tinhChiPhi() const = 0;
    virtual string danhGiaKhaiThac() const = 0;
};
