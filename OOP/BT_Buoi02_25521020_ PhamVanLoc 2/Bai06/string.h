#pragma once

class String
{
private:
    char *s;

public:
    String();
    String(const char *str);
    ~String();

    void ThietLap(const char *str);
    int ChieuDai();
    void Noi(String b);
    void DaoChuoi();
    void InHoa();
    void InThuong();

    void Nhap();
    void Xuat();
};