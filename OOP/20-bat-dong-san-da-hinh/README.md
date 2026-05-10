# Real Estate Transaction Management with Inheritance and Polymorphism
# Quản lý giao dịch bất động sản với Kế thừa và Đa hình

## 1. Giới thiệu

Bài này mô phỏng việc quản lý các giao dịch bất động sản của công ty **VAKALAND**.

Có 3 loại giao dịch:
- Giao dịch đất
- Giao dịch nhà phố
- Giao dịch căn hộ chung cư

Bài làm được xây dựng theo hướng:
- **kế thừa**
- **đa hình**

Mục tiêu của bài:
- nhập danh sách giao dịch
- tính thành tiền cho từng loại giao dịch
- tính trung bình thành tiền căn hộ
- tìm giao dịch nhà có giá trị cao nhất
- lọc các giao dịch trong tháng 12/2024

---

## 2. Ý tưởng thiết kế lớp

### Lớp cha: `GiaoDich`
Lớp này chứa các thông tin chung:
- mã giao dịch
- ngày giao dịch
- đơn giá
- diện tích

Các hàm chung:
- `nhap()`
- `xuat()`
- `thanhTien()`

Trong đó:
- `nhap()` và `xuat()` là phần dùng chung
- `thanhTien()` là hàm thuần ảo, vì mỗi loại giao dịch có công thức khác nhau

### Các lớp con

#### `GiaoDichDat`
Thông tin riêng:
- loại đất: A, B, C

Công thức thành tiền:
- loại A: `diện tích * đơn giá * 1.5`
- loại B, C: `diện tích * đơn giá`

#### `GiaoDichNha`
Thông tin riêng:
- loại nhà: cao cấp / thường
- địa chỉ

Công thức thành tiền:
- cao cấp: `diện tích * đơn giá`
- thường: `diện tích * đơn giá * 0.9`

#### `GiaoDichCanHo`
Thông tin riêng:
- mã căn hộ
- vị trí tầng

Công thức thành tiền:
- tầng 1: `diện tích * đơn giá * 2`
- tầng >= 15: `diện tích * đơn giá * 1.2`
- các tầng còn lại: `diện tích * đơn giá`

---

## 3. Kế thừa trong bài

Bài này có kế thừa vì:

```cpp
class GiaoDichDat : public GiaoDich
class GiaoDichNha : public GiaoDich
class GiaoDichCanHo : public GiaoDich