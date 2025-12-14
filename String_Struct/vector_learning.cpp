#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

// vector<kieudulieu> ten_vector
// push_back()
// size()
// Truy cap cac phan tu thong qua chi so
// Duyet qua index
// Duyet qua

int main()
{
    // vector<int> v;
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);

    // cout << v.size() << endl;
    // v.push_back(40);
    // cout << v.size() << endl;
    // cout << "Phan tu dau tien: " << v[0] << endl;
    // cout << "Phan tu cuoi cung: " << v[v.size() - 1] << endl;

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << endl;     //(Duyet qua index)
    // }

    // for (int x : v)
    // {
    //     cout << x << endl;     //duyet qua x
    // }

    // for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    // {
    //     cout << *it << endl; // Duyet bang iterator
    // }

    // for (auto it = v.begin(); it != v.end(); ++it)
    // {
    //     cout << *it << endl;  //auto thay cho khai bao iterator
    // }
    // cout << v[2] << endl;
    // cout << *(v.begin() + 2);

    // int n;
    // cin >> n;
    // vector<int> v(n);
    // // for (int i = 0; i < n; i++)
    // // {
    // //     cin >> v[i];
    // // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << v[i] << endl;
    // }
    // v.push_back(20);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << v[i] << endl;
    // }

    // vector<string> v;
    // v.push_back("Lap trinh");
    // v.push_back("DSA");
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << endl;
    // }

    string s = " ngon ngu    lap trinh  c++";
    stringstream ss(s);
    string tmp;
    vector<string> v;
    while (ss >> tmp)
    {
        v.push_back(tmp);
    }
    for (string x : v)
    {
        cout << x << " ";
    }

    return 0;
}