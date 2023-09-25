#include <stdio.h>
// Function to calculate Fibonacci number recursively
int fibonacci(int n)
{
// Base case: Fibonacci of 0 and 1 is the number itself
if (n == 0 || n == 1)
return n;
// Recursive case: Fibonacci of n is the sum of Fibonacci of (n-1) and Fibonacci of (n-2)
return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
int number;
printf("Enter the number of terms: ");
scanf("%d", &number);
printf("Fibonacci Series: ");
for (int i = 0; i < number; i++)
{
printf("%d ", fibonacci(i));
}
printf("\n");
return 0;
}
