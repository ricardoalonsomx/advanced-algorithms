# Homework - Kruskal's algorithm for Minimum Spanning Trees

## Purpose
To understand the implementation and functionality of Kruskal's algorithm for finding a minimum spanning tree in an undirected weighted graph.

## Instructions
The task will be solved in teams of up to 2 students.

Implement the Kruskal's algorithm in C++ to find a minimum spanning tree in an undirected weighted graph. The algorithm taught in class should be implemented.

The program receives an integer N as arguments, indicating the number of edges, followed by N values indicating the source node of the edges, followed by N values indicating the destination node of the edges, and finally N values indicating the weight of the edges.

For example, the program should be executed as follows:
```
>> ./a.out 16 2 3 1 1 0 4 6 5 4 1 6 2 1 6 0 0 3 6 2 5 2 7 2 7 5 3 0 7 7 4 7 4 17 52 36 32 26 37 40 28 35 29 58 34 19 93 16 38
```

For the above example, the expected output should be as follows:

```
>> 0 7 16
   2 3 17
   1 7 19
   0 2 26
   5 7 28
   4 5 35
   6 2 40
```

**Note:**
- The output should be the edges with the source node, destination node, and weight separated by a newline.

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
Solutions submitted in this repository on the GitHub classroom platform will be considered. You can either upload your separate "homework-05.cpp" file or edit the existing file and commit it.

Additionally, in the Canvas assignment space, one team member should submit a .ZIP file named A0XXXXXXX-A0YYYYYYY_Act5.1 (where XXXXXXX and YYYYYYY are the team's IDs), containing a folder named A0XXXXXXX.
