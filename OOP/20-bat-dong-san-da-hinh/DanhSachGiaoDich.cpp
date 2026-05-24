#include "DanhSachGiaoDich.h"
#include <iostream>
using namespace std;

DanhSachGiaoDich::DanhSachGiaoDich() : soDat(0), soNha(0), soCanHo(0)
{
}

DanhSachGiaoDich::~DanhSachGiaoDich()
{
    for (int i = 0; i < gd.size(); i++)
    {
        delete gd[i];
    }
    gd.clear();
}

void DanhSachGiaoDich::nhap()
{
    cout << "Nhap so giao dich dat: ";
    cin >> soDat;
    cout << "Nhap so giao dich nha: ";
    cin >> soNha;
    cout << "Nhap so giao dich can ho: ";
    cin >> soCanHo;

    cout << "\n----NHAP DANH SACH GIAO DICH DAT----\n";
    for (int i = 0; i < soDat; i++)
    {
        cout << "\nNhap giao dich thu " << i + 1 << ": \n";
        GiaoDich* p = new GiaoDichDat;
        p->nhap();
        gd.push_back(p);
    }

    cout << "\n----NHAP DANH SACH GIAO DICH NHA----\n";
    for (int i = 0; i < soNha; i++)
    {
        cout << "\nNhap giao dich thu " << i + 1 << ": \n";
        GiaoDich* p = new GiaoDichNha;
        p->nhap();
        gd.push_back(p);
    }

    cout << "\n----NHAP DANH SACH GIAO DICH CAN HO----\n";
    for (int i = 0; i < soCanHo; i++)
    {
        cout << "\nNhap giao dich thu " << i + 1 << ": \n";
        GiaoDich* p = new GiaoDichCanHo;
        p->nhap();
        gd.push_back(p);
    }
}

void DanhSachGiaoDich::xuatThongKe() const
{
    double sum = 0;
    int demCanHo = 0;

    for (int i = 0; i < gd.size(); i++)
    {
        GiaoDichCanHo* p = dynamic_cast<GiaoDichCanHo*>(gd[i]);
        if (p != nullptr)
        {
            sum += p->thanhTien();
            demCanHo++;
        }
    }

    cout << "\n\n-----DA NHAP XONG CAC GIAO DICH----" << endl;
    cout << "Tong so giao dich dat: " << soDat << endl;
    cout << "Tong so giao dich nha: " << soNha << endl;
    cout << "Tong so giao dich can ho: " << soCanHo << endl;

    if (demCanHo > 0)
        cout << "\nTrung binh thanh tien cua giao dich can ho chung cu: " << sum / demCanHo << endl;
    else
        cout << "\nKhong co giao dich can ho de tinh trung binh.\n";
}

void DanhSachGiaoDich::xuatGiaoDichNhaCaoNhat() const
{
    GiaoDichNha* p = nullptr;

    for (int i = 0; i < gd.size(); i++)
    {
        GiaoDichNha* nha = dynamic_cast<GiaoDichNha*>(gd[i]);
        if (nha != nullptr)
        {
            if (p == nullptr || nha->thanhTien() > p->thanhTien())
            {
                p = nha;
            }
        }
    }

    if (p != nullptr)
    {
        cout << "\n----Giao dich nha co gia tri cao nhat----\n";
        p->xuat();
    }
    else
    {
        cout << "\nKhong co giao dich nha.\n";
    }
}

void DanhSachGiaoDich::xuatDanhSachThang12Nam2024() const
{
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
}