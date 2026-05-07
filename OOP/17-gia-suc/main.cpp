#include "Bo.h"
#include "Cuu.h"
#include "De.h"
#include <ctime>
#include <vector>
using namespace std;

int main()
{
    srand((unsigned)time(NULL));

    int soBo, soCuu, soDe;

    cout << "Nhap so luong bo ban dau: ";
    cin >> soBo;

    cout << "Nhap so luong cuu ban dau: ";
    cin >> soCuu;

    cout << "Nhap so luong de ban dau: ";
    cin >> soDe;

    Bo bo(soBo);
    Cuu cuu(soCuu);
    De de(soDe);

    cout << "\n=== MOT HOM NGUOI CHU DI VANG, TAT CA GIA SUC DEU DOI ===\n";
    for (int i = 0; i < soBo; i++)
    {
        cout << bo.tiengKeu() << endl;
    }
    for (int i = 0; i < soCuu; i++)
    {
        cout << cuu.tiengKeu() << endl;
    }
    for (int i = 0; i < soDe; i++)
    {
        cout << de.tiengKeu() << endl;
    }

    int boSinh = bo.sinhCon();
    int cuuSinh = cuu.sinhCon();
    int deSinh = de.sinhCon();

    int suaBo = bo.choSua();
    int suaCuu = cuu.choSua();
    int suaDe = de.choSua();

    bo.setSoLuong(bo.getSoLuong() + boSinh);
    cuu.setSoLuong(cuu.getSoLuong() + cuuSinh);
    de.setSoLuong(de.getSoLuong() + deSinh);

    cout << "\n=== THONG KE SAU MOT LUA SINH VA MOT LUOT CHO SUA ===\n";
    cout << "So luong bo: " << bo.getSoLuong() << endl;
    cout << "So luong cuu: " << cuu.getSoLuong() << endl;
    cout << "So luong de: " << de.getSoLuong() << endl;

    cout << "\nSo bo sinh them: " << boSinh << endl;
    cout << "So cuu sinh them: " << cuuSinh << endl;
    cout << "So de sinh them: " << deSinh << endl;

    cout << "\nLuong sua bo cho: " << suaBo << " lit" << endl;
    cout << "Luong sua cuu cho: " << suaCuu << " lit" << endl;
    cout << "Luong sua de cho: " << suaDe << " lit" << endl;

    cout << "\nTong so lit sua tat ca gia suc da cho: " << suaBo + suaCuu + suaDe << " lit" << endl;

    return 0;
}