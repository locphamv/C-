#include <iostream>

using namespace std;

// pari<datatype1, datatype2> name;
// make_pair(a,b)
// v.first
// v.second
// {}

int main()
{
    // pair<int, int> v = {100, 200};
    // // pair <long long , long long> v;
    // // pait <string, int> v;
    // cout << v.first << endl;
    // cout << v.second << endl;

    tuple<string, int, int> t = {"python", 2, 3};
    cout << get<0>(t) << endl;
    cout << get<1>(t);

    return 0;
}