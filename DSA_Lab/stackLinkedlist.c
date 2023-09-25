#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
int data; 
struct Node* next; 
}; 
void push(struct Node** head, int data) { 
// Create a new node 
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
new_node->data = data; 
new_node->next = NULL; 
// If the list is empty, make the new node the head 
if (*head == NULL) { 
*head = new_node; 
return; 
} 
// Set the "next" pointer of the new node to the current head 
new_node->next = *head; 
// Update the head pointer to the new node 
*head = new_node; 
} 
int pop(struct Node** head) { 
if (*head == NULL) { 
printf("Error: Stack is empty.\n"); 
return -1; // Returning -1 as an error value 
} 
// Store the data of the head node 
int data = (*head)->data; 
// Store the reference to the head node 
struct Node* temp = *head; 
// Move the head pointer to the next node 
*head = (*head)->next; 
// Free the memory of the previous head node 
free(temp); 
return data; 
}
void printList(struct Node* node) { 
while (node != NULL) { 
printf("%d ", node->data); 
node = node->next; 
} 
printf("\n"); 
} 
int main() { 
// Create an empty linked list 
struct Node* head = NULL; 
// Push elements into the list 
push(&head, 5); 
push(&head, 10); 
push(&head, 15); 
// Print the list 
printf("stack element: "); 
printList(head); 
// Pop elements from the list 
printf("Popped: %d\n", pop(&head)); 
printf("Popped: %d\n", pop(&head)); 
printf("stack element: "); 
printList(head); 
return 0; 
} 

