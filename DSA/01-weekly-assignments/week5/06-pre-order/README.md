# Duyệt Cây Theo Pre-Order

## Mô tả bài toán
Duyệt cây nhị phân tìm kiếm theo thứ tự Pre-order (gốc - trái - phải) và in ra kết quả.

## Định dạng Input
- Dòng 1: Số nguyên `n` (số lượng nút trong cây)
- Dòng 2: `n` số nguyên (giá trị các nút, được thêm vào cây theo thứ tự)

## Định dạng Output
In các giá trị của cây theo thứ tự pre-order, cách nhau bởi dấu cách.

## Ví dụ
**Input:**
```
5
50 30 70 20 40
```

**Output:**
```
50 30 20 40 70
```

## Ghi chú
- Cây được xây dựng từ các giá trị đầu vào theo quy tắc Binary Search Tree (BST)
- Pre-order traversal: duyệt gốc trước, sau đó duyệt cây con trái, cuối cùng duyệt cây con phải
