# Duyệt Cây Post-order

## Mô tả
In ra các phần tử trong cây theo thứ tự post-order traversal. Post-order là thứ tự duyệt: trái → phải → gốc.

## Định dạng Input
- Dòng 1: Số nguyên `n` - số lượng phần tử (1 ≤ n ≤ 10⁵)
- Dòng 2: `n` số nguyên cách nhau bởi khoảng trắng (các giá trị khác nhau, |giá trị| ≤ 10⁹)

## Định dạng Output
- In ra các phần tử theo thứ tự post-order, cách nhau bởi dấu cách

## Ví dụ

### Input
```
5
10 5 15 3 7
```

### Output
```
3 7 5 15 10 
```

## Ghi chú
- Post-order traversal: duyệt con trái → con phải → nút hiện tại
- Cây được xây dựng theo quy tắc BST (phần tử nhỏ hơn vào trái, lớn hơn vào phải)
- Có dấu cách ở cuối output
