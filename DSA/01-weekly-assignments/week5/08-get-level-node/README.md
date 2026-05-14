# Tính Chiều Cao Của Cây

## Mô tả bài toán
Tính chiều cao (height) của cây nhị phân tìm kiếm. Chiều cao là số tầng của cây, tính từ gốc đến lá xa nhất.

## Định dạng Input
- Dòng 1: Số nguyên `n` (số lượng nút trong cây)
- Dòng 2: `n` số nguyên (giá trị các nút, được thêm vào cây theo thứ tự)

## Định dạng Output
In chiều cao của cây (tính từ 0 cho cây chỉ có gốc).

## Ví dụ
**Input:**
```
5
50 30 70 20 40
```

**Output:**
```
2
```

## Ghi chú
- Cây được xây dựng từ các giá trị đầu vào theo quy tắc Binary Search Tree (BST)
- Cây chỉ có gốc (1 nút) có chiều cao là 0
- Sử dụng duyệt cây theo cấp (BFS) để tính chiều cao
- Chiều cao = số tầng - 1
