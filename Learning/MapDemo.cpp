#include <iostream>
#include <map>

using namespace std;

int main()
{
    // map<Key_Type, Value_Type> map_name;
    map<int, int> mp;

    // --- 1. INSERTION (Thêm phần tử) ---

    // Method 1: Using [] operator
    // Meaning: If key exists -> Update value. If not -> Create new.
    mp[100] = 200;
    mp[200] = 300;

    // Method 2: Using insert()
    // Meaning: Only insert if the key does NOT exist.
    mp.insert({300, 400});
    mp.insert({400, 500});

    cout << "Initial size: " << mp.size() << endl
         << endl;

    // --- 2. ITERATION (Duyệt Map) ---
    cout << "--- Iterate through Map ---" << endl;

    // Best Practice: Using 'auto' (Modern C++)
    for (auto it : mp)
    {
        cout << "Key: " << it.first << " -> Value: " << it.second << endl;
    }

    // --- 3. SEARCHING (Tìm kiếm) ---
    cout << endl
         << "--- Searching ---" << endl;

    int searchKey = 200;

    // Method A: Using count() (Recommended for checking existence)
    // Returns 1 if found, 0 if not found.
    if (mp.count(searchKey) != 0)
    {
        cout << "Found key " << searchKey << "!" << endl;
    }
    else
    {
        cout << "Key " << searchKey << " not found!" << endl;
    }

    // Method B: Using find() (Returns an iterator)
    if (mp.find(999) == mp.end())
    {
        cout << "Key 999 not found (checked via find function)." << endl;
    }

    // --- 4. DELETION (Xóa) ---
    cout << endl
         << "--- Deletion ---" << endl;
    mp.erase(200); // Remove key 200 from the map
    cout << "Deleted key 200. Current size: " << mp.size() << endl;

    // --- 5. WARNING: THE [] OPERATOR TRAP (Cạm bẫy toán tử []) ---
    cout << endl
         << "--- Warning: The [] Operator Trap ---" << endl;

    // Scenario: We try to access a key that does NOT exist (e.g., 9999)
    // PROBLEM: Map will automatically CREATE this key with a default value (0).

    cout << "Size BEFORE accessing non-existent key: " << mp.size() << endl;

    cout << "Value of non-existent key (9999): " << mp[9999] << endl; // Auto-created here!

    cout << "Size AFTER accessing non-existent key: " << mp.size() << endl; // Size increased!

    return 0;
}