# XYZ - Quản lý khách hàng mua hàng bằng Kế thừa và Đa hình

## 1. Giới thiệu

Bài này mô phỏng việc công ty **XYZ** quản lý 3 loại khách hàng khi mua hàng:

- Loại A: Khách hàng bình thường
- Loại B: Khách hàng thân thiết
- Loại C: Khách hàng đặc biệt

Chương trình áp dụng:

- **kế thừa**
- **đa hình**
- **đọc dữ liệu từ file**
- **ghi kết quả ra file**

Các chức năng chính:
- đọc danh sách khách hàng từ file `XYZ.INP`
- tính số tiền mỗi khách hàng phải trả
- tính tổng số tiền công ty thu được
- xuất kết quả ra file `XYZ.OUT`

---

## 2. Cấu trúc lớp

### Lớp cha: `KhachHang`

Lớp `KhachHang` chứa các thông tin chung:

- tên khách hàng
- số lượng hàng
- đơn giá hàng

Các hàm chung:
- `nhap(istream&)`
- `tinhTien()`
- `xuat(ostream&)`

Trong đó:
- `nhap()` đọc dữ liệu từ file
- `tinhTien()` là hàm thuần ảo vì mỗi loại khách hàng có công thức tính tiền khác nhau
- `xuat()` xuất tên khách hàng và số tiền phải trả

### Các lớp con

#### `KhachHangA`
Khách hàng bình thường

Công thức:
- tiền hàng = `số lượng * đơn giá`
- VAT = `10%`
- số tiền phải trả = `tiền hàng + VAT`

#### `KhachHangB`
Khách hàng thân thiết

Thông tin riêng:
- số năm thân thiết

Công thức:
- phần trăm khuyến mãi = `min(số năm thân thiết * 5%, 50%)`
- tiền sau giảm giá = `tiền hàng * (1 - phần trăm khuyến mãi)`
- VAT = `10%` trên số tiền sau giảm
- số tiền phải trả = `tiền sau giảm + VAT`

#### `KhachHangC`
Khách hàng đặc biệt

Công thức:
- tiền hàng chỉ tính `50%`
- VAT = `10%`
- số tiền phải trả = `(số lượng * đơn giá * 50%) + VAT`

---

## 3. Kế thừa trong bài

Bài này có kế thừa vì:

```cpp
class KhachHangA : public KhachHang
class KhachHangB : public KhachHang
class KhachHangC : public KhachHang