

```markdown
# Quản lý nhân viên với Kế thừa và Đa hình
## Employee Management with Inheritance and Polymorphism

## 1. Giới thiệu

Bài này mô phỏng việc quản lý 2 loại nhân viên trong công ty:
- Nhân viên sản xuất
- Nhân viên văn phòng

**Yêu cầu của bài:**
- Nhập danh sách nhân viên sản xuất và nhân viên văn phòng
- Tính lương cho từng nhân viên
- Xuất danh sách nhân viên
- Tính tổng lương công ty phải trả
- Tìm nhân viên sản xuất có lương thấp nhất
- Tìm nhân viên văn phòng lớn tuổi nhất

Bài được xây dựng theo hướng **kế thừa** và **đa hình**.

---

## 2. Ý tưởng thiết kế lớp

### Lớp cha: `NhanVien`

Lớp này chứa các thông tin chung:
- Họ tên
- Ngày sinh

Và các hàm chung:
- `nhap()` và `xuat()`: xử lý thông tin cơ bản
- `tinhLuong()`: hàm thuần ảo để mỗi lớp con tự định nghĩa cách tính riêng

### Lớp con

**`NhanVienSanXuat`**
- Thông tin riêng: lương cơ bản, số sản phẩm
- Công thức lương: `lương = lương cơ bản + số sản phẩm × 5000`

**`NhanVienVanPhong`**
- Thông tin riêng: số ngày làm việc
- Công thức lương: `lương = số ngày làm việc × 100000`

---

## 3. Kế thừa và Đa hình trong bài

### Kế thừa

Bài này sử dụng kế thừa để thiết lập quan hệ:

```cpp
class NhanVienSanXuat : public NhanVien {};
class NhanVienVanPhong : public NhanVien {};
```

Nhờ kế thừa:
- Lớp con dùng lại được thông tin chung của lớp cha
- Lớp con có thể gọi lại `NhanVien::nhap()` và `NhanVien::xuat()` giúp tránh lặp code

### Đa hình

Chương trình quản lý chung các nhân viên bằng một danh sách:

```cpp
vector<NhanVien*> ds;
```

Sau đó đưa vào cùng một danh sách cả `NhanVienSanXuat` và `NhanVienVanPhong`, rồi gọi chung:

```cpp
ds[i]->xuat();
ds[i]->tinhLuong();
```

Nhờ từ khóa `virtual` ở lớp cha, chương trình sẽ tự gọi đúng hàm của lớp con tương ứng tại thời điểm chạy.

---

## 4. Vì sao dùng `dynamic_cast`?

Trong bài này có 2 yêu cầu riêng biệt không thể xử lý chung:
1. Tìm nhân viên sản xuất có lương thấp nhất
2. Tìm nhân viên văn phòng lớn tuổi nhất

Trong khi danh sách lại lưu chung dưới dạng `vector<NhanVien*> ds;`, nên khi duyệt từng phần tử, cần kiểm tra object thật sự đang trỏ tới là loại nào. Ví dụ:

```cpp
NhanVienSanXuat* sx = dynamic_cast<NhanVienSanXuat*>(ds[i]);
```

- Nếu đúng là nhân viên sản xuất thì `sx != nullptr`
- Nếu không đúng thì `sx == nullptr`

`dynamic_cast` giúp ép kiểu an toàn từ con trỏ lớp cha sang con trỏ lớp con để xử lý các thuộc tính/nghiệp vụ riêng.

---

## 5. Input mẫu và Kết quả mong đợi

**Input mẫu:**

```text
2          // Số lượng NV Sản xuất
2          // Số lượng NV Văn phòng
Nguyen Van A
15/03/1998
5000000
100
Tran Thi B
20/11/1995
4500000
50
Le Van C
01/01/1990
26
Pham Thi D
12/08/1988
24

```

**Kết quả mong đợi:**

```text
Nhân viên sản xuất có lương thấp nhất: Tran Thi B
Nhân viên văn phòng lớn tuổi nhất: Pham Thi D
Tổng lương công ty phải trả: 15,250,000

```

---

## 6. Những khó khăn đã gặp trong quá trình làm

Trong lúc làm bài này, mình đã gặp khá nhiều chỗ dễ nhầm:

**1. Nhầm giữa kế thừa và đa hình:**
Ban đầu mình nghĩ chỉ cần `class NhanVienSanXuat : public NhanVien` là đã đủ cả kế thừa và đa hình. Sau khi làm kỹ hơn mới hiểu như vậy mới chỉ là kế thừa. Muốn thể hiện đa hình thì phải gọi qua con trỏ hoặc tham chiếu lớp cha (ví dụ `NhanVien*`).

**2. Nhầm giữa `virtual` và `= 0`:**
Mình đã phải phân biệt lại:

* `virtual` dùng để hỗ trợ đa hình.
* `virtual ... = 0` là hàm thuần ảo, dùng cho trừu tượng. Tức là có `virtual` chưa chắc đã là trừu tượng, nhưng có `= 0` thì lớp cha sẽ trở thành lớp trừu tượng (không thể tạo object trực tiếp).

**3. Nhầm rằng mọi hàm đều phải `virtual`:**
Lúc đầu rất dễ nghĩ đã dùng đa hình thì hàm nào cũng phải `virtual`. Sau đó hiểu ra chỉ những hàm nào cần gọi qua lớp cha mà vẫn chạy đúng hàm lớp con thì mới nên `virtual`, các hàm getter/setter thông thường không nhất thiết phải dùng.

**4. Băn khoăn có nên để `luong` thành thuộc tính của lớp cha không:**
Ban đầu mình nghĩ `luong` cũng là một thuộc tính. Nhưng sau đó hiểu rằng trong đề này lương không phải dữ liệu nhập sẵn mà là giá trị tính ra từ công thức. Vì vậy hợp lý hơn khi dùng hàm `double tinhLuong() const;` thay vì lưu sẵn biến `luong`.

**5. Khó hiểu chỗ `dynamic_cast`:**
Đây là phần mình thấy lạ nhất lúc đầu. Vì danh sách đã lưu chung bằng `NhanVien*` rồi, tại sao vẫn phải tách ra? Sau đó mới hiểu: đa hình dùng để xử lý chung, còn `dynamic_cast` dùng khi cần quay lại tách riêng từng loại trong danh sách chung để giải quyết yêu cầu đặc thù.

**6. Nhầm giữa con trỏ, mảng và vector:**
Trong quá trình học rất dễ nhầm lúc nào dùng object bình thường, lúc nào dùng con trỏ, tại sao dùng `vector<Cha*>`. Bài này giúp mình hiểu đa hình chuẩn thường dùng cho từng object, và nếu có nhiều object khác loại thì nên quản lý bằng `vector<NhanVien*>` vì nó dễ dàng quản lý và `delete` từng phần tử hơn là mảng động `Base* p = new Derived[10]`.

---

## 7. Những gì mình học được sau bài này

Sau bài này, mình rút ra được các khái niệm cốt lõi:

* **Kế thừa:** Giúp lớp con dùng lại phần chung của lớp cha. Lớp con có thể gọi lại hàm lớp cha rồi viết tiếp phần riêng của mình.
* **Đa hình:** Muốn dùng đa hình runtime thì thường gọi qua con trỏ hoặc tham chiếu lớp cha. Từ khóa `virtual` giúp chương trình tự động chọn đúng hàm của object thật sự lúc chạy.
* **Trừu tượng:** Cú pháp `virtual ... = 0` làm lớp cha thành lớp trừu tượng. Không tạo object trực tiếp từ lớp cha được và bắt buộc lớp con phải cài đặt lại hàm đó.
* **Override:** Giúp compiler xác nhận lớp con đang ghi đè đúng hàm của lớp cha. Không bắt buộc nhưng rất nên dùng để tránh sai sót chính tả hoặc sai tham số.
* **Dynamic cast:** Dùng để kiểm tra object thật sự thuộc lớp con nào. Rất hữu ích khi vừa muốn quản lý chung trong một cấu trúc dữ liệu, vừa muốn lọc riêng từng loại để xử lý.

---

## 8. Kết luận

Đây là một bài thực hành rất tốt để hiểu rõ sự khác nhau và mối liên hệ giữa **kế thừa**, **đa hình**, **trừu tượng**, **override** và **dynamic_cast**.

Sau bài này, mình hiểu rõ hơn nguyên lý: kế thừa giúp dùng lại phần chung, đa hình giúp quản lý chung các object khác loại, và `dynamic_cast` giúp quay lại xử lý riêng từng loại khi cần thiết.

```</NhanVienSanXuat*></NhanVien*>

```