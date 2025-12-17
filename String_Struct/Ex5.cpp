
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void ChenChuoiTaiVitriK(char s[], char s1[], int k);
void Chuanhoa(char s[]);
int myStrlen(char s[], int k);
bool myStrcat(char s[], char s1[], char s2[]);
void myStrcpy(char s[], int vt, char s1[], int k);
int myStrstr(char s[], char s1[]);

int main()
{
	char s[MAX];

	fflush(stdin);
	fgets(s, MAX, stdin);

	char s1[MAX];
	myStrcpy(s1, 0, s, 0);
	Chuanhoa(s1);
	cout << s << endl
		 << s1 << endl;
	return 0;
}
// 1. Tinh do dai chuoi s bat dau tu vi tri k
int myStrlen(char s[], int k)
{
	int count = 0;
	while (s[k + count] != '\0')
	{
		count++;
	}
	return count;
}

// 2. Copy chuoi s1 (tu vi tri k) sang chuoi s (tai vi tri vt)
void myStrcpy(char s[], int vt, char s1[], int k)
{
	int i = 0;
	while (s1[k + i] != '\0')
	{
		s[vt + i] = s1[k + i];
		i++;
	}
	s[vt + i] = '\0'; // Nho gan ky tu ket thuc chuoi
}

// 3. Tim vi tri xuat hien dau tien cua s1 trong s
int myStrstr(char s[], char s1[])
{
	int n = myStrlen(s, 0);
	int m = myStrlen(s1, 0);

	if (m == 0)
		return 0; // Chuoi rong luon tim thay

	for (int i = 0; i <= n - m; i++)
	{
		int j = 0;
		// Kiem tra tung ky tu
		while (j < m && s[i + j] == s1[j])
		{
			j++;
		}
		if (j == m)
			return i; // Tim thay
	}
	return -1; // Khong tim thay
}

// 4. Noi s1 va s2 roi luu vao s (s = s1 + s2)
bool myStrcat(char s[], char s1[], char s2[])
{
	int len1 = myStrlen(s1, 0);
	int len2 = myStrlen(s2, 0);

	if (len1 + len2 >= MAX)
		return false; // Tran bo nho

	myStrcpy(s, 0, s1, 0);	  // Copy s1 vao dau s
	myStrcpy(s, len1, s2, 0); // Noi s2 vao sau s1

	return true;
}

// 5. Chen chuoi s1 vao s tai vi tri k
void ChenChuoiTaiVitriK(char s[], char s1[], int k)
{
	int lenS = myStrlen(s, 0);
	int lenS1 = myStrlen(s1, 0);

	if (lenS + lenS1 >= MAX)
	{
		cout << "Khong du bo nho de chen!" << endl;
		return;
	}
	if (k < 0 || k > lenS)
		return; // Vi tri khong hop le

	// Doi cac ky tu tu vi tri k ve phia sau de lay cho trong
	for (int i = lenS; i >= k; i--)
	{
		s[i + lenS1] = s[i];
	}

	// Chen s1 vao cho trong vua tao
	for (int i = 0; i < lenS1; i++)
	{
		s[k + i] = s1[i];
	}
}

// 6. Chuan hoa chuoi (Xoa khoang trang thua, viet hoa chu cai dau)
void Chuanhoa(char s[])
{
	int n = myStrlen(s, 0);
	char temp[MAX]; // Dung mang phu de de xu ly
	int j = 0;		// Chi so cho mang temp

	// Buoc 1: Xoa khoang trang thua va chep vao temp
	for (int i = 0; i < n; i++)
	{
		// Neu ky tu la khoang trang
		if (s[i] == ' ')
		{
			// Chi them khoang trang neu truoc do chua co khoang trang (va khong phai dau dong)
			if (j > 0 && temp[j - 1] != ' ')
			{
				temp[j++] = ' ';
			}
		}
		else
		{
			// Neu khong phai khoang trang thi chep vao
			temp[j++] = s[i];
		}
	}

	// Xoa khoang trang o cuoi neu co
	if (j > 0 && temp[j - 1] == ' ')
	{
		j--;
	}
	temp[j] = '\0'; // Ket thuc chuoi temp

	// Buoc 2: Xu ly viet hoa/thuong
	for (int i = 0; i < j; i++)
	{
		// Ky tu dau tien hoac ky tu sau dau cach thi viet Hoa
		if (i == 0 || temp[i - 1] == ' ')
		{
			temp[i] = toupper(temp[i]);
		}
		else
		{
			// Cac ky tu con lai viet thuong
			temp[i] = tolower(temp[i]);
		}
	}

	// Copy nguoc tu temp ve s
	myStrcpy(s, 0, temp, 0);
}