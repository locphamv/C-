#include "PhuongTien.h"


PhuongTien::PhuongTien() : maPhuongTien(""), hangSanXuat(""), namSanXuat(0), giaThueCoBan(0) {
}

PhuongTien::PhuongTien(const string &ma, const string &hang, int nam, double gia)
    : maPhuongTien(ma), hangSanXuat(hang), namSanXuat(nam), giaThueCoBan(gia) {
}

PhuongTien::~PhuongTien() {
}

string PhuongTien::getMaPhuongTien() const {
    return maPhuongTien;
}
string PhuongTien::getHangSanXuat() const {
    return hangSanXuat;
}
int PhuongTien::getNamSanXuat() const {
    return namSanXuat;
}
double PhuongTien::getGiaThueCoBan() const {
    return giaThueCoBan;
}

void PhuongTien::setMaPhuongTien(const string &ma) {
    maPhuongTien = ma;
}
void PhuongTien::setHangSanXuat(const string &hang) {
    hangSanXuat = hang;
}
void PhuongTien::setNamSanXuat(int nam) {
    namSanXuat = nam;
}
void PhuongTien::setGiaThueCoBan(double gia) {
    giaThueCoBan = gia;
}

void PhuongTien::nhap(istream &in) {
    cout << "Nhap ma phuong tien: ";
    getline(in >> ws, maPhuongTien);
    cout << "Nhap hang san xuat: ";
    getline(in >> ws, hangSanXuat);
    cout << "Nhap nam san xuat: ";
    in >> namSanXuat;
    cout << "Nhap gia thue co ban: ";
    in >> giaThueCoBan;
}

void PhuongTien::xuat(ostream &out) const {
    out << "Ma phuong tien: " << maPhuongTien << '\n';
    out << "Hang san xuat: " << hangSanXuat << '\n';
    out << "Nam san xuat: " << namSanXuat << '\n';
    out << "Gia thue co ban: " << giaThueCoBan << '\n';
}
