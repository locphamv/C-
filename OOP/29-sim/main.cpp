#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sim {
  protected:
    string seri;
    string ma;
    string sdt;
    int tinhTrang;

  public:
    virtual void nhap();
    virtual void xuat();
    virtual double tinhKm() = 0;
};

class SimTraTruoc : public Sim {
  private:
    double soDu;
    int soLanNap;

  public:
    void nhap();
    void xuat();
    double tinhKm();
    bool laATT();
};

class SimTraSau : public Sim {
  private:
    string goiCuoc;
    int soGhiNo;

  public:
    void nhap();
    void xuat();
    double tinhKm();
    int getSoGhiNo();
};

class DSSim {
  private:
    vector<Sim *> ds;

  public:
    void nhapDS();
    void xuatDS();
    double tongKm();
    void ghiNoLonNhat();
};

void Sim::nhap() {
    cin >> seri >> ma >> sdt >> tinhTrang;
}

void Sim::xuat() {
    cout << seri << " " << ma << " " << sdt << " " << tinhTrang << " ";
}

void SimTraTruoc::nhap() {
    Sim::nhap();
    cin >> soDu >> soLanNap;
}

void SimTraTruoc::xuat() {
    Sim::xuat();
    cout << soDu << " " << soLanNap << endl;
}
bool SimTraTruoc::laATT() {
    return ma == "+002";
}

double SimTraTruoc::tinhKm() {
    if (soLanNap < 5) {
        return 0.1;
    }
    if (soLanNap < 10) {
        return 0.2;
    }
    return 0.5;
}

void SimTraSau::nhap() {
    Sim::nhap();
    cin >> goiCuoc >> soGhiNo;
}

void SimTraSau::xuat() {
    Sim::xuat();
    cout << goiCuoc << " " << soGhiNo << endl;
}
double SimTraSau::tinhKm() {
    if (goiCuoc == "LCAP") {
        return 0.05;
    }
    if (goiCuoc == "MCAP") {
        return 0.1;
    }
    return 0.15;
}
int SimTraSau::getSoGhiNo() {
    return soGhiNo;
}

void DSSim::nhapDS() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int loai;
        cin >> loai;
        if (loai == 0) {
            Sim *p = new SimTraTruoc;
            p->nhap();
            ds.push_back(p);
        } else if (loai == 1) {
            Sim *p = new SimTraSau;
            p->nhap();
            ds.push_back(p);
        }
    }
}

void DSSim::xuatDS() {
    for (int i = 0; i < ds.size(); i++) {
        ds[i]->xuat();
    }
}

double DSSim::tongKm() {
    double sum = 0;
    for (int i = 0; i < ds.size(); i++) {
        SimTraTruoc *tmp = dynamic_cast<SimTraTruoc *>(ds[i]);
        if (tmp && tmp->laATT()) {
            sum += ds[i]->tinhKm();
        }
    }
    cout << sum;
    return sum;
}

void DSSim::ghiNoLonNhat() {
    SimTraSau *p = nullptr;
    for (int i = 0; i < ds.size(); i++) {
        SimTraSau *tmp = dynamic_cast<SimTraSau *>(ds[i]);
        if (tmp != nullptr) {
            if (p == nullptr || tmp->getSoGhiNo() > p->getSoGhiNo()) {
                p = tmp;
            }
        }
    }
    p->xuat();
}

int main() {
    DSSim ds;
    ds.nhapDS();
    cout << endl;
    ds.xuatDS();
    cout << endl;
    ds.tongKm();
    cout << endl;
    ds.ghiNoLonNhat();
    return 0;
}