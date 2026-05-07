# Quản lý nhân viên - Kế thừa trong C++

## 1. Giới thiệu

Chương trình này mô phỏng việc quản lý và tính lương cho nhân viên trong công ty.

Bài làm được xây dựng bằng ngôn ngữ C++ và áp dụng kiến thức lập trình hướng đối tượng, đặc biệt là **kế thừa**.

Trong chương trình có 2 loại nhân viên:

- Nhân viên sản xuất
- Nhân viên văn phòng

Mỗi loại nhân viên có cách nhập thông tin, xuất thông tin và tính lương riêng.

---

## 2. Mục tiêu bài làm

Chương trình thực hiện các chức năng chính sau:

- Nhập danh sách nhân viên sản xuất
- Nhập danh sách nhân viên văn phòng
- Xuất thông tin từng nhân viên
- Tính lương cho từng nhân viên
- Tính tổng lương công ty phải trả cho toàn bộ nhân viên

---

## 3. Cấu trúc class

### 3.1. Class `NhanVien`

Đây là class cha, lưu các thông tin chung của nhân viên.

Thuộc tính:

- `hoTen`: họ và tên nhân viên
- `ngaySinh`: ngày sinh của nhân viên

Phương thức:

- `nhap()`: nhập thông tin chung của nhân viên
- `xuat()`: xuất thông tin chung của nhân viên

Class `NhanVien` là class cơ sở để các class nhân viên cụ thể kế thừa lại.

---

### 3.2. Class `NhanVienSanXuat`

Class `NhanVienSanXuat` kế thừa từ class `NhanVien`.

Thuộc tính riêng:

- `luongCoBan`: lương cơ bản
- `soSanPham`: số sản phẩm làm được

Phương thức:

- `nhap()`: nhập thông tin nhân viên sản xuất
- `xuat()`: xuất thông tin nhân viên sản xuất
- `tinhLuong()`: tính lương nhân viên sản xuất

Công thức tính lương:

```cpp
luong = luongCoBan + 5000 * soSanPham;
```