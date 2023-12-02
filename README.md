# ICS_CP_ATTAGALLU
Eigenvalue Calculation Program:
      This C program calculates eigenvalues of a 3x3 matrix using the Power Iteration method.
      The usage of this program:
           INPUT: Enter the 3*3 matrix when prompted.
                press 'Enter' or "space bar" to enter the next element of the matrix.
           OUTPUT: The program will print the eigen values of the given matrix.

In the program <math.h>,<stdbool.h> libraries are used.
ENVIRONMENTAL SETUP:
  Make sure you have the GCC compiler installed on your system.
ALGORITHM:
  The program uses the Power Iteration method to find the largest eigenvalue of the input matrix. 
  It then calculates the remaining eigenvalues using the characteristic equation.
COMPILATION:
  1.Open a terminal window in the directory containing the source code.
EXECUTION:
  1.Run the compiled program in 
  2.Enter the 3x3 matrix when prompted. Each matrix element should be separated by a space, and each row should be on a new line.
    ->For the input matrix:

  ...
  Enter the elements of 3x3 matrix :
  1 2 3
  3 2 1
  2 1 3
  ...

  ->The program will give the output:

  ...
  The eigen values are : 
  6.000000
  1.414214
  -1.414214
  ...

  NOTE:
    1.The eigenvalues are calculated by using  Power Iteration method ,the convergence error is set to be 0.0001.
    2.Enter the inputs accurately for precise results.

