#include "QuanLyCanBo.h"
#include <iostream>

using namespace std;

void menu()
{
    cout << "\n========== MENU ==========\n";
    cout << "1. Nhap danh sach can bo\n";
    cout << "2. In danh sach can bo ra console\n";
    cout << "3. In danh sach can bo ra file DanhSach.txt\n";
    cout << "4. Doc danh sach can bo tu file DanhSach.txt\n";
    cout << "5. Sap xep danh sach theo luong\n";
    cout << "6. Tim can bo theo ma so, ho ten\n";
    cout << "7. Sua thong tin can bo bat ky\n";
    cout << "8. Tinh tong luong phai tra\n";
    cout << "0. Thoat\n";
    cout << "==========================\n";
}

int main()
{
    QuanLyCanBo ql;
    int chon;

    do
    {
        menu();
        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon)
        {
        case 1:
            ql.nhapDanhSach();
            break;

        case 2:
            ql.xuatDanhSach();
            break;

        case 3:
            ql.ghiFile();
            break;

        case 4:
            ql.docFile();
            break;

        case 5:
            ql.sapXepTheoLuong();
            break;

        case 6:
            ql.timCanBo();
            break;

        case 7:
            ql.suaCanBo();
            break;

        case 8:
            ql.tinhTongLuong();
            break;

        case 0:
            cout << "Ket thuc chuong trinh.\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);

    return 0;
}