# C++ OOP Exercise - Student Information

## Description
This exercise demonstrates class design and friend functions in C++. The `SinhVien` (Student) class manages student information including ID, name, class, date of birth, and GPA.

## Features
- Student class with private data members
- Friend functions for input and output
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
Nguyen Van A
DCCN001 5/3/2002 3.50
```

**Output:**
```
B20DCCN001 Nguyen Van A DCCN001 05/03/2002 3.50
```

## Compile Command
```bash
clang++ -std=c++17 -stdlib=libc++ -g Bai02/main.cpp Bai02/SinhVien.cpp -o Bai02/main
```

Or use VS Code build task:
```
Ctrl+Shift+B
```

## Run
```bash
./Bai02/main
```
