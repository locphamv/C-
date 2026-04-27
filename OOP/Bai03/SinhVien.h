#pragma once
#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
  private:
    string ma, hoTen, lop, ngaySinh;
    double GPA;

  public:
    SinhVien(string ten = "", string l = "", string ns = "", double gpa = 0.00);
    friend istream &operator>>(istream &, SinhVien &);
    friend ostream &operator<<(ostream &, const SinhVien &);
};
