#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Structure of node */
struct node
{
int data;
struct node *next;
} *head;

void initialize()
{
head = NULL;
}

/* Function to insert a node in linke dlist */
void insert(int num)
{
struct node* newNode = (struct node*) malloc(sizeof(struct node));
newNode->data = num;
newNode->next = head;
head = newNode;
}

/* Function to find the length of the linked list */
int getLength(struct node *head)
{
if (head == NULL)
{
printf("Error : Invalid node pointer !!!\n");
return 0;
}

int length =0;
while(head != NULL){
head = head->next;
length++;
}
return length;
}

/* Function to find the Nth node from the last */
struct node* getNthLastNode(struct node* head, int n)
{
struct node *front, *back;
int i;
front = back = head;
if(n > getLength(head))
{
printf("Error : n is greater than length of Linked List\n");
return NULL;
}
for(i = 0; i < n-1; i++){
front = front->next;
}
/* Now, move both pointers together till front reaches
last node of linked list */
while(front->next != NULL){
front = front->next;
back = back->next;
}

return back;
}

/* Prints a linked list from head node till tail node */
void printLinkedList(struct node *nodePtr) {
while (nodePtr != NULL) {
printf("%d", nodePtr->data);
nodePtr = nodePtr->next;
if(nodePtr != NULL)
printf("�>");
}
}

int main()
{
int N, k;
struct node *NthNode;
initialize();
/* Creating a linked List*/
int new_node;
int i;
printf("\nEnter the total number of nodes : "); /* Number of nodes */
scanf("%d",&k);
printf("\nEnter the data for the nodes : ");
for(i = 0; i < k; i++)
{
scanf("%d",&new_node);
insert(new_node); /* Inserting the nodes */
}

printf("\nLinked List : ");
printLinkedList(head);
printf("\n\nEnter value of N : ");
scanf("%d", &N);
NthNode = getNthLastNode(head, N);
printf("\nNth Last node is %d\n", NthNode->data);
return 0;
}
