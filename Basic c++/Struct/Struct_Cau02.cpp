#include <iostream>
#include <cmath>
using namespace std;

struct Diem
{
    int x;
    int y;
};

void nhapDiem(Diem &d)
{

    cin >> d.x >> d.y;
}

void xuatDiem(Diem d)
{
    cout << "(" << d.x << ";" << d.y << ")";
}

float khoangCachDiem(Diem d1, Diem d2)
{
    return sqrt(pow(d2.x - d1.x, 2) + pow(d2.y - d1.y, 2));
}

float khoangCachGoc(Diem d)
{
    return sqrt(pow(d.x, 2) + pow(d.y, 2));
}

int main()
{
    int n;
    cout << "Nhap so luong diem: ";
    cin >> n;

    if (n <= 0)
        return 0;

    Diem dsDiem[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap x, y diem thu " << i + 1 << ": ";
        nhapDiem(dsDiem[i]);
    }

    cout << "\n--- DANH SACH DIEM ---\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". ";
        xuatDiem(dsDiem[i]);
        cout << endl;
    }

    int v1, v2;
    cout << "\n--- Tinh khoang cach tuy chon ---\n";
    cout << "Ban muon tinh khoang cach giua diem thu may va thu may? (Nhap 2 so): ";
    cin >> v1 >> v2;

    if (v1 >= 1 && v1 <= n && v2 >= 1 && v2 <= n)
    {

        float kc = khoangCachDiem(dsDiem[v1 - 1], dsDiem[v2 - 1]);

        cout << "-> Khoang cach giua diem " << v1 << " va diem " << v2 << " la: " << kc << endl;
    }
    else
    {
        cout << "-> Loi: Vi tri diem khong hop le!" << endl;
    }

    int chiSoMax = 0;
    int chiSoMin = 0;
    float maxDist = khoangCachGoc(dsDiem[0]);
    float minDist = khoangCachGoc(dsDiem[0]);

    for (int i = 1; i < n; i++)
    {
        float dist = khoangCachGoc(dsDiem[i]);
        if (dist > maxDist)
        {
            maxDist = dist;
            chiSoMax = i;
        }
        if (dist < minDist)
        {
            minDist = dist;
            chiSoMin = i;
        }
    }

    cout << "\n--- Ket qua khac ---" << endl;
    cout << "Diem XA goc toa do nhat: ";
    xuatDiem(dsDiem[chiSoMax]);
    cout << " (kc = " << maxDist << ")" << endl;

    cout << "Diem GAN goc toa do nhat: ";
    xuatDiem(dsDiem[chiSoMin]);
    cout << " (kc = " << minDist << ")" << endl;

    return 0;
}