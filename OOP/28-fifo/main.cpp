#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct KhachHang {
    string ma, ten;
    int soNguoi;
    double tongTien;

    void nhap();
    void xuat() const;
};

void KhachHang::nhap() {
    cout << "Nhap ma: ";
    cin >> ma;

    cout << "Nhap ten: ";
    getline(cin >> ws, ten);

    cout << "Nhap so nguoi: ";
    cin >> soNguoi;

    cout << "Nhap tong tien: ";
    cin >> tongTien;
}

void KhachHang::xuat() const {
    cout << ma << " - " << ten << " - " << soNguoi << " nguoi - " << tongTien << "k" << endl;
}

int main() {
    queue<KhachHang> ds;

    int n;
    cout << "Nhap so khach hang: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nNhap khach hang thu " << i + 1 << endl;
        KhachHang kh;
        kh.nhap();
        ds.push(kh);
    }

    if (!ds.empty()) {
        cout << "\nKhach hang o dau hang: ";
        ds.front().xuat();
    } else {
        cout << "Danh sach trong." << endl;
    }

    cout << "\nToan bo danh sach:" << endl;

    queue<KhachHang> tam = ds;
    double sum = 0;
    int stt = 1;

    while (!tam.empty()) {
        cout << stt << ". ";
        tam.front().xuat();

        sum += tam.front().tongTien;
        tam.pop();
        stt++;
    }

    cout << "\nTong tien dang cho thanh toan: " << sum << "k" << endl;

    cout << "\nTrang thai hang cho: ";
    cout << (ds.empty() ? "Danh sach trong" : "Danh sach khong trong");

    return 0;
}