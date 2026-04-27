# Student List Sorter

## Description

A simple C++ program that manages and sorts a list of students by their ID. The application reads student information, stores it in a dynamic collection, and outputs the sorted results.

## Features

- **Student Data Management**: Stores student information including ID, name, class, and email
- **Dynamic Input**: Reads an arbitrary number of student records until EOF
- **Sorting Capability**: Automatically sorts students by ID in ascending order
- **Operator Overloading**: Implements custom input/output operators for user-friendly data handling
- **Vector-Based Storage**: Uses `std::vector` for efficient data management

## Technical Concepts Used

- Class and Object-Oriented Programming
- Constructor initialization
- Friend functions
- Operator overloading (`>>`, `<<`, `<`)
- STL Vector container
- Algorithm library (`std::sort`)

## Input Format

Each student record should be entered on a single line with the following format:

```
<ID> <Name> <Class> <Email>
```

**Example:**
```
SV001 Nguyen Van A 10A1 a.nguyen@school.edu
SV003 Tran Thi B 10A2 b.tran@school.edu
SV002 Le Van C 10A1 c.le@school.edu
```

Read until EOF (Ctrl+D on Unix/Mac or Ctrl+Z on Windows).

## Output

The program outputs the sorted list of students by ID in ascending order:

```
SV001 Nguyen Van A 10A1 a.nguyen@school.edu
SV002 Le Van C 10A1 c.le@school.edu
SV003 Tran Thi B 10A2 b.tran@school.edu
```

## Sample Execution

**Input:**
```
SV005
Pham Quoc D
10A3 d.pham@school.edu
SV001
Nguyen Van A
10A1 a.nguyen@school.edu
SV003
Tran Thi B
10A2 b.tran@school.edu
SV002
Le Van C
10A1 c.le@school.edu
SV004
Hoang Van E
10A2 e.hoang@school.edu
```

**Output:**
```
SV001 Nguyen Van A 10A1 a.nguyen@school.edu
SV002 Le Van C 10A1 c.le@school.edu
SV003 Tran Thi B 10A2 b.tran@school.edu
SV004 Hoang Van E 10A2 e.hoang@school.edu
SV005 Pham Quoc D 10A3 d.pham@school.edu
```