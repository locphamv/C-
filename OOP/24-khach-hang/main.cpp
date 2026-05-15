#include "CongTy.h"
#include <iostream>
using namespace std;

int main()
{
    CongTy ct;

    if (!ct.docFile("XYZ.INP"))
    {
        cout << "Khong mo duoc file XYZ.INP\n";
        return 1;
    }

    if (!ct.ghiFile("XYZ.OUT"))
    {
        cout << "Khong ghi duoc file XYZ.OUT\n";
        return 1;
    }

    cout << "Da xu ly xong file XYZ.INP va ghi ket qua ra XYZ.OUT\n";
    return 0;
}