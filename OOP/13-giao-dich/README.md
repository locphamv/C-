# Gold and Currency Transaction Management

## Introduction

This is a simple C++ program used to manage gold transactions and currency transactions.

The project was created to practice Object-Oriented Programming concepts in C++, especially:

- Classes and objects
- Inheritance
- Method overriding
- `virtual` functions
- `override`
- Working with multiple `.h` and `.cpp` files
- Using `vector`

---

## Class Structure

### 1. `GiaoDich` Class

`GiaoDich` is the base class that stores common information of a transaction.

Common attributes:

- Transaction ID
- Transaction date
- Unit price
- Quantity

Main methods:

```cpp
virtual void nhap();
virtual void xuat();
virtual double tinhTien();

int getSoLuong();
double getDonGia();
```

This class is used as the parent class for more specific transaction types.

---

### 2. `GiaoDichVang` Class

`GiaoDichVang` inherits from `GiaoDich`.

Additional attribute:

- Type of gold

Formula for calculating the total amount:

```cpp
totalAmount = quantity * unitPrice;
```

Overridden methods:

```cpp
void nhap() override;
void xuat() override;
double tinhTien() override;
```

---

### 3. `GiaoDichTienTe` Class

`GiaoDichTienTe` inherits from `GiaoDich`.

Additional attributes:

- Exchange rate
- Currency type

Formula for calculating the total amount:

For Vietnamese currency:

```cpp
totalAmount = quantity * unitPrice;
```

For foreign currency:

```cpp
totalAmount = quantity * unitPrice * exchangeRate;
```

Overridden methods:

```cpp
void nhap() override;
void xuat() override;
double tinhTien() override;
```

---

## Project Structure

```txt
.
├── main.cpp
├── GiaoDich.h
├── GiaoDich.cpp
├── GiaoDichVang.h
├── GiaoDichVang.cpp
├── GiaoDichTienTe.h
├── GiaoDichTienTe.cpp
└── README.md
```

---

## Main Features

The program can:

1. Input a list of gold transactions.
2. Input a list of currency transactions.
3. Find the gold transaction with the highest total amount.
4. Find the Euro currency transaction with the lowest total amount.
5. Display currency transactions whose total amount is greater than 1 billion VND.

---

## Input Format

### Gold Transaction

Each gold transaction is entered in the following order:

```txt
Transaction ID
Transaction date
Unit price
Quantity
Gold type
```

### Currency Transaction

Each currency transaction is entered in the following order:

```txt
Transaction ID
Transaction date
Unit price
Quantity
Exchange rate
Currency type
```

---

## Sample Input

```txt
3
4
V001
01/05/2026
7000000
10
SJC
V002
02/05/2026
6800000
5
9999
V003
03/05/2026
7200000
20
PNJ
T001
01/05/2026
1
10000
25000
USD
T002
02/05/2026
1
30000
27000
Euro
T003
03/05/2026
1
1000
26000
Euro
T004
04/05/2026
1
50000
24000
USD
```

---

## Sample Output

```txt
The gold transaction with the highest total amount is:
Transaction ID: V003
Transaction date: 03/05/2026
Unit price: 7200000
Quantity: 20
Gold type: PNJ
Total amount: 144000000

The Euro currency transaction with the lowest total amount is:
Transaction ID: T003
Transaction date: 03/05/2026
Unit price: 1
Quantity: 1000
Exchange rate: 26000
Currency type: Euro
Total amount: 26000000

Currency transactions with total amount greater than 1 billion VND:
Transaction number 4:
Transaction ID: T004
Transaction date: 04/05/2026
Unit price: 1
Quantity: 50000
Exchange rate: 24000
Currency type: USD
Total amount: 1200000000
```

---

## Note

In `main.cpp`, this line can be used to prevent large numbers from being displayed in scientific notation:

```cpp
cout << fixed << setprecision(0);
```

For example, instead of displaying:

```txt
7.2e+06
```

the program will display:

```txt
7200000
```

Remember to include:

```cpp
#include <iomanip>
```

---

## How to Compile

Using `g++`:

```bash
g++ main.cpp GiaoDich.cpp GiaoDichVang.cpp GiaoDichTienTe.cpp -o main
```

Run the program:

```bash
./main
```

On Windows:

```bash
main.exe
```

---

## Learning Purpose

This project demonstrates how inheritance works in C++.

Example:

```cpp
class GiaoDichVang : public GiaoDich
```

and:

```cpp
class GiaoDichTienTe : public GiaoDich
```

By using inheritance, child classes can reuse common attributes and methods from the parent class, while also adding their own specific attributes and behaviors.