# Hash Table Collision Checker

## Problem Description

We are given a hash table that uses **separate chaining** to handle collisions. The program evaluates whether the collision ratio in the hash table is acceptable based on a predefined threshold.

The hash function is:

```cpp
h(key) = key % M
```

Where:
- `key` is the input key to be inserted
- `M` is the number of buckets in the hash table

## Solution Approach

The algorithm:
1. Initialize an array of `M` buckets, each with a count of 0
2. For each key, compute its hash value using `h(key) = key % M`
3. If a bucket already has elements (count > 0), increment the collision counter
4. Increment the bucket's count
5. Check if the collision ratio exceeds the threshold (33%)
6. Output "GOOD" if ratio ≤ 33%, otherwise "BAD"

The collision ratio is calculated as:
$$\text{ratio} = \frac{\text{collisions}}{n} \times 100$$

## Input Format

- First line: `n M`
  - `n`: number of keys to insert (1 ≤ n ≤ 100,000)
  - `M`: number of buckets (1 ≤ M ≤ 10,000)
- Next `n` lines: each contains a single integer key (1 ≤ key ≤ 1,000,000)

## Output Format

- `GOOD` if collision ratio ≤ 33%
- `BAD` if collision ratio > 33%

## Example

### Input
```
5 3
1
4
7
2
3
```

### Computation
- key=1: h(1)=1%3=1, bucket[1]=1, no collision
- key=4: h(4)=4%3=1, bucket[1]>0, collision! collisions=1, bucket[1]=2
- key=7: h(7)=7%3=1, bucket[1]>0, collision! collisions=2, bucket[1]=3
- key=2: h(2)=2%3=2, bucket[2]=1, no collision
- key=3: h(3)=3%3=0, bucket[0]=1, no collision

Collision ratio: 2/5 × 100 = 40% > 33% → **BAD**

### Output
```
BAD
```

## Compilation & Execution

### macOS/Linux (with clang++)
```bash
clang++ -std=c++17 -stdlib=libc++ main.cpp -o collision_ratio
./collision_ratio
```

### Generic (with g++)
```bash
g++ -std=c++17 main.cpp -o collision_ratio
./collision_ratio
```

## Complexity Analysis

- **Time Complexity**: O(n)
  - Single pass through all n keys
  - Each hash computation and bucket update: O(1)

- **Space Complexity**: O(M)
  - Storage for M buckets

## Algorithm Explanation

The separate chaining hash table stores elements in the same bucket as a chain. When a collision occurs (i.e., we try to insert a key into a bucket that already contains at least one element), we count it. This solution assumes a simple separate chaining implementation where we only track the count of elements in each bucket.