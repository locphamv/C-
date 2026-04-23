#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> student;
    queue<int> lunch;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        student.push(x);
    }
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        lunch.push(y);
    }

    long long count = 0;
    while (!student.empty() && count < student.size())
    {
        if (student.front() == lunch.front())
        {
            student.pop();
            lunch.pop();
            count = 0;
        }
        else
        {
            student.push(student.front());
            student.pop();
            count++;
        }
    }
    cout << student.size();
}