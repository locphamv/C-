#include "DSGiaSuc.h"
using namespace std;

void DSGiaSuc::nhap()
{
    int soBo, soCuu, soDe;

    cout << "Nhap so luong bo ban dau: ";
    cin >> soBo;

    cout << "Nhap so luong cuu ban dau: ";
    cin >> soCuu;

    cout << "Nhap so luong de ban dau: ";
    cin >> soDe;

    ds.push_back(new Bo(soBo));
    ds.push_back(new Cuu(soCuu));
    ds.push_back(new De(soDe));
}

void DSGiaSuc::giaSucKeu()
{
    for (int i = 0; i < ds.size(); i++)
    {
        for (int j = 0; j < ds[i]->getSoLuong(); j++)
        {
            cout << ds[i]->tiengKeu() << endl;
        }
    }
}

void DSGiaSuc::sauSinhVaChoSua()
{
    int boSinh = ds[0]->sinhCon();
    int cuuSinh = ds[1]->sinhCon();
    int deSinh = ds[2]->sinhCon();

    int suaBo = ds[0]->choSua();
    int suaCuu = ds[1]->choSua();
    int suaDe = ds[2]->choSua();

    ds[0]->setSoLuong(ds[0]->getSoLuong() + boSinh);
    ds[1]->setSoLuong(ds[1]->getSoLuong() + cuuSinh);
    ds[2]->setSoLuong(ds[2]->getSoLuong() + deSinh);

    cout << "\n=== THONG KE SAU MOT LUA SINH VA MOT LUOT CHO SUA ===\n";
    cout << "So luong bo: " << ds[0]->getSoLuong() << endl;
    cout << "So luong cuu: " << ds[1]->getSoLuong() << endl;
    cout << "So luong de: " << ds[2]->getSoLuong() << endl;

    cout << "\nSo bo sinh them: " << boSinh << endl;
    cout << "So cuu sinh them: " << cuuSinh << endl;
    cout << "So de sinh them: " << deSinh << endl;

    cout << "\nLuong sua bo cho: " << suaBo << " lit" << endl;
    cout << "Luong sua cuu cho: " << suaCuu << " lit" << endl;
    cout << "Luong sua de cho: " << suaDe << " lit" << endl;

    cout << "\nTong so lit sua tat ca gia suc da cho: " << suaBo + suaCuu + suaDe << " lit" << endl;
}

DSGiaSuc::~DSGiaSuc()
{
    for (int i = 0; i < ds.size(); i++)
    {
        delete ds[i];
    }
    ds.clear();
}