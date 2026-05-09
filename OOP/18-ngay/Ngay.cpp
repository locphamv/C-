#include "Ngay.h"
Date::Date() : ngay(0), thang(0), nam(0)
{
}

istream &operator>>(istream &is, Date &d)
{
    is >> d.ngay >> d.thang >> d.nam;
    return is;
}

ostream &operator<<(ostream &os, const Date &d)
{
    os << d.ngay << "/" << d.thang << "/" << d.nam << endl;
    return os;
}

bool operator>(const Date &d1, const Date &d2)
{
    if (d1.nam != d2.nam)
    {
        return d1.nam > d2.nam;
    }
    else if (d1.thang != d2.thang)
    {
        return d1.thang > d2.thang;
    }
    else if (d1.ngay != d2.ngay)
    {
        return d1.ngay > d2.ngay;
    }
    return false;
}
