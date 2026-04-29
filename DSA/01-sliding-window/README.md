# Sliding Window Sum

This C++ program calculates the sum of every contiguous subarray of size `k` in an array.

## Input

The program reads:

```text
n k
a1 a2 a3 ... an
```

Where:

- `n` is the number of elements in the array
- `k` is the window size
- `a1 a2 ... an` are the array elements

## Output

The program prints the sum of each subarray of size `k`.

## Example Input and Output

### Input

```text
5 3
1 2 3 4 5
```

### Output

```text
6 9 12
```

## Explanation

For `k = 3`, the subarrays are:

```text
1 2 3 -> 6
2 3 4 -> 9
3 4 5 -> 12
```

## Complexity

- Time complexity: `O(n)`
- Space complexity: `O(n)`

