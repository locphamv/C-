# Đếm Số Nút Lá trong Cây Nhị Phân Tìm Kiếm

## Mô tả
Đếm số lượng nút lá trong một Binary Search Tree (BST). Nút lá là nút không có con trái và con phải.

## Định dạng Input
- Dòng 1: Số nguyên `n` - số lượng phần tử (1 ≤ n ≤ 10⁵)
- Dòng 2: `n` số nguyên cách nhau bởi khoảng trắng (các giá trị khác nhau, |giá trị| ≤ 10⁹)

## Định dạng Output
- In ra một số nguyên duy nhất là số lượng nút lá trong cây

## Ví dụ

### Input
```
5
10 5 15 3 7
```

### Output
```
3
```

## Ghi chú
- Nút lá: nút không có con trái và con phải (cả left và right đều nullptr)
- Cây được xây dựng theo quy tắc BST (phần tử nhỏ hơn vào trái, lớn hơn vào phải)
- Nếu cây chỉ có 1 nút, nút đó được coi là nút lá
