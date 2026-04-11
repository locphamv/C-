#pragma once
class cThoiGian
{
private:
    int gio;
    int phut;
    int giay;
    void ChuanHoa();

public:
    cThoiGian();
    cThoiGian(int g, int p, int s);
    void nhap();
    void xuat();
    void ThietLap(int g, int p, int s);

    void DatGio(int g);
    void DatPhut(int p);
    void DatGiay(int s);

    int LayGio();
    int LayPhut();
    int LayGiay();
    void TangGio(int g);
    void TangPhut(int p);
    void TangGiay(int s);

    void GiamGio(int g);
    void GiamPhut(int p);
    void GiamGiay(int s);
};