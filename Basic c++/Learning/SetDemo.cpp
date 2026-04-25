#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    // ==========================================
    // PART 1: STD::SET (Unique & Sorted)
    // Complexity: O(log N) for insert, find, erase
    // ==========================================
    cout << "--- PART 1: SET (Unique Elements) ---" << endl;

    set<int> s;

    // 1. INSERTION (Thêm phần tử)
    // Duplicates are ignored automatically
    s.insert(100);
    s.insert(200);
    s.insert(300);
    s.insert(100); // Ignored
    s.insert(200); // Ignored

    cout << "Size: " << s.size() << endl; // Output: 3

    // 2. TRAVERSAL (Duyệt)
    // Elements are always sorted (Ascending order)
    cout << "Elements: ";
    for (int x : s)
    {
        cout << x << " ";
    }
    cout << endl;

    // 3. MIN & MAX (Lấy nhỏ nhất & Lớn nhất)
    // *s.begin()  -> First element (Min)
    // *s.rbegin() -> Last element (Max)
    if (!s.empty())
    {
        cout << "Min: " << *s.begin() << endl;
        cout << "Max: " << *s.rbegin() << endl;
    }

    // 4. SEARCHING (Tìm kiếm)
    // Method A: count() -> Returns 1 (Found) or 0 (Not Found)
    if (s.count(100) != 0)
    {
        cout << "Found 100!" << endl;
    }

    // Method B: find() -> Returns iterator
    if (s.find(999) == s.end())
    {
        cout << "999 not found!" << endl;
    }

    // 5. ERASURE (Xóa)
    s.erase(100); // Remove value 100
    // s.erase(s.begin()); // Remove the first element
    cout << "Size after erase: " << s.size() << endl;

    // ==========================================
    // PART 2: STD::MULTISET (Duplicates Allowed)
    // ==========================================
    cout << endl
         << "--- PART 2: MULTISET (Duplicates Allowed) ---" << endl;

    multiset<int> ms;
    ms.insert(100);
    ms.insert(200);
    ms.insert(100); // Accepted!

    cout << "Size of multiset: " << ms.size() << endl; // Output: 3

    cout << "Elements in multiset: ";
    for (int x : ms)
        cout << x << " ";
    cout << endl;

    // Important: count() in multiset returns frequency
    cout << "Count of 100: " << ms.count(100) << endl; // Output: 2

    // --- WARNING: ERASING IN MULTISET ---
    // CAUTION 1: erase(value) -> Removes ALL instances
    // ms.erase(100); // Would remove both 100s

    // CAUTION 2: erase(iterator) -> Removes ONE instance
    auto it = ms.find(100);
    if (it != ms.end())
    {
        ms.erase(it); // Only remove one 100
    }

    cout << "Size after removing one 100: " << ms.size() << endl;

    // ==========================================
    // PART 3: PRACTICAL EXAMPLE (String Set)
    // ==========================================
    /* // Uncomment this block to test user input
    cout << endl << "--- PART 3: String Example ---" << endl;
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    set<string> strSet;
    cin.ignore(); // Clear buffer

    for (int i = 0; i < n; i++) {
        string temp;
        getline(cin, temp);
        strSet.insert(temp);
    }

    cout << "Unique strings sorted:" << endl;
    for (string x : strSet) {
        cout << x << endl;
    }
    */

    return 0;
}