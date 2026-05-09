#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date
{
  private:
    int ngay, thang, nam;

  public:
    Date();
    friend istream &operator>>(istream &is, Date&);
    friend ostream &operator<<(ostream &os, const Date&);
    friend bool operator>(const Date&,const Date&);
};