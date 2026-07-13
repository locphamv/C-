#include "XeTai.h"

XeTai::XeTai() : PhuongTien(), taiTrong(0), soChuyenMoiNgay(0), loaiHangHoa("") {
}

XeTai::XeTai(const string &ma, const string &hang, int nam, double gia, double taiTrong,
             int soChuyen, const string &loaiHang)
    : PhuongTien(ma, hang, nam, gia), taiTrong(taiTrong), soChuyenMoiNgay(soChuyen),
      loaiHangHoa(loaiHang) {
}

XeTai::~XeTai() {
}

double XeTai::getTaiTrong() const {
    return taiTrong;
}
int XeTai::getSoChuyenMoiNgay() const {
    return soChuyenMoiNgay;
}
string XeTai::getLoaiHangHoa() const {
    return loaiHangHoa;
}

void XeTai::setTaiTrong(double t) {
    taiTrong = t;
}
void XeTai::setSoChuyenMoiNgay(int s) {
    soChuyenMoiNgay = s;
}
void XeTai::setLoaiHangHoa(const string &l) {
    loaiHangHoa = l;
}

void XeTai::nhap(istream &in) {
    PhuongTien::nhap(in);
    cout << "Nhap tai trong (tan): ";
    in >> taiTrong;
    cout << "Nhap so chuyen trung binh moi ngay: ";
    in >> soChuyenMoiNgay;
    cout << "Nhap loai hang hoa: ";
    getline(in >> ws, loaiHangHoa);
}

void XeTai::xuat(ostream &out) const {
    out << "XE TAI:  \n";
    PhuongTien::xuat(out);
    out << "Tai trong: " << taiTrong << " tan\n";
    out << "So chuyen moi ngay: " << soChuyenMoiNgay << '\n';
    out << "Loai hang hoa: " << loaiHangHoa << '\n';
    out << "Chi phi thue: " << tinhChiPhi() << '\n';
    out << "Muc danh gia: " << danhGiaKhaiThac() << '\n';
}

double XeTai::tinhChiPhi() const {
    double heSoTaiTrong;
    if (taiTrong < 5)
        heSoTaiTrong = 1.2;
    else if (taiTrong <= 10)
        heSoTaiTrong = 1.5;
    else
        heSoTaiTrong = 2.0;

    return giaThueCoBan * heSoTaiTrong + soChuyenMoiNgay * 120000.0;
}

string XeTai::danhGiaKhaiThac() const {
    if (soChuyenMoiNgay < 5)
        return "It khai thac";
    if (soChuyenMoiNgay <= 15)
        return "Khai thac binh thuong";
    return "Khai thac cao";
}
