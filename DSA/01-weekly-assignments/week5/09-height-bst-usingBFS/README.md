# Tính Chiều Cao BST Bằng Đệ Quy

## Mô tả bài toán
Tính chiều cao của cây nhị phân tìm kiếm sử dụng phương pháp đệ quy. Chiều cao là độ dài của đường dẫn dài nhất từ gốc đến lá.

## Định dạng Input
- Dòng 1: Số nguyên `n` (số lượng nút trong cây)
- Dòng 2: `n` số nguyên (giá trị các nút, được thêm vào cây theo thứ tự)

## Định dạng Output
In chiều cao của cây.

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
- Chiều cao được tính bằng công thức: height(node) = 1 + max(height(left), height(right))
- Cây rỗng có chiều cao -1, cây chỉ có gốc có chiều cao 0
- Sử dụng đệ quy (DFS) để tính chiều cao
