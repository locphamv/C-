# Employee Management with Inheritance and Polymorphism
# Quản lý nhân viên với Kế thừa và Đa hình

## 1. Giới thiệu

Bài này mô phỏng việc quản lý nhân viên trong công ty phần mềm với 2 loại nhân viên:

- Lập trình viên
- Kiểm chứng viên

Chương trình được xây dựng theo hướng:

- **kế thừa**
- **đa hình**
- **dùng `dynamic_cast` để xử lý riêng từng loại nhân viên khi cần**

Các chức năng chính của bài:
- nhập danh sách nhân viên
- xuất danh sách nhân viên
- xuất nhân viên có lương thấp hơn mức lương trung bình
- tìm nhân viên có lương cao nhất
- tìm nhân viên có lương thấp nhất
- tìm lập trình viên có lương cao nhất
- tìm kiểm chứng viên có lương thấp nhất

---

## 2. Cấu trúc lớp

### Lớp cha: `NhanVien`

Lớp `NhanVien` chứa các thông tin chung:

- mã nhân viên
- họ tên
- tuổi
- số điện thoại
- email
- lương cơ bản

Các hàm chung:
- `nhap()`
- `xuat()`
- `tinhLuong()`

Trong đó:
- `nhap()` và `xuat()` là phần dùng chung
- `tinhLuong()` là hàm thuần ảo để từng lớp con tự định nghĩa cách tính lương

### Lớp con: `LapTrinhVien`

Thông tin riêng:
- số giờ overtime

Công thức lương:
`lương = lương cơ bản + số giờ overtime * 200000`

### Lớp con: `KiemChungVien`

Thông tin riêng:
- số lỗi phát hiện

Công thức lương:
`lương = lương cơ bản + số lỗi * 50000`

---

## 3. Kế thừa trong bài

Bài này có kế thừa vì:

```cpp
class LapTrinhVien : public NhanVien
class KiemChungVien : public NhanVien
```
### Input: 
```text
2
2
LTV01
Nguyen Van A
25
0901111111
a@gmail.com
5000000
20
LTV02
Tran Thi B
27
0902222222
b@gmail.com
4500000
10
KCV01
Le Van C
24
0903333333
c@gmail.com
4000000
80
KCV02
Pham Thi D
26
0904444444
d@gmail.com
4200000
30
```
### Output:
```text

-----Danh sach nhan vien-----
Ma nhan vien: LTV01
Ho va ten: Nguyen Van A
Tuoi: 25
So dien thoai: 0901111111
Email: a@gmail.com
Luong co ban: 5e+06
So gio lam: 20
Tong luong: 9e+06

Ma nhan vien: LTV02
Ho va ten: Tran Thi B
Tuoi: 27
So dien thoai: 0902222222
Email: b@gmail.com
Luong co ban: 4.5e+06
So gio lam: 10
Tong luong: 6.5e+06

Ma nhan vien: KCV01
Ho va ten: Le Van C
Tuoi: 24
So dien thoai: 0903333333
Email: c@gmail.com
Luong co ban: 4e+06
So loi: 80
Tong luong: 8e+06

Ma nhan vien: KCV02
Ho va ten: Pham Thi D
Tuoi: 26
So dien thoai: 0904444444
Email: d@gmail.com
Luong co ban: 4.2e+06
So loi: 30
Tong luong: 5.7e+06


Danh sach nhan vien luong duoi tb---
Ma nhan vien: LTV02
Ho va ten: Tran Thi B
Tuoi: 27
So dien thoai: 0902222222
Email: b@gmail.com
Luong co ban: 4.5e+06
So gio lam: 10
Tong luong: 6.5e+06

Ma nhan vien: KCV02
Ho va ten: Pham Thi D
Tuoi: 26
So dien thoai: 0904444444
Email: d@gmail.com
Luong co ban: 4.2e+06
So loi: 30
Tong luong: 5.7e+06


---Lap trinh vien co luong cao nhat---
Ma nhan vien: LTV01
Ho va ten: Nguyen Van A
Tuoi: 25
So dien thoai: 0901111111
Email: a@gmail.com
Luong co ban: 5e+06
So gio lam: 20
Tong luong: 9e+06

---Kiem chung vien co luong thap nhat---
Ma nhan vien: KCV02
Ho va ten: Pham Thi D
Tuoi: 26
So dien thoai: 0904444444
Email: d@gmail.com
Luong co ban: 4.2e+06
So loi: 30
Tong luong: 5.7e+06

---Nhan vien co luong cao nhat---
Ma nhan vien: LTV01
Ho va ten: Nguyen Van A
Tuoi: 25
So dien thoai: 0901111111
Email: a@gmail.com
Luong co ban: 5e+06
So gio lam: 20
Tong luong: 9e+06

---Nhan vien co luong thap nhat---
Ma nhan vien: KCV02
Ho va ten: Pham Thi D
Tuoi: 26
So dien thoai: 0904444444
Email: d@gmail.com
Luong co ban: 4.2e+06
So loi: 30
Tong luong: 5.7e+06
