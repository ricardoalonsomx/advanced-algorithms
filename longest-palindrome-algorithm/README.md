# Homework - Longest palindrome algorithm

## Purpose
To understand the implementation and functionality of the Manacher's algorithm for finding the longest palindrome.

## Instructions
The task will be solved in teams of up to 2 students.

Implement the algorithm in C++ to find the longest palindrome in a string. The algorithm taught in class should be implemented.

The program receives a string containing the text in which we need to find the longest palindrome. The program should return the starting position and length of the longest palindrome in the string.

For example, the program should be executed as follows:
```
>> ./a.out "Was it a cat I saw? Maybe a taco cat?"
```
In this text, there are more than one palindrome, such as "Was it a cat I saw" and "taco cat," but the longest one is the first one. Therefore, the program should return the starting position and length of the first palindrome.

For the above example, the expected output should be as follows:

```
>> 0 13
```

**Note:**
- The above index and length do not consider spaces in the input string (this will make development a bit easier).

## Evaluation
Your program should compile without errors or warnings and should run correctly in a Linux environment. Think of extreme test cases that can be used to test your program.
Your proposed solution should be correct and efficient.

To obtain 100% of the points for this activity, your program should:

- **80%** - List 4 test cases for each of the functionalities, where each case will be evaluated as follows:
  - **Excellent (80%)** - correctly evaluates all 4 test cases.
  - **Very Good (60%)** - correctly evaluates 3 test cases.
  - **Good (40%)** - correctly evaluates 2 test cases.
  - **Insufficient (20%)** - correctly evaluates 1 or 0 test cases.
- **20%** - The code should follow the coding standards specified in the provided coding standards document.

## Where do I submit it?
In this GitHub classroom space. The code will be evaluated using the test cases in the "Actions" tab. The code should also be uploaded to the assignment space on Canvas. 

## How do I submit it?
Solutions submitted in this repository on the GitHub classroom platform will be considered. You can either upload your separate "homework-04.cpp" file or edit the existing file and commit it.

Additionally, in the Canvas assignment space, one team member should submit a .ZIP file named A0XXXXXXX-A0YYYYYYY_Act4.1 (where XXXXXXX and YYYYYYY are the team's IDs), containing a folder named A0XXXXXXX.
