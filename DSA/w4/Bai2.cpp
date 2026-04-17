#include <iostream>
#include <string>

using namespace std;

string removeDuplicates(string s) {
    string stack_str = ""; 
    
    for (char c : s) {
        if (!stack_str.empty() && stack_str.back() == c) {
            stack_str.pop_back(); 
        } else {
            stack_str.push_back(c); 
        }
    }
    
    return stack_str;
}

int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        cout << removeDuplicates(s) << "\n";
    }

    return 0;
}