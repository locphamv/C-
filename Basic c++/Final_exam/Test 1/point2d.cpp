#include <iostream>
#include <string.h>
#include <cmath>
#include <iomanip>
using namespace std;

struct POINT2D
{
    int x, y;
};

void NhapMang(POINT2D s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].x >> s[i].y;
    }
}

void run(POINT2D s[], int n)
{
    POINT2D point;
    cin >> point.x >> point.y;
    float dis1 = 0;
    float dis2;
    int xmax, ymax;
    for (int i = 0; i < n; i++)
    {
        dis2 = abs(point.x - s[i].x) + abs(point.y - s[i].y);
        if (dis2 > dis1)
        {
            dis1 = dis2;
            xmax = s[i].x;
            ymax = s[i].y;
        }
    }
    cout << xmax << " " << ymax << " " << fixed << setprecision(2) << dis1;
}

int main()
{
    int n;
    cin >> n;
    POINT2D *s = new POINT2D[n];
    NhapMang(s, n);
    run(s, n);
    return 0;
}