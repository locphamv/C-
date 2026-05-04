#include "SachGiaoKhoa.h"
#include "SachThamKhao.h"
using namespace std;

int main()
{
    SachGiaoKhoa a, b, c;
    vector<SachThamKhao> stk(3);
    cout << "\n----Nhap thong tin sach giao khoa----" << endl;
    a.nhap();
    cout << "\n----Da nhap mot sach co thong tin----" << endl;
    a.xuat();

    cout << "\n----Nhap thong tin sach giao khoa----" << endl;
    b.nhap();
    cout << "\n----Da nhap mot sach co thong tin----" << endl;
    b.xuat();

    cout << "\n----Nhap thong tin sach giao khoa----" << endl;
    c.nhap();
    cout << "\n----Da nhap mot sach co thong tin----" << endl;
    c.xuat();

    double sumDonGia = 0;
    for (int i = 0; i < 3; i++)
    {
        cout << "\n----Nhap thong tin sach tham khao----" << endl;
        stk[i].nhap();
        cout << "\n----Da nhap mot sach co thong tin----" << endl;
        stk[i].xuat();
        sumDonGia += stk[i].getDonGia();
    }

    cout << "Trung binh don gia cua cac sach tham khao: " << sumDonGia / 3.0;

    string nxb;
    cout << "Nhap nha xuat ban: ";
    getline(cin >> ws, nxb);

    for (int i = 0; i < 3; i++)
    {
        if (stk[i].getNxb() == nxb)
        {
            cout << "\nCac sach co cung nha xuat ban " << nxb << " bao gom " << endl;
            stk[i].xuat();
        }
    }
}
