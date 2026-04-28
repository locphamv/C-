# NhanVien (Employee) - OOP Project

## Description
A C++ project demonstrating Object-Oriented Programming principles through an Employee management system. This project implements a `NhanVien` (Employee) class with operator overloading for input/output operations.

## Features
- **Employee Data Management**: Store and manage employee information
- **Operator Overloading**: Custom `>>` and `<<` operators for input/output
- **Data Encapsulation**: Private member variables with controlled access
- **Input Validation**: Structured input for employee data

## Class Structure

### NhanVien Class

#### Private Members
- `ma` (string): Employee ID
- `ten` (string): Employee Name
- `gioiTinh` (string): Gender
- `ngaySinh` (string): Date of Birth
- `diaChi` (string): Address
- `maSoThue` (string): Tax Code
- `ngayKiHopDong` (string): Contract Date

#### Public Methods
- `NhanVien()`: Constructor - initializes all member variables to empty strings
- `operator>>()`: Input operator - reads employee data from input stream
- `operator<<()`: Output operator - displays employee data to output stream


## Input Format
When running the program, provide employee information in the following order:
1. **Employee Name** (string with spaces allowed)
2. **Gender** (single string)
3. **Date of Birth** (string format)
4. **Address** (string with spaces allowed)
5. **Tax Code** (string)
6. **Contract Date** (string format)

### Example Input
```
Nguyen Van A
Nam
01/01/1990
123 Duong Bach Dang, Ha Noi
12345678901
01/01/2020
```

## Output Format
The program outputs employee information in the following format:
```
<ID> <Gender> <DateOfBirth> <Address> <TaxCode> <ContractDate>
```

## Example
```
00001 Nam 01/01/1990 123 Duong Bach Dang, Ha Noi 12345678901 01/01/2020
```

## Key Implementation Details
- Employee ID (`ma`) is automatically set to "00001" during input
- Input uses `getline()` for fields that may contain spaces (Name, Address)
- Output displays all employee information in a single line
- All member variables are initialized to empty strings in the constructor

## Notes
- This is an educational project focusing on OOP concepts
- Operator overloading demonstrates friend function usage
- The class demonstrates proper encapsulation with private data members
