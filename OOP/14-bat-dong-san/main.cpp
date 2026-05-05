#include "GiaoDichCanHo.h"
#include "GiaoDichDat.h"
#include "GiaoDichNha.h"
using namespace std;
#include <sstream>
#include <vector>

int main()
{
    int m, n, q;
    cout << "Nhap so giao dich dat: ";
    cin >> m;
    cout << "Nhap so giao dich nha: ";
    cin >> n;
    cout << "Nhap so giao dich can ho: ";
    cin >> q;
    vector<GiaoDichDat> gdd(m);
    vector<GiaoDichNha> gdn(n);
    vector<GiaoDichCanHo> gdch(q);

    cout << "\n----NHAP DANH SACH GIAO DICH DAT----\n";
    for (int i = 0; i < m; i++)
    {
        cout << "\nNhap giao dich thu " << i + 1 << ": \n";
        gdd[i].nhap();
    }

    double caoNhat;
    int indexNha;

    cout << "\n----NHAP DANH SACH GIAO DICH NHA----\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap giao dich thu " << i + 1 << ": \n";
        gdn[i].nhap();
        if (i == 0 || gdn[i].thanhTien() > caoNhat)
        {
            caoNhat = gdn[i].thanhTien();
            indexNha = i;
        }
    }

    double sum = 0;

    cout << "\n----NHAP DANH SACH GIAO DICH CAN HO----\n";
    for (int i = 0; i < q; i++)
    {
        cout << "\nNhap giao dich thu " << i + 1 << ": \n";
        gdch[i].nhap();
        sum += gdch[i].thanhTien();
    }

    cout << "\n\n-----DA NHAP XONG CAC GIAO DICH----" << endl;
    cout << "Tong so giao dich dat: " << m << endl;
    cout << "Tong so giao dich nha: " << n << endl;
    cout << "Tong so giao dich can ho: " << q << endl;

    cout << "\nTrung binh thanh tien cua giao dich can ho chung cu: " << sum / q << endl;

    cout << "\n----Giao dich nha co gia tri cao nhat----\n";
    gdn[indexNha].xuat();

    cout << "\n---Danh sach cac giao dich vao thang 12/2024---";
    int count = 1;
    for (int i = 0; i < m; i++)
    {

        if (gdd[i].getThangNgay() == "12/2024")
        {
            cout << "\nSTT: " << count++ << endl;
            gdd[i].xuat();
        }
    }
    for (int i = 0; i < n; i++)
    {

        if (gdn[i].getThangNgay() == "12/2024")
        {
            cout << "\nSTT: " << count++ << endl;
            gdn[i].xuat();
        }
    }

    for (int i = 0; i < q; i++)
    {

        if (gdch[i].getThangNgay() == "12/2024")
        {
            cout << "\nSTT: " << count++ << endl;
            gdch[i].xuat();
        }
    }
}