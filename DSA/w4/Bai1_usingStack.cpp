
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

void calculateStockSpan(const vector<int>& price, int n) {
   
    vector<int> span(n);
    
    
    stack<int> st;


    span[0] = 1;
    st.push(0);

    
    for (int i = 1; i < n; i++) {
        
        while (!st.empty() && price[st.top()] <= price[i]) {
            st.pop();
        }


        if (st.empty()) {
           
            span[i] = i + 1;
        } else {
           
            span[i] = i - st.top();
        }

        
        st.push(i);
    }

   
    for (int i = 0; i < n; i++) {
        cout << span[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << "\n";
}

int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    calculateStockSpan(arr, n);

    return 0;
}