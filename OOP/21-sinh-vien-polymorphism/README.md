# Quản lý Sinh Viên với Kế thừa và Đa hình
**Student Management with Inheritance and Polymorphism**

---

## 1. Giới thiệu

Bài này mô phỏng việc quản lý 2 loại sinh viên:
- Sinh viên Đại học
- Sinh viên Cao đẳng

### Công nghệ áp dụng

| Công nghệ | Mục đích |
|-----------|---------|
| **Kế thừa** | Chia sẻ thuộc tính và hành vi chung |
| **Đa hình** | Xử lý các loại sinh viên khác nhau thông qua interface chung |
| **Trừu tượng** | Định nghĩa các hành vi bắt buộc cho lớp con |

### Chức năng chính

- ✓ Nhập danh sách sinh viên đại học và cao đẳng
- ✓ Xuất danh sách sinh viên
- ✓ Liệt kê sinh viên đủ điều kiện tốt nghiệp
- ✓ Liệt kê sinh viên không đủ điều kiện tốt nghiệp
- ✓ Tìm sinh viên đại học có điểm trung bình cao nhất
- ✓ Tìm sinh viên cao đẳng có điểm trung bình cao nhất
- ✓ Đếm số sinh viên không đủ điều kiện tốt nghiệp theo loại

---

## 2. Thiết kế Lớp

### Lớp Cha: `SinhVien`

**Thuộc tính chung:**
- `maSinhVien` - mã sinh viên
- `hoTen` - họ tên
- `diaChi` - địa chỉ
- `tongTinChi` - tổng tín chỉ
- `diemTrungBinh` - điểm trung bình

**Phương thức:**
| Phương thức | Mô tả | Loại |
|-------------|-------|------|
| `nhap()` | Nhập thông tin chung | Cơ sở |
| `xuat()` | Xuất thông tin chung | Cơ sở |
| `duDieuKien()` | Kiểm tra điều kiện tốt nghiệp | Thuần ảo |

### Lớp Con

#### `SinhVienDaiHoc`

**Thuộc tính riêng:**
- `tenLuanVan` - tên luận văn
- `diemLuanVan` - điểm luận văn

**Điều kiện tốt nghiệp:**
- Tổng tín chỉ ≥ 145
- Điểm trung bình ≥ 5.0
- Điểm luận văn ≥ 5.0

#### `SinhVienCaoDang`

**Thuộc tính riêng:**
- `diemTotNghiep` - điểm tốt nghiệp

**Điều kiện tốt nghiệp:**
- Tổng tín chỉ ≥ 110
- Điểm trung bình ≥ 5.0
- Điểm tốt nghiệp ≥ 5.0

---

## 3. Sơ đồ Kế thừa

```
        SinhVien (Lớp cha - Base Class)
        ├─ nhap()
        ├─ xuat()
        └─ duDieuKien() [pure virtual]
             ↓
        ┌─────┴─────┐
        ↓           ↓
    SinhVienDaiHoc  SinhVienCaoDang
    (Đại học)      (Cao đẳng)
```

**Kế thừa công khai (public inheritance):**
```cpp
class SinhVienDaiHoc : public SinhVien { ... }
class SinhVienCaoDang : public SinhVien { ... }
```

---

## 4. Ví dụ Dữ liệu

**Format nhập:**
```
[Số lượng sinh viên đại học] [Số lượng sinh viên cao đẳng]
[Mã SV] [Họ tên] [Địa chỉ] [Tổng tín chỉ] [Điểm TB] [Tên luận văn] [Điểm luận văn]
...
[Mã SV] [Họ tên] [Địa chỉ] [Tổng tín chỉ] [Điểm TB] [Điểm tốt nghiệp]
...
```
## Input mẫu

```text
2
2
DH01
Nguyen Van A
Ho Chi Minh
150
7.8
He thong thong tin
8.5
DH02
Tran Thi B
Da Nang
140
6.2
Tri tue nhan tao
4.5
CD01
Le Van C
Can Tho
115
6.8
7.0
CD02
Pham Thi D
Ha Noi
100
5.5
4.0
