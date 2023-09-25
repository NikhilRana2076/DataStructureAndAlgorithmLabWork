#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
int data; 
struct Node* next; 
}; 
struct Node* createNode(int data) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
if (newNode == NULL) {
printf("Memory allocation failed!\n"); 
return NULL; 
} 
newNode->data = data; 
newNode->next = NULL; 
return newNode; 
} 
void enqueue(struct Node** front, struct Node** rear, int data) { struct Node* newNode = createNode(data); 
if (*rear == NULL) { 
*front = newNode; 
*rear = newNode; 
} else { 
(*rear) -> next = newNode; 
*rear = newNode; 
} 
} 
int dequeue(struct Node** front, struct Node** rear) { if (*front == NULL) { 
printf("Error: Queue is empty!\n"); 
return -1; // Returning -1 as an error value 
} 
struct Node* temp = *front; 
int data = temp->data; 
*front = (*front)->next; 
if (*front == NULL) { 
*rear = NULL; 
} 
free(temp); 
return data; 
} 
void printQueue(struct Node* front) { 
if (front == NULL) { 
printf("Queue is empty!\n"); 
return; 
} 
printf("Queue: "); 
while (front != NULL) { 
printf("%d ", front->data); 
front = front->next; 
} 
printf("\n"); 
} 
int main() { 
struct Node* front = NULL; 
struct Node* rear = NULL; 
// Enqueue elements 
enqueue(&front, &rear, 10); 
enqueue(&front, &rear, 20);
enqueue(&front, &rear, 30); 
// Print the queue 
printQueue(front); 
// Dequeue elements 
printf("Dequeued: %d\n", dequeue(&front, &rear)); 
printf("Dequeued: %d\n", dequeue(&front, &rear)); 
// Print the updated queue 
printQueue(front); 
// Dequeue from an empty queue 
printf("Dequeued: %d\n", dequeue(&front, &rear)); 
return 0; 
} 

