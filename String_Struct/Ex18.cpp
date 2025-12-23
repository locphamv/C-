#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct sinhvien
{
    string maso;
    string ten;
    string ngaysinh;
    char gioitinh;
    double toan;
    double ly;
    double hoa;
    double dtb;
};

int main()
{
    int n;
    sinhvien a[10005];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].maso;
        cin.ignore();
        getline(cin, a[i].ten);
        getline(cin, a[i].ngaysinh);
        cin >> a[i].gioitinh >> a[i].toan >> a[i].ly >> a[i].hoa;
        a[i].dtb = (a[i].toan + a[i].ly + a[i].hoa) / 3;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i].maso << " " << a[i].ten << " " << a[i].ngaysinh << " " << a[i].gioitinh << " " << a[i].toan << " " << a[i].ly << " " << a[i].hoa << " " << setprecision(3) << a[i].dtb << endl;
    }

    return 0;
}