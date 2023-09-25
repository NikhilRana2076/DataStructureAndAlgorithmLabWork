#include <stdio.h>
#include <stdlib.h>
// Node structure for doubly linked list
struct Node {
int data;
struct Node* prev;
struct Node* next;
};
// Function to create a new node
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->prev = NULL;
newNode->next = NULL;
return newNode;
}
// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
struct Node* newNode = createNode(data);
newNode->next = *head;
if (*head != NULL)
(*head)->prev = newNode;
*head = newNode;
}
// Function to insert a node at the middle of the list
void insertAtMiddle(struct Node** head, int data, int position) {
struct Node* newNode = createNode(data);
struct Node* current = *head;
int count = 0;
while (count < position - 1 && current->next != NULL) {
current = current->next;
count++;
}
newNode->next = current;
newNode->prev = current->prev;
if (current->prev != NULL)
current->prev->next = newNode;
current->prev = newNode;}
//function to delete at the beginning...
void deleteFromBeginning(struct Node** head) {
if (*head == NULL)
return;
struct Node* temp = *head;
*head = (*head)->next;
if (*head != NULL)
(*head)->prev = NULL;
free(temp);
}
// Function to delete a node from the end of the list
void deleteFromEnd(struct Node** head) {
if (*head == NULL)
return;
struct Node* current = *head;
while (current->next != NULL)
current = current->next;
current->prev->next = NULL;
free(current);
}

// Function to print the doubly linked list
void printList(struct Node* head) {
struct Node* current = head;
while (current != NULL) {
printf("%d ", current->data);
current = current->next;
}
printf("\n");
}
// Main function
int main() {
struct Node* head = NULL;
// Create nodes
struct Node* node1 = createNode(1);
struct Node* node2 = createNode(2);
struct Node* node3 = createNode(3);node1->next = node2;
node2->prev = node1;
node2->next = node3;
node3->prev = node2;
// Set the head to the first node
head = node1;
// Inserting nodes at the beginning
insertAtBeginning(&head, 4);
// Inserting node at the middle
insertAtMiddle(&head, 10, 3);
// Deleting node from the beginning
deleteFromBeginning(&head);
// Deleting node from the end
deleteFromEnd(&head);
// Print the doubly linked list
printf("Doubly linked list: ");
printList(head);
free(node1);
free(node2);free(node3);
return 0;
}
