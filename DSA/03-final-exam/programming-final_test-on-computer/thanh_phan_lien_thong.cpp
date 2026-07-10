#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1005;

int n, m;
vector<int> adj[MAXN];
bool visited[MAXN];

int soDinh;

void nhapDoThi() {
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> m;

    cout << "Nhap cac canh:\n";

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void DFS(int u) {
    visited[u] = true;
    soDinh++;

    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

void lietKeThanhPhanLienThong() {
    int soThanhPhan = 0;
    int kichThuocLonNhat = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            soThanhPhan++;
            soDinh = 0;

            cout << "Thanh phan " << soThanhPhan << ": ";

            DFS(i);

            cout << endl;

            if (soDinh > kichThuocLonNhat) {
                kichThuocLonNhat = soDinh;
            }
        }
    }

    cout << "\nSo thanh phan lien thong: " << soThanhPhan << endl;

    cout << "So dinh cua thanh phan lon nhat: " << kichThuocLonNhat << endl;

    if (soThanhPhan == 1) {
        cout << "Do thi lien thong";
    } else {
        cout << "Do thi khong lien thong";
    }
}

int main() {
    nhapDoThi();

    lietKeThanhPhanLienThong();

    return 0;
}