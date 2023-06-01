/* Doubly Linked List implementation */
#include<stdio.h>
#include<stdlib.h>

struct Node  {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.

//Creates a new Node and returns pointer to it. 
struct Node* createNewNode(int value) {
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
//Checks whether the value x is present in linked list
int search(struct Node* head, int value){
  struct Node* current = head;
  int index = 0;
  
  while (current != NULL){
    if (current -> data == value)
      return index;
    current = current -> next;
    index++;
  }

  //value not found
  return -1;
}
//Inserts a Node at head of doubly linked list
void InsertAtHead(int value) {
	struct Node* newNode = createNewNode(value);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head; 
	head = newNode;
}

//Inserts a Node at middle of doubly linked list
void InsertAtMiddle(int value, int position) {
	struct Node* newNode = createNewNode(value);
  struct Node* itr = head;
  int index = 0;
	if (position < 2||head == NULL) {
    printf("please use InsertAtHead()!");
    return;
  }
  while(index != position -2){
    itr = itr->next;
    index ++;
  }

  if (index != position -2){
    printf("there is no this position in list");
    return;
  }
	
	newNode->next = itr->next; 
	newNode->prev = itr;
  itr->next->prev=newNode;
  itr->next = newNode;
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(int value) {
	struct Node* itr = head;
	struct Node* newNode = createNewNode(value);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(itr->next != NULL) itr = itr->next; // Go To last Node
	itr->next = newNode;
	newNode->prev = itr;
}

//Delete a Node at beginning of Doubly linked list
void DeleteAtBeginning() {
	struct Node* itr = head;
	if(head == NULL) {
		printf("underflow");
    return;
	}
  
  // Go To first Node
  itr->next->prev = NULL;
  head = itr->next;
  free(itr);
}

//Delete a Node at middle of Doubly linked list
void DeleteAtMiddle(int value) {
	struct Node* itr = head;
  int index = 0;
	if(head == NULL) {
		printf("underflow");
    return;
	}

  while (itr->data != value){
    if (itr->next == NULL){
      printf("there is no this value");
      return;
    }
    itr = itr->next;
    index++;
  }
  if(index == 1){
    head->next = head->next->next;
    head->next->prev = head;
  }
  // Go To the position and delete
  itr->next->prev = itr->prev;
  itr->prev->next = itr->next;  
  free(itr);
}


//Delete a Node at tail of Doubly linked list
void DeleteAtTail() {
	struct Node* itr = head;
	if(head == NULL) {
		printf("underflow");
    return;
	}
	while(itr->next != NULL){
    itr = itr->next;
  }
  // Go To last Node
	itr->prev->next = NULL;
  free(itr);
}



//Prints all the elements in linked list in forward traversal order
void Print() {
	struct Node* itr = head;
	printf("Forward: ");
	while(itr != NULL) {
		printf("%d ",itr->data);
		itr = itr->next;
	}
	printf("\n");
}

//Prints all elements in linked list in reverse traversal order. 
void ReversePrint() {
	struct Node* itr = head;
	if(itr == NULL) return; // empty list, evalueit
	// Going to last Node
	while(itr->next != NULL) {
		itr = itr->next;
	}
	// Traversing backward using prev pointer
	printf("Reverse: ");
	while(itr != NULL) {
		printf("%d ",itr->data);
		itr = itr->prev;
	}
	printf("\n");
}

int main() {

	/*Driver code to test the implementation*/
	head = NULL; // empty list. set head as NULL. 
	
	// Calling an Insert and printing list both in forward as well as reverse direction. 
	InsertAtTail(2); 
  printf("Insert 2 at tail:\n");Print(); 
	InsertAtTail(6); 
  printf("Insert 4 at tail:\n");Print();
  InsertAtTail(8); 
  printf("Insert 2 at tail:\n");Print(); 
	InsertAtHead(1); 
  printf("Insert 6 at head:\n");Print(); 
  InsertAtMiddle(4,3);
  printf("Insert 0 at position 3:\n");Print();
  InsertAtMiddle(3,3);
  printf("Insert 9 at position 3:\n");Print();Print(); 
  //test search()
  if (search(head,2) != -1){
    printf("\nsearch: The index of 2 is %d\n", search(head,2));
  }
  printf("\n");
  DeleteAtTail();
	printf("Delete at tail:\n");Print();
  DeleteAtBeginning();
  printf("Delete at beginning:\n");Print();
  DeleteAtMiddle(3);
  printf("Delete value 8:\n");Print();
  printf("Reverse print:\n");ReversePrint();
}