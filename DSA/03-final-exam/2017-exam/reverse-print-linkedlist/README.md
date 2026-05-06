# Reverse Print Singly Linked List

Bài toán: In các phần tử trong danh sách liên kết đơn theo thứ tự từ cuối về đầu, 
không dùng mảng phụ hoặc danh sách phụ.

## Ý tưởng chính

Vì danh sách liên kết đơn chỉ đi được từ `Head` sang `Next`, ta dùng đệ quy:

1. Đi tới node cuối cùng trước.
2. Khi đệ quy quay lui thì mới in node hiện tại.
3. Kết quả là danh sách được in ngược.

## Hai hàm quan trọng

```cpp
void RPrintNode(Node *p)
{
    if (p == NULL)
        return;

    RPrintNode(p->Next);      // đi tới node phía sau trước
    cout << p->info << " ";   // in node hiện tại khi quay lui
}

void RPrint(List Ls)
{
    RPrintNode(Ls.Head);
}
```

## Ví dụ

Danh sách ban đầu:

```text
1 -> 2 -> 3 -> 4 -> 5
```

Kết quả khi gọi `RPrint`:

```text
5 4 3 2 1
```

## Độ phức tạp

- Thời gian: `O(n)`
- Bộ nhớ: `O(n)` do dùng ngăn xếp đệ quy
- Không dùng mảng phụ hoặc danh sách phụ