#pragma once
#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
  private:
    string ma;
    string hoTen;
    string lop;
    string ngaySinh;
    double GPA;

  public:
    SinhVien(string ten ="", string l="", string ns="" , double gpa=0.00);
    friend void nhap(SinhVien &);
    friend void in(const SinhVien &);
};
