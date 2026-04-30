#ifndef CANBO_H
#define CANBO_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CanBo {
protected:
    string maSo;
    string hoTen;
    double heSoLuong;

public:
    CanBo();
    virtual ~CanBo();

    string getMaSo() const;
    string getHoTen() const;

    virtual void nhap();
    virtual void xuat() const;

    void suaThongTin();

    virtual double tinhLuong() const = 0;
    virtual void ghiFile(ofstream& out) const = 0;
    virtual void docFile(ifstream& in) = 0;
};

#endif