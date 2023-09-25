#include<stdio.h> 
#include<stdlib.h> 
int no_vertices; 
struct node 
{ 
int data; 
struct node *next; 
}; 
void readgraph(struct node *ad[]); 
void printgraph(struct node *ad[]); 
int main() 
{
int i,j,k; 
printf("Enter the total numbe of vertex :"); 
scanf("%d",&no_vertices); 
struct node *adj[no_vertices]; 
for(i=0;i<no_vertices;i++) 
{ 
adj[i] = NULL; 
} 
readgraph(adj); 
printgraph(adj); 
return 0; 
} 
void readgraph(struct node *ad[]) 
{ 
struct node *newnode; 
int i,j,k,data; 
for(i=0;i<no_vertices;i++) 
{ 
struct node *last =NULL; 
printf("\nEnter the Number of neighbours of %d :",i); scanf("%d",&k); 
for(j=0;j<k;j++) 
{ 
printf("Enter the value of %d neighbour of %d : ",j,i); scanf("%d",&data); 
newnode = (struct node*)malloc(sizeof(struct node*)); newnode->data = data; 
newnode->next = NULL; 
if(ad[i]==NULL) 
{ 
ad[i] = newnode; 
} 
else 
last->next = newnode; 
last = newnode; 
} 
} 
} 
void printgraph(struct node *ad[]) 
{ 
struct node *ptr = NULL; 
int i,j; 
for(i=0;i<no_vertices;i++) 
{ 
ptr = ad[i]; 
printf("\n The neighbour of %d are :",i); 
while(ptr != NULL) 
{ 
printf("%d\t",ptr->data); 
ptr = ptr->next;
} 
} 
}

