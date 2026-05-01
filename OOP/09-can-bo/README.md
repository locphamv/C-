# Hệ Thống Quản Lý Cán Bộ

## Mô Tả Dự Án
Ứng dụng quản lý cán bộ (nhân viên) cho một tổ chức/đơn vị. Hệ thống hỗ trợ quản lý thông tin các loại cán bộ khác nhau như giảng viên, nhân viên hành chính và tính toán lương dựa trên các hệ số khác nhau.

## Chức Năng Chính
- **Nhập danh sách cán bộ** - Thêm thông tin cán bộ từ bàn phím
- **Xuất danh sách** - Hiển thị danh sách cán bộ trên console
- **Lưu/Đọc file** - Lưu danh sách vào file `DanhSach.txt` hoặc đọc từ file
- **Sắp xếp** - Sắp xếp danh sách theo tiền lương
- **Tìm kiếm** - Tìm cán bộ theo mã số hoặc họ tên
- **Sửa thông tin** - Cập nhật thông tin cán bộ
- **Tính lương** - Tính tổng tiền lương phải trả

## Các Loại Cán Bộ
- **Giảng viên** - Tính lương dựa trên: lương cơ bản × hệ số lương × (1 + số năm công tác × 5%)
- **Nhân viên hành chính** - Có cách tính lương riêng

## Ví Dụ Nhập Dữ Liệu

### Giảng Viên
```
Mã số: GV001
Họ tên: Trần Văn A
Hệ số lương: 2.5
Số năm công tác: 5
Chuyên ngành: Khoa Học Máy Tính
```

### Nhân Viên Hành Chính
```
Mã số: NV001
Họ tên: Nguyễn Thị B
Hệ số lương: 1.8
Phòng ban: Phòng Nhân Sự
```

## Cấu Trúc Lớp
- `CanBo` - Lớp cơ sở (abstract)
- `GiangVien` - Kế thừa từ CanBo
- `NhanVienHanhChinh` - Kế thừa từ CanBo
- `QuanLyCanBo` - Quản lý danh sách cán bộ

## Biên Dịch và Chạy
```bash
clang++ -std=c++17 -stdlib=libc++ -g *.cpp -o main
./main
```
