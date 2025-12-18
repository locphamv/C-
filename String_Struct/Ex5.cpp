
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
int myStrlen(char s[], int k)
{
	int len = 0;
	while (s[k + len] != '\0')
	{
		len++;
	}
	return len;
}

// 2. Hàm sao chép chuỗi (theo yêu cầu đề bài)
// s: đích, vt: vị trí bắt đầu gán vào đích
// s1: nguồn, k: vị trí bắt đầu lấy từ nguồn
void myStrcpy(char s[], int vt, char s1[], int k)
{
	int i = 0;
	while (s1[k + i] != '\0')
	{
		s[vt + i] = s1[k + i];
		i++;
	}
	s[vt + i] = '\0'; // Kết thúc chuỗi đích
}

// 3. Hàm chuẩn hóa (Logic chính)
void Chuanhoa(char s[])
{
	char temp[MAX]; // Mảng tạm để xây dựng chuỗi mới
	int n = myStrlen(s, 0);

	// Xóa ký tự xuống dòng \n do fgets để lại (nếu có)
	if (n > 0 && s[n - 1] == '\n')
	{
		s[n - 1] = '\0';
		n--;
	}

	int j = 0; // Chỉ số cho chuỗi temp

	for (int i = 0; i < n; i++)
	{
		// --- XỬ LÝ DẤU CÁCH ---
		if (s[i] == ' ')
		{
			// Nếu là dấu cách đầu tiên hoặc dấu cách thừa -> Bỏ qua
			if (j == 0 || temp[j - 1] == ' ')
				continue;

			// Kiểm tra: Nếu ký tự tiếp theo là dấu chấm -> Bỏ qua dấu cách này
			// (Nguyên tắc: Trước dấu chấm không có khoảng trắng)
			int next = i + 1;
			while (next < n && s[next] == ' ')
				next++; // Bỏ qua các dấu cách thừa phía sau để nhìn thấy ký tự tiếp theo
			if (next < n && s[next] == '.')
				continue;

			// Nếu không phạm luật trên thì thêm dấu cách bình thường
			temp[j++] = ' ';
		}
		// --- XỬ LÝ DẤU CHẤM ---
		else if (s[i] == '.')
		{
			// Đảm bảo ngay trước dấu chấm không có dấu cách (xử lý an toàn)
			if (j > 0 && temp[j - 1] == ' ')
				j--;

			temp[j++] = '.'; // Thêm dấu chấm

			// Nguyên tắc: Sau dấu chấm có 1 khoảng trắng
			// Chỉ thêm nếu sau dấu chấm vẫn còn nội dung (không phải cuối chuỗi)
			if (i < n - 1)
			{
				temp[j++] = ' ';
			}
		}
		// --- CÁC KÝ TỰ KHÁC ---
		else
		{
			temp[j++] = s[i];
		}
	}

	// Xử lý cuối chuỗi: Xóa dấu cách thừa ở cuối nếu có
	if (j > 0 && temp[j - 1] == ' ')
	{
		temp[j - 1] = '\0';
	}
	else
	{
		temp[j] = '\0';
	}

	// Sao chép ngược từ temp về s
	myStrcpy(s, 0, temp, 0);
}

// --- CÁC HÀM KHÁC (Để đảm bảo đầy đủ template, dù chưa dùng tới) ---

void ChenChuoiTaiVitriK(char s[], char s1[], int k)
{
	// Logic chèn chuỗi (Empty stub)
}

bool myStrcat(char s[], char s1[], char s2[])
{
	// Logic nối chuỗi (Empty stub)
	return true;
}

int myStrstr(char s[], char s1[])
{
	// Logic tìm chuỗi (Empty stub)
	return -1;
}