#pragma once
#include "XeKhach.h"
#include "XeTai.h"
#include <vector>
using namespace std;

class QLPT {
  private:
    vector<PhuongTien *> ds;

  public:
    QLPT();
    ~QLPT();

    void clear();

    string XuatKhaiThacCao() const;
    void SapXepChiPhiTangDan();

    friend istream &operator>>(istream &in, QLPT &ql);
    friend ostream &operator<<(ostream &out, const QLPT &ql);
};