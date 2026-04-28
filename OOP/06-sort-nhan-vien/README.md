# Sort NhanVien (Sort Employees by Date of Birth) - OOP Project

## Description
A C++ project that manages and sorts employees by their date of birth. This project demonstrates OOP principles including operator overloading, static members, and custom comparison operators.

## Features
- **Multiple Employee Management**: Store multiple employee records
- **Automatic ID Assignment**: Uses static counter to assign unique employee IDs
- **Sorting by Date of Birth**: Sorts employees by birth year, month, then day
- **Operator Overloading**: Custom comparison operator for sorting
- **Formatted Output**: Displays employee IDs with leading zeros

## Class Structure

### NhanVien Class

#### Private Members
- `ten` (string): Employee Name
- `gioiTinh` (string): Gender
- `ngaySinh` (string): Date of Birth (DD/MM/YYYY format)
- `diaChi` (string): Address
- `maSoThue` (string): Tax Code
- `ngayKiHopDong` (string): Contract Date
- `ma` (int): Employee ID (auto-assigned)

#### Static Members
- `cnt` (int): Counter for generating unique employee IDs

#### Public Methods
- `NhanVien()`: Constructor - initializes all string members to empty
- `operator>>()`: Input operator - reads employee data and assigns ID
- `operator<<()`: Output operator - displays employee with formatted ID
- `operator<()`: Comparison operator - compares employees by birth date

## Sorting Logic
Employees are sorted by date of birth in ascending order:
1. **Year** - older employees first
2. **Month** - earlier months first (if same year)
3. **Day** - earlier days first (if same year and month)

## Input Format
First line: Number of employees (n)
For each employee:
1. **Employee Name** (string with spaces allowed)
2. **Gender** (single string)
3. **Date of Birth** (DD/MM/YYYY format)
4. **Address** (string with spaces allowed)
5. **Tax Code** (string)
6. **Contract Date** (string format)

### Example Input
```
2
Nguyen Van A
Nam
15/03/1990
123 Duong Bach Dang, Ha Noi
12345678901
01/01/2020
Tran Thi B
Nu
22/07/1988
456 Nguyen Hue, TP HCM
98765432101
15/06/2019
```

## Output Format
Employees are displayed sorted by date of birth, with ID formatted with leading zeros:
```
<ID (5 digits)> <Name> <Gender> <DateOfBirth> <Address> <TaxCode> <ContractDate>
```

### Example Output
```
00002 Tran Thi B   Nu 22/07/1988 456 Nguyen Hue, TP HCM 98765432101 15/06/2019
00001 Nguyen Van A   Nam 15/03/1990 123 Duong Bach Dang, Ha Noi 12345678901 01/01/2020
```

## Key Implementation Details
- **Static Counter**: `cnt` is a class variable that increments with each employee added
- **Date Format**: Uses DD/MM/YYYY format; parsing extracts year, month, and day
- **Stable Sort**: Maintains relative order of equal elements
- **Formatted ID Output**: IDs display with leading zeros (e.g., 00001, 00002)
- **Friend Functions**: Input/output operators have access to private members

## Execution Flow
1. Read the number of employees
2. Input employee data (IDs are auto-assigned sequentially)
3. Sort all employees by date of birth
4. Output sorted employee list with formatted IDs
