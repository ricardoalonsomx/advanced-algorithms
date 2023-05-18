# Homework - Shape Context

## Purpose
To understand the implementation and functionality of the Shape Context algorithm for finding correspondences between shapes.

## Instructions
The task will be solved in teams of up to 2 students.

The shape context algorithm is divided into three parts:

1. Calculate the shape descriptor for the input point set (slides 8 and 9). **100 points**
2. Calculate the correspondence cost matrix (slides 10 and 11). **+25 points**
3. Calculate the distance between two shapes (slide 12). **+25 points**

In this task, ONLY part 1 of the algorithm will be evaluated, which is calculating the shape descriptor for the input point set (slides 8 and 9).

Implement the algorithm in C++ to calculate the shape descriptor based on the shape context algorithm using 12 sector bins and 5 radial bins, with a radius of size 10. The radial sectors will be uniform and not logarithmic.

The program receives as arguments an integer N (indicating the number of points), followed by N values indicating the x-coordinate of each point, followed by N values indicating the y-coordinate of each point.

**Note:** The order of the histograms in the output should be the same order as the points in the input. Row 0 of the histogram corresponds to points with a distance from 0 to 2, while column 0 corresponds to points with angles from 0 to 30, and so on. Points with a distance greater than 10 are discarded.

```
>> ./a.out 5 1 -2 -3 4 12 2 4 12 16 8
```

The output of the algorithm should be a vector of 60 values (12 x 5 bins) for each input point.

For the example above, the expected output is as follows:
```
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 1 0 0

0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
```

## Evaluation
Your program should compile without errors or warnings and should run correctly in a Linux environment. Think of extreme test cases that can be used to test your program.
Your proposed solution should be correct and efficient.

To receive 100% of the points for this assignment, your program should:

- **80%** - Provide a list of 4 test cases for each functionality, where each case will be evaluated as follows:
  - **Excellent (80%)** - Correctly evaluates all 4 test cases.
  - **Very Good (60%)** - Correctly evaluates 3 test cases.
  - **Good (40%)** - Correctly evaluates 2 test cases.
  - **Insufficient (20%)** - Correctly evaluates 1 or 0 test cases.
- **20%** - The code must follow the coding standard guidelines.
Remember that 10 points will be deducted for each day of late submission.

## Where to Submit?
In this space on GitHub Classroom. The code will be evaluated with the test cases in the "Actions" tab. You should also upload the code to the assignment space on Canvas.

## How to Submit?
Solutions submitted in this GitHub classroom repository will be considered. You can upload your "homework-10.cpp" file separately or edit the existing file and commit it.

Additionally, in the Canvas assignment space, one team member should submit a .ZIP file named A0XXXXXXX-A0YYYYYYY_Act10.1 (where XXXXXXX and YYYYYYY are the team's IDs), containing a folder named A0XXXXXXX-A0YYYYYYY_Act10.1,
     which contains a single .cpp file. You can have one or more .h files.

Only one submission per team.
Failure to comply with this submission format will result in a 20-point penalty on the obtained grade.
