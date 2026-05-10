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
    vector<GiaoDich *> gd;

    cout << "\n----NHAP DANH SACH GIAO DICH DAT----\n";
    for (int i = 0; i < m; i++)
    {
        cout << "\nNhap giao dich thu " << i + 1 << ": \n";
        GiaoDich *p = new GiaoDichDat;
        p->nhap();
        gd.push_back(p);
    }

    cout << "\n----NHAP DANH SACH GIAO DICH NHA----\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap giao dich thu " << i + 1 << ": \n";
        GiaoDich *p = new GiaoDichNha;
        p->nhap();
        gd.push_back(p);
    }

    double sum = 0;
    cout << "\n----NHAP DANH SACH GIAO DICH CAN HO----\n";
    for (int i = 0; i < q; i++)
    {
        cout << "\nNhap giao dich thu " << i + 1 << ": \n";
        GiaoDich *p = new GiaoDichCanHo;
        p->nhap();
        gd.push_back(p);
        sum += p->thanhTien();
    }

    cout << "\n\n-----DA NHAP XONG CAC GIAO DICH----" << endl;
    cout << "Tong so giao dich dat: " << m << endl;
    cout << "Tong so giao dich nha: " << n << endl;
    cout << "Tong so giao dich can ho: " << q << endl;

    if (q > 0)
        cout << "\nTrung binh thanh tien cua giao dich can ho chung cu: " << sum / q << endl;
    else
        cout << "\nKhong co giao dich can ho de tinh trung binh.\n";

    GiaoDichNha *nhaMax = nullptr;

    for (int i = 0; i < gd.size(); i++)
    {
        GiaoDichNha *nha = dynamic_cast<GiaoDichNha *>(gd[i]);
        if (nha != nullptr)
        {
            if (nhaMax == nullptr || nha->thanhTien() > nhaMax->thanhTien())
            {
                nhaMax = nha;
            }
        }
    }
    if (nhaMax != nullptr)
    {
        cout << "\n----Giao dich nha co gia tri cao nhat----\n";
        nhaMax->xuat();
    }
    else
    {
        cout << "\nKhong co giao dich nha.\n";
    }

    cout << "\n---Danh sach cac giao dich vao thang 12/2024---";
    int count = 1;
    for (int i = 0; i < gd.size(); i++)
    {

        if (gd[i]->getThangNgay() == "12/2024")
        {
            cout << "\nSTT: " << count++ << endl;
            gd[i]->xuat();
        }
    }
    for (int i = 0; i < gd.size(); i++)
    {
        delete gd[i];
    }
    gd.clear();
    return 0;
}