#include "QLPT.h"
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

QLPT::QLPT() {
}

QLPT::~QLPT() {
    clear();
}

void QLPT::clear() {
    for (PhuongTien *p : ds) {
        delete p;
    }
    ds.clear();
}

string QLPT::XuatKhaiThacCao() const {
    ostringstream out;
    out << "\n PHUONG TIEN KHAI THAC CAO : \n";

    bool found = false;
    for (PhuongTien *p : ds) {
        if (p->danhGiaKhaiThac() == "Khai thac cao") {
            p->xuat(out);
            out << "\n";
            found = true;
        }
    }

    if (!found) {
        out << "Khong co phuong tien nao khai thac cao.\n";
    }

    return out.str();
}

void QLPT::SapXepChiPhiTangDan() {
    sort(ds.begin(), ds.end(),
         [](PhuongTien *a, PhuongTien *b) { return a->tinhChiPhi() < b->tinhChiPhi(); });
}

istream &operator>>(istream &in, QLPT &ql) {
    int n;
    cout << "Nhap so luong phuong tien: ";
    in >> n;

    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\nNhap loai phuong tien thu " << i + 1 << " (1. Xe tai, 2. Xe khach): ";
        in >> loai;

        PhuongTien *p = nullptr;
        if (loai == 1)
            p = new XeTai;
        else if (loai == 2)
            p = new XeKhach;

        if (p != nullptr) {
            p->nhap(in);
            ql.ds.push_back(p);
        }
    }

    return in;
}

ostream &operator<<(ostream &out, const QLPT &ql) {
    out << "\n DANH SACH PHUONG TIEN :\n";

    if (ql.ds.empty()) {
        out << "Danh sach rong.\n";
        return out;
    }

    for (int i = 0; i < ql.ds.size(); i++) {
        out << "Phuong tien thu " << i + 1 << ":\n";
        ql.ds[i]->xuat(out);
        out << endl;
    }

    return out;
}
