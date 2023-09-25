#include <stdio.h> 
int towerOfHanoi(int n, char source, char auxiliary, char destination) { if (n == 1) { 
printf("Move disk 1 from %c to %c\n", source, destination);
return 1; 
} 
int steps = 0; 
steps += towerOfHanoi(n - 1, source, destination, auxiliary); 
printf("Move disk %d from %c to %c\n", n, source, destination); 
steps++; 
steps += towerOfHanoi(n - 1, auxiliary, source, destination); 
return steps; 
} 
int main() { 
int n = 4; // Number of disks 
char source = 'A', auxiliary = 'B', destination = 'C'; 
int totalSteps = towerOfHanoi(n, source, auxiliary, destination); 
printf("Total number of steps required: %d\n", totalSteps); 
return 0; 
} 

