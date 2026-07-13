#include "QLPT.h"
#include <iostream>
using namespace std;

int main() {
    QLPT a; // class Quản lý phương tiện
    // Nhập vào danh sách các phương tiện (xe tải, xe khách)
    cin >> a;
    // In ra danh sách tất cả phương tiện
    cout << a;
    // Xuất ra các phương tiện khai thác cao
    cout << a.XuatKhaiThacCao();
    // Xuất danh sách phương tiện theo chi phí tăng dần
    a.SapXepChiPhiTangDan();
}