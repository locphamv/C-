#pragma once
#include <string>
class cDate
{
private:
    int ngay;
    int thang;
    int nam;
    int SoNgayTrongThang(int t, int n);
    void ChuanHoa();

public:
    cDate();

    void Nhap();
    void Xuat();

    void ThietLap(int d, int m, int y);

    void DatNgay(int d);
    void DatThang(int m);
    void DatNam(int y);

    int LayNgay();
    int LayThang();
    int LayNam();

    int LaNamNhuan();
    std::string ThuTrongTuan();

    void TangNgay(int d);
    void GiamNgay(int d);

    void TangThang(int m);
    void GiamThang(int m);

    void TangNam(int y);
    void GiamNam(int y);
};
