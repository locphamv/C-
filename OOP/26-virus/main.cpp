#include <bits/stdc++.h>
using namespace std;

// De bai gia dinh da co san ham nay
double RandomDouble()
{
    return (double)rand() / RAND_MAX;
};

class Virus
{
  protected:
    string ten;
    double tiLeTuVongTB;

  public:
    Virus(string ten, double tiLe)
    {
        this->ten = ten;
        this->tiLeTuVongTB = tiLe;
    }

    string LayTen()
    {
        return ten;
    }

    virtual void XuatTCNhe() = 0;
    virtual void XuatTCNang() = 0;

    void XuLyNhiem(int mienDich, bool tiemVacxin, int &trieuChung, bool &tuVong)
    {
        double khong, nhe, heSoTuVong;

        if (tiemVacxin == false)
        {
            if (mienDich == 3)
            {
                khong = 0.50;
                nhe = 0.35;
                heSoTuVong = 0.50;
            }
            else if (mienDich == 2)
            {
                khong = 0.10;
                nhe = 0.40;
                heSoTuVong = 0.70;
            }
            else
            {
                khong = 0.05;
                nhe = 0.15;
                heSoTuVong = 1.00;
            }
        }
        else
        {
            if (mienDich == 3)
            {
                khong = 0.70;
                nhe = 0.25;
                heSoTuVong = 0.40;
            }
            else if (mienDich == 2)
            {
                khong = 0.20;
                nhe = 0.50;
                heSoTuVong = 0.60;
            }
            else
            {
                khong = 0.10;
                nhe = 0.40;
                heSoTuVong = 0.80;
            }
        }

        double r = RandomDouble();

        if (r < khong)
            trieuChung = 0; // khong trieu chung
        else if (r < khong + nhe)
            trieuChung = 1; // trieu chung nhe
        else
            trieuChung = 2; // trieu chung nang

        double xacSuatTuVong = heSoTuVong * tiLeTuVongTB;

        if (RandomDouble() < xacSuatTuVong)
            tuVong = true;
        else
            tuVong = false;
    }
};

class Covid19 : public Virus
{
  public:
    Covid19() : Virus("Covid-19", 0.04)
    {
    }

    void XuatTCNhe()
    {
        cout << "Sot, ho, mat vi giac";
    }

    void XuatTCNang()
    {
        cout << "Sot cao, ho khan, kho tho, dau dau du doi";
    }
};

class Ebola : public Virus
{
  public:
    Ebola() : Virus("Ebola", 0.50)
    {
    }

    void XuatTCNhe()
    {
        cout << "Sot, dau hong, dau co, dau dau";
    }

    void XuatTCNang()
    {
        cout << "Non mua, tieu chay, xuat huyet";
    }
};

class HIV : public Virus
{
  public:
    HIV() : Virus("HIV", 0.90)
    {
    }

    void XuatTCNhe()
    {
        cout << "Trieu chung giong cam sot";
    }

    void XuatTCNang()
    {
        cout << "Met moi, sung hach, lo loet, viem phoi, tieu chay nang";
    }
};

class VatChu
{
  private:
    string ma;
    int mienDich;
    int trieuChung[3];
    bool tuVong[3];

  public:
    void Nhap()
    {
        cin >> ma >> mienDich;
    }

    void NhiemTatCa(Virus *dsVirus[], bool tiemVacxin)
    {
        for (int i = 0; i < 3; i++)
        {
            dsVirus[i]->XuLyNhiem(mienDich, tiemVacxin, trieuChung[i], tuVong[i]);
        }
    }

    void Xuat(Virus *dsVirus[])
    {
        cout << "Ma vat chu: " << ma << endl;

        for (int i = 0; i < 3; i++)
        {
            cout << dsVirus[i]->LayTen() << ": ";

            if (trieuChung[i] == 0)
                cout << "Khong trieu chung";
            else if (trieuChung[i] == 1)
                dsVirus[i]->XuatTCNhe();
            else
                dsVirus[i]->XuatTCNang();

            if (tuVong[i] == true)
                cout << " - Tu vong";
            else
                cout << " - Khong tu vong";

            cout << endl;
        }

        cout << endl;
    }

    bool CoTrieuChungNang()
    {
        for (int i = 0; i < 3; i++)
        {
            if (trieuChung[i] == 2)
                return true;
        }
        return false;
    }

    bool CoTuVong()
    {
        for (int i = 0; i < 3; i++)
        {
            if (tuVong[i] == true)
                return true;
        }
        return false;
    }
};

int main()
{
    Virus *dsVirus[3];

    dsVirus[0] = new Covid19();
    dsVirus[1] = new Ebola();
    dsVirus[2] = new HIV();

    int N;
    cin >> N;

    VatChu ds[10000];

    for (int i = 0; i < N; i++)
    {
        ds[i].Nhap();
        ds[i].NhiemTatCa(dsVirus, false);
    }

    for (int i = 0; i < N; i++)
    {
        ds[i].Xuat(dsVirus);
    }

    int M = N;
    VatChu dsMoi[10000];

    int demNang = 0;
    int demTuVong = 0;

    for (int i = 0; i < M; i++)
    {
        dsMoi[i].Nhap();
        dsMoi[i].NhiemTatCa(dsVirus, true);

        if (dsMoi[i].CoTrieuChungNang())
            demNang++;

        if (dsMoi[i].CoTuVong())
            demTuVong++;
    }

    cout << "So vat chu gap trieu chung nang: " << demNang << endl;
    cout << "So vat chu tu vong: " << demTuVong << endl;

    return 0;
}