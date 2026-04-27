# C++ OOP Exercise - Student Information with Operator Overloading

## Description
This exercise demonstrates operator overloading in C++. The `SinhVien` (Student) class uses overloaded stream operators (`>>` and `<<`) for input and output, instead of friend functions.

## Features
- Student class with private data members
- Overloaded input operator (`>>`)
- Overloaded output operator (`<<`)
- Date formatting (DD/MM/YYYY)
- Fixed precision decimal output for GPA

## Input
Student information:
```
<name>
<class> <date_of_birth> <GPA>
```

## Output
Formatted student information:
```
<ID> <name> <class> <date_of_birth> <GPA>
```

## Example
**Input:**
```
Tran Thi B
DCCN002 12/8/2003 3.75
```

**Output:**
```
B20DCCN001 Tran Thi B DCCN002 12/08/2003 3.75
```

## Compile Command
```bash
clang++ -std=c++17 -stdlib=libc++ -g Bai03/main.cpp Bai03/SinhVien.cpp -o Bai03/main
```

Or use VS Code build task:
```
Ctrl+Shift+B
```

## Run
```bash
./Bai03/main
```
