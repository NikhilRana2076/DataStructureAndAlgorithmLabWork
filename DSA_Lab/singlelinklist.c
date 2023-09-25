#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
int data; 
struct Node* next; 
}; 
// Function to create a new node 
struct Node* createNode(int data) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
if (newNode == NULL) { 
printf("Memory allocation failed.\n"); 
return NULL; 
} 
newNode->data = data; 
newNode->next = NULL; 
return newNode; 
} 
// Function to insert at the beginning 
void insertAtBeginning(struct Node** head, int data) { 
struct Node* newNode = createNode(data); 
if (newNode == NULL) { 
// Error occurred during memory allocation 
return; 
} 
newNode->next = *head; 
*head = newNode; 
} 
// Function to insert at the end 
void insertAtEnd(struct Node** head, int data) { 
struct Node* newNode = createNode(data); 
if (newNode == NULL) { 
// Error occurred during memory allocation 
return; 
} 
if (*head == NULL) { 
// If the linked list is empty, make the new node as the head 
*head = newNode; 
return; 
} 
struct Node* current = *head; 
while (current->next != NULL) { 
current = current->next; 
}
current->next = newNode; 
} 
// Function to insert at a desired position 
void insertAtPosition(struct Node** head, int data, int position) { if (position < 0) { 
printf("Invalid position.\n"); 
return; 
} 
struct Node* newNode = createNode(data); 
if (newNode == NULL) { 
// Error occurred during memory allocation 
// Handle error or exit the program 
return; 
} 
if (position == 1) { 
// Insert at the beginning if position is 1 
newNode->next = *head; 
*head = newNode; 
return; 
} 
struct Node* current = *head; 
int currentPosition = 1; // Start from position 1 
while (current != NULL && currentPosition < position - 2) { current = current->next; 
currentPosition++; 
} 
if (current == NULL) { 
printf("Position exceeds the length of the linked list.\n"); return; 
} 
newNode->next = current->next; 
current->next = newNode; 
} 
// Function to delete at the end 
void deleteAtEnd(struct Node** head) { 
if (*head == NULL) { 
printf("Linked list is empty. Nothing to delete.\n"); return; 
} 
if ((*head)->next == NULL) { 
// If there is only one node in the linked list 
free(*head); 
*head = NULL; 
return; 
} 
struct Node* secondLast = *head; 
while (secondLast->next->next != NULL) { 
secondLast = secondLast->next; 
} 
free(secondLast->next);
secondLast->next = NULL; 
} 
// Function to print the linked list 
void printList(struct Node* head) { 
struct Node* current = head; 
while (current != NULL) { 
printf("%d ", current->data); 
current = current->next; 
} 
printf("\n"); 
} 
int main() { 
struct Node* head = createNode(12); 
struct Node* second = createNode(23); 
struct Node* third = createNode(34); 
struct Node* fourth = createNode(45); 
if (head == NULL || second == NULL || third == NULL || fourth == NULL) { return 1; // Error occurred 
} 
head->next = second; 
second->next = third; 
third->next = fourth; 
// Inserting another node at the beginning 
insertAtBeginning(&head, 88); 
// Inserting another node at the end 
insertAtEnd(&head, 57); 
// Inserting a node at a desired position 
insertAtPosition(&head, 99, 2); 
// Deleting the node at the end 
deleteAtEnd(&head); 
// Printing the linked list 
printf("Linked List: "); 
printList(head); 
// Freeing the memory allocated for the nodes 
free(head); 
free(second); 
free(third); 
free(fourth); 
return 0; 
} 

