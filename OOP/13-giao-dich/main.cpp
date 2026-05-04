#include "GiaoDichTienTe.h"
#include "GiaoDichVang.h"
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    cout << fixed << setprecision(0);
    int m, n;
    cout << "So giao dich vang: ";
    cin >> m;
    cout << "So giao dich tien te: ";
    cin >> n;

    vector<GiaoDichVang> gdv(m);
    vector<GiaoDichTienTe> gdtt(n);

    double maxVang;
    int indexVang = 0;
    cout << "Nhap danh sach cac giao dich vang:\n ";
    for (int i = 0; i < m; i++)
    {
        gdv[i].nhap();
        if (i == 0 || gdv[i].tinhTien() > maxVang)
        {
            maxVang = gdv[i].tinhTien();
            indexVang = i;
        }
    }

    double minNgoaiTe;
    int indexNgoaiTe;
    cout << "Nhap danh sach cac giao dich tien te: ";
    bool foundEuro = false;
    for (int i = 0; i < n; i++)
    {
        gdtt[i].nhap();

        if (gdtt[i].getLoaiTien() == "Euro")
        {
            if (!foundEuro || gdtt[i].tinhTien() < minNgoaiTe)
            {
                minNgoaiTe = gdtt[i].tinhTien();
                indexNgoaiTe = i;
                foundEuro = true;
            }
        }
    }

    cout << "\n------------\n";
    cout << "Giao dich vang co thanh tien cao nhat la: \n";
    gdv[indexVang].xuat();

    cout << "\nGiao dich ngoai te Euro co thanh tien thap nhat la: \n";
    gdtt[indexNgoaiTe].xuat();

    cout << "\nCac giao dich tien te co gia tri thanh tien lon hon 1 ty dong la:\n ";
    for (int i = 0; i < n; i++)
    {
        if (gdtt[i].tinhTien() > 1000000000)
        {
            cout << "\nGiao dich thu " << i + 1 << ": \n";
            gdtt[i].xuat();
            cout << endl;
        }
    }
}