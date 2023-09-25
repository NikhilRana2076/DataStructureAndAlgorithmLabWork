#include <stdio.h> 
int factorial(int n) 
{ 
// Base case: factorial of 0 and 1 is 1 
if (n == 0 || n == 1) 
return 1; 
// Recursive case: factorial of n is n multiplied by factorial of (n-1) 
return n * factorial(n - 1); 
} 
int main() 
{ 
int number; 
printf("Enter a positive integer: "); 
scanf("%d", &number); 
int result = factorial(number); 
printf("Factorial of %d is %d\n", number, result); 
return 0; 
} 
