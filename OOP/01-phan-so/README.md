# C++ OOP Exercise - Fraction Addition

## Description
This exercise demonstrates Object-Oriented Programming principles in C++ by implementing a `PhanSo` (Fraction) class. The program reads two fractions, adds them, and outputs the result in simplified form.

## Features
- Fraction class with numerator and denominator
- Operator overloading for addition (`+`)
- Stream operators for input (`>>`) and output (`<<`)
- Automatic fraction normalization (simplification)
- Negative denominator handling

## Input
Two lines, each containing two integers:
```
<numerator1> <denominator1>
<numerator2> <denominator2>
```

## Output
The sum of the two fractions in simplified form:
```
<numerator> / <denominator>
```

## Example
**Input:**
```
1 2
1 3
```

**Output:**
```
5/6
```

## Compile Command
```bash
clang++ -std=c++17 -stdlib=libc++ -g Bai01/main.cpp Bai01/PhanSo.cpp -o Bai01/main
```

Or use the VS Code build task:
```
Ctrl+Shift+B (Build C++ (Auto))
```

## Run
```bash
./Bai01/main
```
