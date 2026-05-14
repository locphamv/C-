# Farm Animal Management with Inheritance and Polymorphism
# Quản lý gia súc với Kế thừa và Đa hình

## 1. Giới thiệu

Bài này mô phỏng việc quản lý một nông trại có 3 loại gia súc:

- Bò
- Cừu
- Dê

Mỗi loại gia súc có:
- tiếng kêu riêng
- khả năng sinh con
- khả năng cho sữa

Bài làm được xây dựng theo hướng:

- **kế thừa**
- **đa hình**
- **dùng danh sách chung để quản lý các loại gia súc khác nhau**

Các chức năng chính:
- nhập số lượng ban đầu của từng loại gia súc
- cho tất cả gia súc phát ra tiếng kêu khi đói
- mô phỏng một lứa sinh
- mô phỏng một lượt cho sữa
- thống kê số lượng gia súc sau khi sinh
- tính tổng số lít sữa thu được

---

## 2. Thiết kế lớp

### Lớp cha: `GiaSuc`

Lớp `GiaSuc` chứa thông tin chung:
- số lượng

Các hàm chung:
- `setSoLuong()`
- `getSoLuong()`
- `tiengKeu()`
- `sinhCon()`
- `choSua()`

Trong đó:
- `tiengKeu()`, `sinhCon()`, `choSua()` là các hàm ảo thuần túy để từng lớp con tự định nghĩa

### Các lớp con

#### `Bo`
- tiếng kêu: `"Bo... bo..."`
- cho sữa ngẫu nhiên từ `0` đến `20` lít mỗi con
- số con sinh ra ngẫu nhiên

#### `Cuu`
- tiếng kêu: `"Be... be..."`
- cho sữa ngẫu nhiên từ `0` đến `5` lít mỗi con
- số con sinh ra ngẫu nhiên

#### `De`
- tiếng kêu: `"De... de..."`
- cho sữa ngẫu nhiên từ `0` đến `10` lít mỗi con
- số con sinh ra ngẫu nhiên

### Lớp quản lý: `DSGiaSuc`

Lớp này dùng để quản lý danh sách các loại gia súc bằng:

```cpp id="95xfxk"
vector<GiaSuc*> ds;