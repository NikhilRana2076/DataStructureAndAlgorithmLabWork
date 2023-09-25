#include <stdio.h> 
#include <stdbool.h> 
// Function prototype 
bool is_prime(int n, int divisor); 
int main() { 
int num; 
printf("Enter a positive integer: "); 
scanf("%d", &num); 
if (num <= 0) { 
printf("Please enter a positive integer.\n"); 
} else { 
if (is_prime(num, 2)) { 
printf("%d is a prime number.\n", num); 
} else { 
printf("%d is not a prime number.\n", num); 
} 
} 
return 0; 
} 
// Function to check if a number is prime using recursion 
bool is_prime(int n, int divisor) { 
// Base cases: If the number is less than 2 or equal to the divisor, it's not prime if (n < 2) 
return false; 
if (n == 2) 
return true; 
if (n % divisor == 0) 
return false; 
// If the divisor exceeds the square root of the number, it's prime
if (divisor * divisor > n) 
return true; 
// Recursive case: check the next divisor return is_prime(n, divisor + 1); 
} 

