#include "QuanLyCanBo.h"
#include "GiangVien.h"
#include "NhanVienHanhChinh.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <limits>

QuanLyCanBo::QuanLyCanBo() {}

QuanLyCanBo::~QuanLyCanBo() {
    xoaDanhSachCu();
}

void QuanLyCanBo::xoaDanhSachCu() {
    for (CanBo* cb : danhSach) {
        delete cb;
    }
    danhSach.clear();
}

void QuanLyCanBo::nhapDanhSach() {
    xoaDanhSachCu();

    int n;
    cout << "Nhap so luong can bo: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int loai;

        cout << "\nNhap can bo thu " << i + 1 << endl;
        cout << "1. Giang vien\n";
        cout << "2. Nhan vien hanh chinh\n";
        cout << "Chon loai can bo: ";
        cin >> loai;

        CanBo* cb;

        if (loai == 1) {
            cb = new GiangVien();
        } else {
            cb = new NhanVienHanhChinh();
        }

        cb->nhap();
        danhSach.push_back(cb);
    }
}

void QuanLyCanBo::xuatDanhSach() const {
    if (danhSach.empty()) {
        cout << "Danh sach rong!\n";
        return;
    }

    cout << "\n===== DANH SACH CAN BO =====\n";

    for (int i = 0; i < (int)danhSach.size(); i++) {
        cout << "\nCan bo thu " << i + 1 << endl;
        danhSach[i]->xuat();
    }
}

void QuanLyCanBo::ghiFile() const {
    ofstream out("DanhSach.txt");

    if (!out) {
        cout << "Khong mo duoc file de ghi!\n";
        return;
    }

    out << danhSach.size() << endl;

    for (CanBo* cb : danhSach) {
        cb->ghiFile(out);
    }

    out.close();
    cout << "Da ghi danh sach vao file DanhSach.txt\n";
}

void QuanLyCanBo::docFile() {
    ifstream in("DanhSach.txt");

    if (!in) {
        cout << "Khong mo duoc file de doc!\n";
        return;
    }

    xoaDanhSachCu();

    int n;
    in >> n;
    in.ignore();

    for (int i = 0; i < n; i++) {
        string loai;
        getline(in, loai);

        CanBo* cb;

        if (loai == "GV") {
            cb = new GiangVien();
        } else {
            cb = new NhanVienHanhChinh();
        }

        cb->docFile(in);
        danhSach.push_back(cb);
    }

    in.close();
    cout << "Da doc danh sach tu file DanhSach.txt\n";
}

void QuanLyCanBo::sapXepTheoLuong() {
    sort(danhSach.begin(), danhSach.end(), [](CanBo* a, CanBo* b) {
        return a->tinhLuong() < b->tinhLuong();
    });

    cout << "Da sap xep danh sach theo luong tang dan.\n";
}

void QuanLyCanBo::timCanBo() const {
    int chon;
    cout << "1. Tim theo ma so\n";
    cout << "2. Tim theo ho ten\n";
    cout << "Nhap lua chon: ";
    cin >> chon;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string tuKhoa;

    if (chon == 1) {
        cout << "Nhap ma so can tim: ";
    } else {
        cout << "Nhap ho ten can tim: ";
    }

    getline(cin, tuKhoa);

    bool found = false;

    for (CanBo* cb : danhSach) {
        if ((chon == 1 && cb->getMaSo() == tuKhoa) ||
            (chon == 2 && cb->getHoTen().find(tuKhoa) != string::npos)) {
            cb->xuat();
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay can bo!\n";
    }
}

void QuanLyCanBo::suaCanBo() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ma;
    cout << "Nhap ma so can bo can sua: ";
    getline(cin, ma);

    for (CanBo* cb : danhSach) {
        if (cb->getMaSo() == ma) {
            cout << "\nThong tin hien tai:\n";
            cb->xuat();

            cout << "\nChi duoc sua ho ten va he so luong.\n";
            cb->suaThongTin();

            cout << "Da sua thong tin can bo!\n";
            return;
        }
    }

    cout << "Khong tim thay can bo co ma so nay!\n";
}

void QuanLyCanBo::tinhTongLuong() const {
    double tong = 0;

    for (CanBo* cb : danhSach) {
        tong += cb->tinhLuong();
    }

    cout << "Tong luong phai tra: " << fixed << setprecision(2) << tong << endl;
}