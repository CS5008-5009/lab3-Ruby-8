#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

/**
  Push a new node on the front of the list
*/
void insertAtBeginning(struct Node** head, int data){
  // allocate node
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  //put in the key
  newNode -> data = data;
  //link the old list of the new node
  newNode -> next = *head;
  //move the head to point to the new node
  *head = newNode;
}

/**
  Push a new node on the front of the list
*/
void insertAtMiddle(struct Node** head, int data, int position){
  if (position < 2 || head == NULL){
    printf ("Insertion failed\n");
  }

  struct Node *temp = head;
  for (int i = 1; i < (position - 1); i++){
    if (temp == NULL){
      printf("Cannot find the position\n");
    }
    temp = temp -> next;
  }

  //insert new node
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode -> data = data;
  newNode -> next = temp -> next;
  temp -> next = newNode;
}

/**
  Push a new node on the front of the list
*/
void insertAtEnd(struct Node** head, int data){
  // allocate node
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  //put in the key
  newNode -> data = data;
  //link the old list of the new node
  newNode -> next = NULL;

  if(*head == NULL){
    *head = newNode;
    return;
  }

  struct Node* current = *head;
  while (current -> next != NULL){
    current = current -> next;
  }

  current -> next = newNode;
}
/**
  Checks whether the value x is present in linked list
  */
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
/**
  Delete elements in the beginning
*/
struct Node *deleteEnd(struct Node** head){
   if(*head == NULL){
    printf ("Empty linked list\n");
    return NULL;
  } else if ((*head) -> next == NULL){
    free(*head);
     *head = NULL;
    printf("Nothing left in the linked list!");
    return NULL;
  }
  
  struct Node* current = *head;
  struct Node* prev = NULL;
  while (current -> next != NULL){
    prev = current;
    current = current -> next;
  }

  prev -> next = NULL;
  free(current);
  return *head;
}
/**
  Delete elements in the middle
*/
struct Node *deleteMiddle (struct Node *head, int element){
  if(head == NULL){
    printf ("Empty linked list\n");
    return NULL;
  } else if (head -> next == NULL){
    free(head);
    printf("Nothing left in the linked list!");
    return NULL;
  }

  struct Node *temp = head;

  while (temp -> next -> data != element && temp -> next != NULL){
    temp = temp -> next;
    if (temp -> next == NULL){
      printf("Cannot find the element\n");
      return head;
    }
  }

  struct Node *del = temp -> next;
  temp -> next = temp->next->next;
  free(del);
  return head;
}

/**
  Delete elements in the end
*/
struct Node *deleteBeginning(struct Node** head){
   if(*head == NULL){
    printf ("Empty linked list\n");
    return NULL;
  } 
  
  struct Node* temp = *head;
  *head = (*head) -> next;
  free(temp);
  return *head;
}

/**
  function to display the linked list
*/
void display(struct Node* head) {
  struct Node* current = head;
  while (current != NULL){
    printf("%d ", current -> data);
    current = current -> next;
  }

  printf("\n");
}

int main() {
  struct Node* head = NULL;

  //Insert nodes at the beginning
  insertAtBeginning (&head, 4);
  insertAtBeginning (&head, 3);
  insertAtBeginning (&head, 2);
  insertAtBeginning (&head, 1);

  //display the linked list
  printf("The output of insertAtBeggining:\n");
  display(head);

  //Insert node at the end
  insertAtEnd (&head, 5);
  printf("The output of insertAtEnd:\n");
  display(head);

   //Insert node at the middle
  insertAtMiddle (head, 0, 3);
  printf("The output of insertAtMiddle:\n");
  display(head);

  //search for a value
  int value = 2;
  int result = search(head, value);
  if (result != -1){
    printf("The output of search value 2:\n");
    printf("Value %d found at index %d\n", value, result);} else{
    printf("Value %d not found in the linked list\n", value);}

  //delete nodes in middle
  head = deleteMiddle(head, 3);
  printf("The output after deleting middle value 3:\n");
  display(head);

  //delete node in beginning
  head = deleteBeginning(&head);
  printf("The output after deleting beginning value:\n");
  display(head);

  //delete node in the end
  head = deleteEnd(&head);
  printf("The output after deleting end value :\n");
  display(head);
  
  //Free allocated memory
  struct Node* current = head;
  while (current != NULL){
    struct Node* temp = current;
    current = current -> next;
    free(temp);
  }
  return 0;
}

