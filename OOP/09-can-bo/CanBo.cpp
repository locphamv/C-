#include "CanBo.h"
#include <iomanip>
#include <limits>

CanBo::CanBo() {
    heSoLuong = 0;
}

CanBo::~CanBo() {}

string CanBo::getMaSo() const {
    return maSo;
}

string CanBo::getHoTen() const {
    return hoTen;
}

void CanBo::nhap() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap ma so: ";
    getline(cin, maSo);

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap he so luong: ";
    cin >> heSoLuong;
}

void CanBo::xuat() const {
    cout << "Ma so: " << maSo << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "He so luong: " << heSoLuong << endl;
}

void CanBo::suaThongTin() {
    cout << "Nhap ho ten moi: ";
    getline(cin, hoTen);

    cout << "Nhap he so luong moi: ";
    cin >> heSoLuong;
}