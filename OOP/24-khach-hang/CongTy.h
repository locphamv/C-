#pragma once
#include <vector>
#include <string>
#include "KhachHangA.h"
#include "KhachHangB.h"
#include "KhachHangC.h"
using namespace std;

class CongTy
{
private:
    vector<KhachHang*> ds;
    int x, y, z;

public:
    CongTy();
    ~CongTy();

    bool docFile(const string& tenFile);
    bool ghiFile(const string& tenFile) const;
    double tongSoTien() const;
};