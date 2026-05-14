#include "DSGiaSuc.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    DSGiaSuc ds;
    ds.nhap();
    cout << "\n=== MOT HOM NGUOI CHU DI VANG, TAT CA GIA SUC DEU DOI ===\n";
    ds.giaSucKeu();
    ds.sauSinhVaChoSua();
    return 0;
}