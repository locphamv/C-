#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

enum class NhienLieu
{
    NONE,
    E5,
    A95,
    DO
};

string toString(NhienLieu nl)
{
    switch (nl)
    {
    case NhienLieu::E5:
        return "E5";
    case NhienLieu::A95:
        return "A95";
    case NhienLieu::DO:
        return "DO";
    default:
        return "NONE";
    }
}

NhienLieu parseNhienLieu(const string &s)
{
    if (s == "E5")
        return NhienLieu::E5;
    if (s == "A95")
        return NhienLieu::A95;
    if (s == "DO")
        return NhienLieu::DO;
    return NhienLieu::NONE;
}

class PhuongTien
{
  protected:
    string bienSo;

  public:
    virtual ~PhuongTien() = default;
    virtual void nhap(istream &in) = 0;
    virtual void xuat(ostream &out) const = 0;
    virtual bool canBom() const
    {
        return false;
    }
    virtual NhienLieu nhienLieuToiUu() const
    {
        return NhienLieu::NONE;
    }
    virtual double litCanBom() const
    {
        return 0.0;
    }
};

class XeThoSo : public PhuongTien
{
  public:
    void nhap(istream &in) override
    {
        getline(in >> ws, bienSo);
    }

    void xuat(ostream &out) const override
    {
        out << "Xe tho so - Bien so: " << bienSo << '\n';
    }
};

class XeCoGioi : public PhuongTien
{
  protected:
    double dungTichBinh;
    double nhienLieuHienTai;
    double tiSoNen;

  public:
    XeCoGioi() : dungTichBinh(0), nhienLieuHienTai(0), tiSoNen(0)
    {
    }

    bool canBom() const override
    {
        return true;
    }

    double litCanBom() const override
    {
        return max(0.0, dungTichBinh - nhienLieuHienTai);
    }

    void nhapCoGioi(istream &in)
    {
        getline(in >> ws, bienSo);
        in >> dungTichBinh >> nhienLieuHienTai >> tiSoNen;
    }
};

class XeMay : public XeCoGioi
{
  public:
    void nhap(istream &in) override
    {
        nhapCoGioi(in);
    }

    void xuat(ostream &out) const override
    {
        out << "Xe may - Bien so: " << bienSo << ", Dung tich binh: " << dungTichBinh
            << ", Nhien lieu hien tai: " << nhienLieuHienTai << ", Ti so nen: " << tiSoNen << '\n';
    }

    NhienLieu nhienLieuToiUu() const override
    {
        return (tiSoNen >= 9.5) ? NhienLieu::A95 : NhienLieu::E5;
    }
};

class OToXang : public XeCoGioi
{
  public:
    void nhap(istream &in) override
    {
        nhapCoGioi(in);
    }

    void xuat(ostream &out) const override
    {
        out << "O to xang - Bien so: " << bienSo << ", Dung tich binh: " << dungTichBinh
            << ", Nhien lieu hien tai: " << nhienLieuHienTai << ", Ti so nen: " << tiSoNen << '\n';
    }

    NhienLieu nhienLieuToiUu() const override
    {
        return (tiSoNen >= 9.5) ? NhienLieu::A95 : NhienLieu::E5;
    }
};

class OToDiesel : public XeCoGioi
{
  public:
    void nhap(istream &in) override
    {
        nhapCoGioi(in);
    }

    void xuat(ostream &out) const override
    {
        out << "O to diesel - Bien so: " << bienSo << ", Dung tich binh: " << dungTichBinh
            << ", Nhien lieu hien tai: " << nhienLieuHienTai << '\n';
    }

    NhienLieu nhienLieuToiUu() const override
    {
        return NhienLieu::DO;
    }
};

class Nguoi
{
  private:
    string maDinhDanh;
    string hoTen;
    vector<PhuongTien *> dsXe;

  public:
    ~Nguoi()
    {
        for (PhuongTien *p : dsXe)
            delete p;
        dsXe.clear();
    }

    void nhap(istream &in)
    {
        getline(in >> ws, maDinhDanh);
        getline(in >> ws, hoTen);

        int soPhuongTien;
        in >> soPhuongTien;

        for (int i = 0; i < soPhuongTien; i++)
        {
            int loai;
            in >> loai;

            PhuongTien *p = nullptr;
            if (loai == 1)
                p = new XeThoSo;
            else if (loai == 2)
                p = new XeMay;
            else if (loai == 3)
                p = new OToXang;
            else if (loai == 4)
                p = new OToDiesel;

            if (p != nullptr)
            {
                p->nhap(in);
                dsXe.push_back(p);
            }
        }
    }

    string getMa() const
    {
        return maDinhDanh;
    }

    const vector<PhuongTien *> &getDSXe() const
    {
        return dsXe;
    }

    void xuat(ostream &out) const
    {
        out << "Nguoi: " << maDinhDanh << " - " << hoTen << '\n';
        for (PhuongTien *p : dsXe)
            p->xuat(out);
    }
};

struct LoNhap
{
    NhienLieu loai;
    double soLit;
    double donGiaNhap;
};

class BonChua
{
  private:
    NhienLieu loai;
    double sucChua;
    vector<LoNhap> dsLo;

  public:
    BonChua() : loai(NhienLieu::NONE), sucChua(0)
    {
    }
    BonChua(NhienLieu l, double s) : loai(l), sucChua(s)
    {
    }

    void setThongTin(NhienLieu l, double s)
    {
        loai = l;
        sucChua = s;
    }

    NhienLieu getLoai() const
    {
        return loai;
    }

    void themLo(double soLit, double donGiaNhap)
    {
        dsLo.push_back({loai, soLit, donGiaNhap});
    }

    double tonKho() const
    {
        double tong = 0;
        for (const LoNhap &lo : dsLo)
            tong += lo.soLit;
        return tong;
    }

    double tongGiaVon() const
    {
        double tong = 0;
        for (const LoNhap &lo : dsLo)
            tong += lo.soLit * lo.donGiaNhap;
        return tong;
    }
};

class CayXang
{
  private:
    string maCay;
    string tenCay;

    int soTruE5, soTruA95, soTruDO;
    double giaBanE5, giaBanA95, giaBanDO;

    BonChua bonE5, bonA95, bonDO;

  public:
    CayXang() : soTruE5(0), soTruA95(0), soTruDO(0), giaBanE5(-1), giaBanA95(-1), giaBanDO(-1)
    {
    }

    void nhap(istream &in)
    {
        getline(in >> ws, maCay);
        getline(in >> ws, tenCay);

        in >> soTruE5 >> soTruA95 >> soTruDO;

        double sucChuaE5, sucChuaA95, sucChuaDO;
        in >> sucChuaE5 >> sucChuaA95 >> sucChuaDO;

        bonE5.setThongTin(NhienLieu::E5, sucChuaE5);
        bonA95.setThongTin(NhienLieu::A95, sucChuaA95);
        bonDO.setThongTin(NhienLieu::DO, sucChuaDO);

        in >> giaBanE5 >> giaBanA95 >> giaBanDO;

        int soLoNhap;
        in >> soLoNhap;
        for (int i = 0; i < soLoNhap; i++)
        {
            string loai;
            double soLit, donGiaNhap;
            in >> loai >> soLit >> donGiaNhap;

            NhienLieu nl = parseNhienLieu(loai);
            if (nl == NhienLieu::E5)
                bonE5.themLo(soLit, donGiaNhap);
            else if (nl == NhienLieu::A95)
                bonA95.themLo(soLit, donGiaNhap);
            else if (nl == NhienLieu::DO)
                bonDO.themLo(soLit, donGiaNhap);
        }
    }

    string getMa() const
    {
        return maCay;
    }

    bool coBan(NhienLieu nl) const
    {
        if (nl == NhienLieu::E5)
            return soTruE5 > 0 && giaBanE5 >= 0;
        if (nl == NhienLieu::A95)
            return soTruA95 > 0 && giaBanA95 >= 0;
        if (nl == NhienLieu::DO)
            return soTruDO > 0 && giaBanDO >= 0;
        return false;
    }

    double giaBan(NhienLieu nl) const
    {
        if (nl == NhienLieu::E5)
            return giaBanE5;
        if (nl == NhienLieu::A95)
            return giaBanA95;
        if (nl == NhienLieu::DO)
            return giaBanDO;
        return 0;
    }

    double tonKho(NhienLieu nl) const
    {
        if (nl == NhienLieu::E5)
            return bonE5.tonKho();
        if (nl == NhienLieu::A95)
            return bonA95.tonKho();
        if (nl == NhienLieu::DO)
            return bonDO.tonKho();
        return 0;
    }

    double loiNhuanNeuBanHet() const
    {
        double doanhThu = 0;
        double giaVon = 0;

        if (coBan(NhienLieu::E5))
        {
            doanhThu += bonE5.tonKho() * giaBanE5;
            giaVon += bonE5.tongGiaVon();
        }
        if (coBan(NhienLieu::A95))
        {
            doanhThu += bonA95.tonKho() * giaBanA95;
            giaVon += bonA95.tongGiaVon();
        }
        if (coBan(NhienLieu::DO))
        {
            doanhThu += bonDO.tonKho() * giaBanDO;
            giaVon += bonDO.tongGiaVon();
        }

        return doanhThu - giaVon;
    }

    void xuat(ostream &out) const
    {
        out << maCay << " - " << tenCay << '\n';
    }
};

class HeThong
{
  private:
    vector<Nguoi *> dsNguoi;
    vector<CayXang *> dsCay;

  public:
    ~HeThong()
    {
        for (Nguoi *p : dsNguoi)
            delete p;
        for (CayXang *p : dsCay)
            delete p;
        dsNguoi.clear();
        dsCay.clear();
    }

    void nhapNguoi(istream &in)
    {
        int nNguoi;
        in >> nNguoi;
        for (int i = 0; i < nNguoi; i++)
        {
            Nguoi *p = new Nguoi;
            p->nhap(in);
            dsNguoi.push_back(p);
        }
    }

    void nhapCayXang(istream &in)
    {
        int nCay;
        in >> nCay;
        for (int i = 0; i < nCay; i++)
        {
            CayXang *p = new CayXang;
            p->nhap(in);
            dsCay.push_back(p);
        }
    }

    void xuatLoiLoCacCayXang() const
    {
        cout << "\n===== CAU 2: LOI/LO CAC CAY XANG =====\n";
        for (const CayXang *cx : dsCay)
        {
            cx->xuat(cout);
            double loiLo = cx->loiNhuanNeuBanHet();
            cout << "Loi/Lo neu ban het ton kho hien co: " << fixed << setprecision(2) << loiLo
                 << "\n\n";
        }
    }

    Nguoi *timNguoi(const string &ma) const
    {
        for (Nguoi *p : dsNguoi)
            if (p->getMa() == ma)
                return p;
        return nullptr;
    }

    CayXang *timCay(const string &ma) const
    {
        for (CayXang *p : dsCay)
            if (p->getMa() == ma)
                return p;
        return nullptr;
    }

    double chiPhiBomDay(const string &maNguoi, const string &maCay, bool &ok) const
    {
        ok = false;

        Nguoi *nguoi = timNguoi(maNguoi);
        CayXang *cay = timCay(maCay);

        if (nguoi == nullptr || cay == nullptr)
            return 0;

        map<NhienLieu, double> nhuCau;
        for (PhuongTien *p : nguoi->getDSXe())
        {
            if (p->canBom())
            {
                NhienLieu nl = p->nhienLieuToiUu();
                nhuCau[nl] += p->litCanBom();
            }
        }

        for (auto &it : nhuCau)
        {
            NhienLieu nl = it.first;
            double soLitCan = it.second;

            if (!cay->coBan(nl) || cay->tonKho(nl) < soLitCan)
            {
                return 0;
            }
        }

        double tongTien = 0;
        for (auto &it : nhuCau)
        {
            tongTien += it.second * cay->giaBan(it.first);
        }

        ok = true;
        return tongTien;
    }
};

int main()
{
    HeThong ht;

    cout << "===== NHAP DANH SACH NGUOI VA PHUONG TIEN =====\n";
    ht.nhapNguoi(cin);

    cout << "\n===== NHAP DANH SACH CAY XANG =====\n";
    ht.nhapCayXang(cin);

    ht.xuatLoiLoCacCayXang();

    string maNguoi, maCay;
    cout << "Nhap ma nguoi can tinh: ";
    cin >> maNguoi;
    cout << "Nhap ma cay xang can chon: ";
    cin >> maCay;

    bool ok;
    double tien = ht.chiPhiBomDay(maNguoi, maCay, ok);

    cout << "\n===== CAU 3 =====\n";
    if (ok)
    {
        cout << "So tien can de bom day binh tat ca xe cua nguoi nay: " << fixed << setprecision(2)
             << tien << '\n';
    }
    else
    {
        cout << "Khong the bom day: nguoi/cay xang khong ton tai hoac cay xang khong du/khong co "
                "nhien lieu phu hop.\n";
    }

    return 0;
}