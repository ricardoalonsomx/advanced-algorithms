# Homework - Convex hull

## Purpose
To understand the implementation and functionality of the algorithm for finding the convex hull of a set of points.

## Instructions
The task will be solved in teams of up to 2 students.

Implement the algorithm to find the convex hull of a set of points in C++. The algorithm seen in class should be implemented.

The program receives an integer N as arguments, indicating the number of points, followed by N values indicating the x-coordinate of each point, and then N values indicating the y-coordinate of each point.

For example, the program should be executed as follows:
```
>> ./a.out 5 1 -2 -3 4 12 2 4 12 16 8
```

For the above example, the expected output should be as follows:

```
>> -2 4
   -3 12
   4 -16
   12 8
```
**Note:**
The output should be the points that form the convex hull in the order they appear in the input, separated by a line break.

## Evaluation
Your program should compile without errors or warnings and should run correctly in a Linux environment. Think of extreme test cases that can be used to test your program. Your proposed solution should be correct and efficient.

To obtain 100% of the points for this activity, your program should:

- **80%** - List 4 test cases for each of the functionalities, where each case will be evaluated as follows:
  - **Excelente (80%)** - correctly evaluates all 4 test cases.
  - **Muy Bien (60%)** - correctly evaluates 3 test cases.
  - **Bien (40%)** - correctly evaluates 2 test cases.
  - **Insuficientre (20%)** - correctly evaluates 1 or 0 test cases.
- **20%** - The code should follow the coding standards specified in the provided coding standards [document](https://experiencia21.tec.mx/courses/173572/files/52881961?wrap=1)

## Where do I submit it?
In this GitHub classroom space. The code will be evaluated using the test cases in the "Actions" tab. The code should also be uploaded to the assignment space on Canvas.

## How do I submit it?
Solutions submitted in this repository on the GitHub classroom platform will be considered. You can either upload your separate "homework-09.cpp" file or edit the existing file and commit it.

Additionally, in the Canvas assignment space, one team member should submit a .ZIP file named A0XXXXXXX-A0YYYYYYY_Act9.1 (where XXXXXXX and YYYYYYY are the team's IDs), which should contain a folder named A0XXXXXXX-A0YYYYYYY_Act9.1. Inside this folder, there should be a single .cpp file. You can have one or more .h files.

Only one submission per team. Failure to comply with this submission format will result in a 20-point deduction from the obtained score.

