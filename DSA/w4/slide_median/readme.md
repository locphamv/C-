# Sliding Median

## Ý tưởng
- Dùng 2 multiset
- low = nửa nhỏ
- high = nửa lớn

## Invariant
- low giữ `(window_size + 1) / 2` phần tử
- mọi phần tử trong low <= mọi phần tử trong high

## Add
- nếu low rỗng hoặc `x <= max(low)` thì vào low
- ngược lại vào high
- sau đó rebalance

## Remove
- tìm trong low, không có thì tìm trong high
- xóa đúng 1 bản sao
- sau đó rebalance

## Rebalance
- low thừa -> chuyển `max(low)` sang high
- low thiếu -> chuyển `min(high)` sang low

## Median
- d lẻ: `max(low)`
- d chẵn: `(max(low) + min(high)) / 2`

## Main flow
- tạo cửa sổ đầu gồm d phần tử
- for `i` từ `d` đến `n-1`
  - check `a[i]`
  - remove `a[i-d]`
  - add `a[i]`