#pragma once
#include <string>

class Vehicle
{
private:
    std::string chuXe;
    std::string loaiXe;
    float triGiaXe;
    int dungTichXylanh;

public:
    Vehicle();
    Vehicle(std::string cx, std::string lx, float tg, int dt);

    void DatChuXe(std::string cx);
    void DatLoaiXe(std::string lx);
    void DatTriGiaXe(float tg);
    void DatDungTichXylanh(int dt);

    std::string LayChuXe();
    std::string LayLoaiXe();
    float LayTriGiaXe();
    int LayDungTichXylanh();

    void Nhap();
    void Xuat();

    float TinhThueTruocBa();
};