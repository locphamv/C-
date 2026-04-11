#include "string.h"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

String::String()
{
    s = new char[1];
    s[0] = '\0';
}

String::String(const char *str)
{
    int n = strlen(str);
    s = new char[n + 1];
    strcpy(s, str);
}

String::~String()
{
    delete[] s;
}

void String::ThietLap(const char *str)
{
    delete[] s;
    int n = strlen(str);
    s = new char[n + 1];
    strcpy(s, str);
}

int String::ChieuDai()
{
    return strlen(s);
}

void String::Noi(String b)
{
    int n1 = strlen(s);
    int n2 = strlen(b.s);

    char *tam = new char[n1 + n2 + 1];

    strcpy(tam, s);
    strcat(tam, b.s);

    delete[] s;
    s = tam;
}

void String::DaoChuoi()
{
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++)
    {
        char t = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = t;
    }
}

void String::InHoa()
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        s[i] = toupper(s[i]);
}

void String::InThuong()
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        s[i] = tolower(s[i]);
}

void String::Nhap()
{
    char tam[1000];
    cin.getline(tam, 1000);
    ThietLap(tam);
}

void String::Xuat()
{
    cout << s;
}