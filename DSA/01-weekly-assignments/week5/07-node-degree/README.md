# Tìm Bậc Của Nút Trong Cây

## Mô tả bài toán
Tìm bậc (degree) của một nút trong cây nhị phân tìm kiếm. Bậc của nút là số lượng nút con trực tiếp của nó.

## Định dạng Input
- Dòng 1: Số nguyên `n` (số lượng nút trong cây)
- Dòng 2: `n` số nguyên (giá trị các nút, được thêm vào cây theo thứ tự)
- Dòng 3: Số nguyên `x` (giá trị nút cần tìm bậc)

## Định dạng Output
In bậc của nút x:
- `0` nếu x là nút lá (không có con)
- `1` nếu x có một con
- `2` nếu x có hai con
- `-1` nếu x không tồn tại trong cây

## Ví dụ
**Input:**
```
5
50 30 70 20 40
50
```

**Output:**
```
2
```

## Ghi chú
- Cây được xây dựng từ các giá trị đầu vào theo quy tắc Binary Search Tree (BST)
- Bậc của một nút bằng số nút con của nó
- Nút lá có bậc 0, nút với một con có bậc 1, nút với hai con có bậc 2
