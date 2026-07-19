#include <bits/stdc++.h>
using namespace std;

class SinhVien {
  public:
    string maSV, ten;
    double diem;
};

bool comparator(const SinhVien &a, const SinhVien &b) {
    if (a.diem != b.diem) {
        return a.diem > b.diem;
    }
    return a.maSV < b.maSV;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<SinhVien> arr;
    for (int i = 0; i < n; i++) {
        SinhVien a;
        cin >> a.maSV >> a.ten >> a.diem;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end(), comparator);
    cout << fixed << setprecision(1);
    for (int i = 0; i < n; i++) {
        cout << arr[i].maSV << " " << arr[i].ten << " " << arr[i].diem << endl;
    }

    return 0;
}