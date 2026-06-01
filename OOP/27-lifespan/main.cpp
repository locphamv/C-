#include <bits/stdc++.h>
using namespace std;

class ConVat
{
  protected:
    int gd1, gd2, gd3, gd4;

  public:
    virtual void nhap();
    virtual void xuat() = 0;
    virtual bool khongTheoQuyLuat() = 0;
};

class Muoi : public ConVat
{
  public:
    void nhap();
    void xuat();
    bool khongTheoQuyLuat();
    int tongThoiGianThanhNhong();
};

class Ech : public ConVat
{
  private:
    int gd5;

  public:
    void nhap();
    void xuat();
    bool khongTheoQuyLuat();
};

class Buom : public ConVat
{
  public:
    void nhap();
    void xuat();
    bool khongTheoQuyLuat();
};

class DanhSachConVat
{
  private:
    int N;
    vector<ConVat *> ds;

  public:
    void nhapDanhSach();
    void xuatVongDoiKhongTheoQuyLuat();
    Muoi *thanhNhongLauNhat();
};

void ConVat::nhap()
{
    cin >> gd1 >> gd2 >> gd3 >> gd4;
}

void Muoi::nhap()
{
    ConVat::nhap();
}
void Muoi::xuat()
{
    cout << "Thoi gian de trung thanh lang quang: " << gd1<<endl;
    cout << "Thoi gian de lang quang thanh nhong: " << gd2<<endl;
    cout << "Thoi gian de nhong thanh muoi: " << gd3<<endl;
    cout << "Thoi gian de muoi de trung: " << gd4<<endl;
}
bool Muoi::khongTheoQuyLuat()
{
    if (gd1 < 1 || gd1 > 3)
    {
        return true;
    }

    if (gd2 < 4 || gd2 > 10)
    {
        return true;
    }

    if (gd3 < 2 || gd3 > 3)
    {
        return true;
    }

    if (gd4 < 5 || gd4 > 8)
    {
        return true;
    }
    return false;
}

int Muoi::tongThoiGianThanhNhong()
{
    return gd1 + gd2;
}

void Ech::nhap()
{
    ConVat::nhap();
    cin >> gd5;
}
void Ech::xuat()
{
    cout << "Thoi gian de trung thanh nong noc: " << gd1<<endl;
    cout << "Thoi gian de nong noc co chan: " << gd2<<endl;
    cout << "Thoi gian de nong noc co chan thanh ech con: " << gd3<<endl;
    cout << "Thoi gian de ech con thanh ech truong thanh : " << gd4<<endl;
    cout << "Thoi gian de ech truong thanh de trung: " << gd5<<endl;
}
bool Ech::khongTheoQuyLuat()
{
    if (gd1 < 1 || gd1 > 3)
    {
        return true;
    }

    if (gd2 != 4)
    {
        return true;
    }

    if (gd3 < 6 || gd3 > 9)
    {
        return true;
    }

    if (gd4 < 1 || gd4 > 4)
    {
        return true;
    }
    if (gd5 < 2 || gd5 > 4)
    {
        return true;
    }
    return false;
}

void Buom::nhap()
{
    ConVat::nhap();
}

void Buom::xuat()
{
    cout << "Thoi gian de trung thanh sau buom: " << gd1<<endl;
    cout << "Thoi gian de sau buom thanh nhong: " << gd2<<endl;
    cout << "Thoi gian de nhong thanh buom: " << gd3<<endl;
    cout << "Thoi gian de buom de trung: " << gd4<<endl;
}
bool Buom::khongTheoQuyLuat()
{
    if (gd1 < 3 || gd1 > 8)
    {
        return true;
    }

    if (gd2 < 15 || gd2 > 16)
    {
        return true;
    }

    if (gd3 < 10)
    {
        return true;
    }

    if (gd4 < 2 || gd4 > 3)
    {
        return true;
    }
    return false;
}

void DanhSachConVat::nhapDanhSach()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int loai;
        cin >> loai; // 1: Muoi, 2: Ech, 3: Buom

        ConVat *cv = nullptr;

        if (loai == 1)
            cv = new Muoi;
        else if (loai == 2)
            cv = new Ech;
        else if (loai == 3)
            cv = new Buom;

        cv->nhap();
        ds.push_back(cv);
    }
}  

void DanhSachConVat::xuatVongDoiKhongTheoQuyLuat()
{
    for (int i = 0; i < N; i++)
    {
        if (ds[i]->khongTheoQuyLuat())
        {
            cout << i+1 << " ";
        }
    }
    cout << endl;
}

Muoi *DanhSachConVat::thanhNhongLauNhat()
{
    int maxThanhNhong = -1;
    Muoi *p = nullptr;
    for (int i = 0; i < N; i++)
    {
        Muoi *m = dynamic_cast<Muoi *>(ds[i]);
        if (m != nullptr)
        {
            if (m->tongThoiGianThanhNhong() > maxThanhNhong)
            {
                maxThanhNhong = m->tongThoiGianThanhNhong();
                p = m;
            }
        }
    }
    return p;
}

int main()
{
    DanhSachConVat ds;
    ds.nhapDanhSach();
    ds.xuatVongDoiKhongTheoQuyLuat();
    ds.thanhNhongLauNhat()->xuat();
}