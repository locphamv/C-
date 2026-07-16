#include <bits/stdc++.h>
#include <list>

using namespace std;

class HashTable {
  private:
    static const int TABLE_SIZE = 1009;

    vector<list<long long>> table;

    int hashFunction(long long x) const {
        return static_cast<int>((x % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE);
    }

  public:
    HashTable() : table(TABLE_SIZE) {
    }

    bool findValue(long long x) const {
        int index = hashFunction(x);

        for (long long value : table[index]) {
            if (value == x)
                return true;
        }

        return false;
    }

    void add(long long x) {
        if (findValue(x))
            return;

        int index = hashFunction(x);
        table[index].push_back(x);
    }

    void eraseValue(long long x) {
        int index = hashFunction(x);

        for (auto it = table[index].begin(); it != table[index].end(); ++it) {

            if (*it == x) {
                table[index].erase(it);
                return;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    HashTable hashTable;

    while (q--) {
        string operation;
        long long x;

        cin >> operation >> x;

        if (operation == "ADD") {
            hashTable.add(x);
        } else if (operation == "FIND") {
            if (hashTable.findValue(x))
                cout << "YES\n";
            else
                cout << "NO\n";
        } else if (operation == "DELETE") {
            hashTable.eraseValue(x);
        }
    }

    return 0;
}