#pragma once
#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
  private:
    string ma, ten, lop, email;

  public:
    SinhVien(string m="", string t="", string l="", string e=""): ma(m),ten(t),lop(l),email(e) {};
    friend istream& operator>>(istream&,SinhVien&);
    friend ostream& operator<<(ostream&, const SinhVien&);
    bool operator<(const SinhVien &other) const;
};