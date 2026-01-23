#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Nguoi
{
    int id;
    string ngay_sinh;
};

// Hàm phụ trợ: Chuyển ddmmyyyy thành yyyymmdd để so sánh
string chuyen_doi_de_so_sanh(string s)
{
    string nam = s.substr(4, 4); // Lấy từ vị trí 4, lấy 4 ký tự
    string thang = s.substr(2, 2);
    string ngay = s.substr(0, 2);
    return nam + thang + ngay;
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    if (n == 0)
    {
        cout << "EMPTY" << endl;
        return 0;
    }

    Nguoi tre_nhat;
    string max_date_val = "";

    for (int i = 0; i < n; i++)
    {
        Nguoi tam;
        cin >> tam.id >> tam.ngay_sinh;

        string val_hien_tai = chuyen_doi_de_so_sanh(tam.ngay_sinh);

        if (i == 0 || val_hien_tai > max_date_val)
        {
            max_date_val = val_hien_tai;
            tre_nhat = tam;
        }
    }

    string d = tre_nhat.ngay_sinh.substr(0, 2);
    string m = tre_nhat.ngay_sinh.substr(2, 2);
    string y = tre_nhat.ngay_sinh.substr(4, 4);

    cout << d << "-" << m << "-" << y << endl;

    return 0;
}