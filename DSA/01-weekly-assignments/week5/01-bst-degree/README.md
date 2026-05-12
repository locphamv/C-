# Độ Lớn Nhất của Cây Nhị Phân Tìm Kiếm

## Mô tả
Tìm degree lớn nhất của các nút trong một Binary Search Tree (BST). Degree của một nút là số lượng con trực tiếp của nó.

## Định dạng Input
- Dòng 1: Số nguyên `n` - số lượng phần tử (1 ≤ n ≤ 10⁵)
- Dòng 2: `n` số nguyên cách nhau bởi khoảng trắng (các giá trị khác nhau, |giá trị| ≤ 10⁹)

## Định dạng Output
- In ra một số nguyên duy nhất là degree lớn nhất trong cây

## Ví dụ

### Input
```
5
10 5 15 3 7
```

### Output
```
2
```

## Ghi chú
- Degree của một nút: 0 nếu không có con, 1 nếu có 1 con, 2 nếu có 2 con
- Cây được xây dựng theo quy tắc BST (phần tử nhỏ hơn vào trái, lớn hơn vào phải)
