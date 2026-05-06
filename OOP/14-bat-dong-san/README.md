# VAKALAND - Real Estate Transaction Management  
# VAKALAND - Quản lý giao dịch bất động sản

## 1. Introduction | Giới thiệu

**English:**  
This program simulates the management of real estate transactions for the company **VAKALAND**.  
The project is implemented using **Object-Oriented Programming (OOP)**, especially **inheritance**, to manage 3 different transaction types:

- Land transaction
- House transaction
- Apartment transaction

**Tiếng Việt:**  
Chương trình mô phỏng việc quản lý các giao dịch bất động sản của công ty **VAKALAND**.  
Bài làm được xây dựng theo hướng **lập trình hướng đối tượng (OOP)**, đặc biệt là **tính kế thừa**, để quản lý 3 loại giao dịch:

- Giao dịch Đất
- Giao dịch Nhà phố
- Giao dịch Căn hộ chung cư

---

## 2. Class Structure | Cấu trúc lớp

### Base class | Lớp cơ sở
- `GiaoDich`
  - Transaction ID | Mã giao dịch
  - Transaction date | Ngày giao dịch
  - Unit price | Đơn giá
  - Area | Diện tích

### Derived classes | Các lớp kế thừa
- `GiaoDichDat`
  - adds `loaiDat` | thêm `loaiDat`
- `GiaoDichNha`
  - adds `loaiNha`, `diaChi` | thêm `loaiNha`, `diaChi`
- `GiaoDichCanHo`
  - adds `maCanHo`, `viTriTang` | thêm `maCanHo`, `viTriTang`

### Inheritance diagram | Sơ đồ kế thừa

```
GiaoDich
├── GiaoDichDat
├── GiaoDichNha
└── GiaoDichCanHo
```

---

## 3. Example | Ví dụ

### Input
```
2
2
3
D01
15/12/2024
1000
50
A
D02
20/11/2024
800
40
B
N01
05/12/2024
2000
60
thuong
123 Le Loi Quan 1
N02
18/10/2024
1500
70
thuong
45 Nguyen Trai Quan 5
C01
01/12/2024
1200
55
CH101
1
C02
22/12/2024
1000
65
CH1502
15
C03
10/09/2024
900
50
CH803
8
```

### Output

```
-----DA NHAP XONG CAC GIAO DICH----
Tong so giao dich dat: 2
Tong so giao dich nha: 2
Tong so giao dich can ho: 3


Trung binh thanh tien cua giao dich can ho chung cu: 85000

----Giao dich nha co gia tri cao nhat----
Ma giao dich: N01
Ngay giao dich: 05/12/2024
Don gia: 2000
Dien tich: 60
Loai nha: thuong
Dia chi 123 Le Loi Quan 1
Thanh tien: 108000

---Danh sach cac giao dich vao thang 12/2024---
STT: 1
Ma giao dich: D01
Ngay giao dich: 15/12/2024
Don gia: 1000
Dien tich: 50
Loai dat: A
Thanh tien: 75000

STT: 2
Ma giao dich: N01
Ngay giao dich: 05/12/2024
Don gia: 2000
Dien tich: 60
Loai nha: thuong
Dia chi 123 Le Loi Quan 1
Thanh tien: 108000

STT: 3
Ma giao dich: C01
Ngay giao dich: 01/12/2024
Don gia: 1200
Dien tich: 55
Ma can ho: CH101
Vi tri tang: 1
Thanh tien: 132000

STT: 4
Ma giao dich: C02
Ngay giao dich: 22/12/2024
Don gia: 1000
Dien tich: 65
Ma can ho: CH1502
Vi tri tang: 15
Thanh tien: 78000
```