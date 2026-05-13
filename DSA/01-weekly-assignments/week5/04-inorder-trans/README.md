# Duyệt Cây Theo In-Order

## Mô tả bài toán
Duyệt cây nhị phân tìm kiếm theo thứ tự In-order (trái - gốc - phải) và in ra kết quả.

## Định dạng Input
- Dòng 1: Số nguyên `n` (số lượng nút trong cây)
- Dòng 2: `n` số nguyên (giá trị các nút, được thêm vào cây theo thứ tự)

## Định dạng Output
In các giá trị của cây theo thứ tự in-order, cách nhau bởi dấu cách.

## Ví dụ
**Input:**
```
5
50 30 70 20 40
```

**Output:**
```
20 30 40 50 70
```

## Ghi chú
- Cây được xây dựng từ các giá trị đầu vào theo quy tắc Binary Search Tree (BST)
- In-order traversal của BST cho kết quả là dãy các giá trị được sắp xếp tăng dần
- In-order: duyệt cây con trái, sau đó duyệt gốc, cuối cùng duyệt cây con phải
