# Đếm Số Nút Ở Tầng K

## Mô tả bài toán
Đếm số lượng nút có ở tầng thứ k trong cây nhị phân tìm kiếm (coi gốc là tầng 0).

## Định dạng Input
- Dòng 1: Hai số nguyên `n` và `k` (số lượng nút và tầng cần đếm)
- Dòng 2: `n` số nguyên (giá trị các nút, được thêm vào cây theo thứ tự)

## Định dạng Output
In số lượng nút ở tầng thứ k.

## Ví dụ
**Input:**
```
5 1
50 30 70 20 40
```

**Output:**
```
2
```

## Ghi chú
- Cây được xây dựng từ các giá trị đầu vào theo quy tắc Binary Search Tree (BST)
- Tầng 0 là gốc của cây
- Sử dụng duyệt cây theo cấp (BFS) để đếm nút ở tầng k
- Nếu tầng k không tồn tại, kết quả là 0
