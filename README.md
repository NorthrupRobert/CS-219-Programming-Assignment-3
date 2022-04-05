# Programming Project Part 2 For CS219 Computer Organization
> This project takes in a set of commands (as per the "input.txt" file indicates) using the Assembly format. Program will run through C++, using hexidecimal numbers.  Functions available to the user include ADD, AND, ASR, LSR, LSL, NOT, ORR, SUB, and XOR.
This software is designed for an in-class project.
## Installation
> Linux Installation -
Utilizes Linux Make
## Usage
1. Navigate to build folder
2. Ensure "input.txt" is properly prepared, with assembly commands given
3. Execute
```sh
> make
> ./passignment2
> 
```
## Example
### Input File (input.txt):
```sh
ADD		0x6E09F		0x8967
AND		0x6E09F		0x8967
ASR		0x6E09F
LSR		0x6E09F
LSL		0x6E09F
NOT		0x6E09F
ORR		0x6E09F		0x8967
SUB		0x6E09F		0x8967
XOR		0x6E09F		0x8967
```
### Terminal Output:
```bash
~/CS-219-Programming-Project-2$ make
~/CS-219-Programming-Project-2$ ./passignment2
> ================================
> ----PROGRAMMING ASSIGNMENT 2----
> ================================
> SUM OF 0x6E09F AND 0x8967 -> 0x76A06
> AND BITWISE OPERATION ON 0x6E09F AND 0x8967 -> 0x8007
> ARITHMETIC SHIFT RIGHT OF 0x6E09F -> 0x3704F
> LOGICAL SHIFT RIGHT OF 0x6E09F -> 0xDC13E
> LOGICAL SHIFT LEFT OF 0x6E09F -> 0x3704F
> NOT OF 0x6E09F -> 0xFFF91F60
> ORR BITWISE OPERATION ON 0x6E09F AND 0x8967 -> 0x6E9FF
> DIFFERENCE OF 0x6E09F AND 0x8967 -> 0x65738
> XOR BITWISE OPERATION ON 0x6E09F AND 0x8967 -> 0x669F8
> ================================
```
## Release History
### 0.4.0
- Fixed bitwise shifts
- Arithmetic shift right implemented
### 0.3.0
- Fixed exception handling
- Fixed file input format checking
### 0.2.0
- Implemented skeleton for all operators necissary for assignment.
- Refactored code to allow only one operand for an operator that will only utilize that one element.
### 0.1.0
- Code base is implemented/brought over PP1 code and refactored for PP2 material.
## Meta
Robb Northrup - robbnorthrup@outlook.com
[Github](https://github.com/NorthrupRobert/CS219-Programming-Project-1.git)