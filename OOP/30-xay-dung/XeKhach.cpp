#include "XeKhach.h"

XeKhach::XeKhach() : PhuongTien(), soChoNgoi(0), soTuyenMoiNgay(0), loaiTuyen("") {
}

XeKhach::XeKhach(const string &ma, const string &hang, int nam, double gia, int soCho, int soTuyen,
                 const string &loai)
    : PhuongTien(ma, hang, nam, gia), soChoNgoi(soCho), soTuyenMoiNgay(soTuyen), loaiTuyen(loai) {
}

XeKhach::~XeKhach() {
}

int XeKhach::getSoChoNgoi() const {
    return soChoNgoi;
}
int XeKhach::getSoTuyenMoiNgay() const {
    return soTuyenMoiNgay;
}
string XeKhach::getLoaiTuyen() const {
    return loaiTuyen;
}

void XeKhach::setSoChoNgoi(int s) {
    soChoNgoi = s;
}
void XeKhach::setSoTuyenMoiNgay(int s) {
    soTuyenMoiNgay = s;
}
void XeKhach::setLoaiTuyen(const string &l) {
    loaiTuyen = l;
}

void XeKhach::nhap(istream &in) {
    PhuongTien::nhap(in);
    cout << "Nhap so cho ngoi: ";
    in >> soChoNgoi;
    cout << "Nhap so tuyen hoat dong moi ngay: ";
    in >> soTuyenMoiNgay;
    cout << "Nhap loai tuyen (noi thanh/lien tinh): ";
    getline(in >> ws, loaiTuyen);
}

void XeKhach::xuat(ostream &out) const {
    out << " XE KHACH : \n";
    PhuongTien::xuat(out);
    out << "So cho ngoi: " << soChoNgoi << '\n';
    out << "So tuyen moi ngay: " << soTuyenMoiNgay << '\n';
    out << "Loai tuyen: " << loaiTuyen << '\n';
    out << "Chi phi thue: " << tinhChiPhi() << '\n';
    out << "Muc danh gia: " << danhGiaKhaiThac() << '\n';
}

double XeKhach::tinhChiPhi() const {
    double heSoChoNgoi;
    if (soChoNgoi < 20)
        heSoChoNgoi = 1.1;
    else if (soChoNgoi <= 40)
        heSoChoNgoi = 1.4;
    else
        heSoChoNgoi = 1.8;

    return giaThueCoBan * heSoChoNgoi + soTuyenMoiNgay * 150000.0;
}

string XeKhach::danhGiaKhaiThac() const {
    if (soTuyenMoiNgay < 3)
        return "It khai thac";
    if (soTuyenMoiNgay <= 8)
        return "Khai thac binh thuong";
    return "Khai thac cao";
}
