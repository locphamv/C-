extern "C" int printf(const char *, ...);
extern "C" int getchar(); // Hàm lấy từng ký tự từ bàn phím

int main()
{
    char buffer[100];
    int i = 0;
    char c;

    // printf("Nhap ca ho ten: ");

    // Tự viết hàm nhập cho đến khi gặp Enter (mã 10)
    while ((c = getchar()) != 10 && i < 99)
    {
        buffer[i] = c;
        i++;
    }
    buffer[i] = 0; // Kết thúc chuỗi bằng ký tự NULL

    printf("Xin chao: %s", buffer);
    return 0;
}