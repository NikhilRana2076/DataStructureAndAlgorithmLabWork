#include <stdio.h> 
// Function prototype 
int gcd(int num1, int num2); 
int main() { 
int num1, num2; 
printf("Enter two positive integers: "); 
scanf("%d %d", &num1, &num2); 
if (num1 <= 0 || num2 <= 0) { 
printf("Please enter positive integers only.\n"); 
} else { 
int result = gcd(num1, num2); 
printf("GCD of %d and %d is: %d\n", num1, num2, result); 
} 
return 0; 
} 
// Function to find GCD using recursion 
int gcd(int num1, int num2) { 
// Base case: if the second number is 0, then the GCD is the first number
if (num2 == 0) { 
return num1; 
} else { 
// Recursive case: call the function with the second number and the remainder of  num1 divided by num2 
return gcd(num2, num1 % num2); 
} 
} 
