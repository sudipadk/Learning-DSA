
// Click on Run Code button to see the result

#include <stdio.h>
#include <stdlib.h>

//node structure
struct Node {
  int data;
  struct Node* next;
};

//Add new element at the end of the list
void push_back(struct Node** head_ref, int newElement) {  
  struct Node *newNode, *temp;
  newNode = (struct Node*)malloc(sizeof(struct Node)); 
  newNode->data = newElement;  
  newNode->next = NULL;
  if(*head_ref == NULL) {
    *head_ref = newNode; 
  } else {
    temp = *head_ref;
    while(temp->next != NULL) {
      temp = temp->next;
    }    
    temp->next = newNode;
  }
}

//count nodes in the list
int countNodes(struct Node* head_ref) {
  struct Node* temp = head_ref;
  int i = 0;
  while (temp != NULL) {
    i++;
    temp = temp->next;    
  }
  return i;    
}

//display the content of the list
void PrintList(struct Node* head_ref) {
  struct Node* temp = head_ref;
  if(head_ref != NULL) {
    printf("The list contains: ");
    while (temp != NULL) {
      printf("%i ",temp->data);
      temp = temp->next;  
    }
    printf("\n");
  } else {
    printf("The list is empty.\n");
  }   
}

// test the code 
int main() {
  struct Node* MyList = NULL;

  //Add four elements in the list.
  push_back(&MyList, 10);
  push_back(&MyList, 20);
  push_back(&MyList, 30);
  push_back(&MyList, 40);

  //Display the content of the list.
  PrintList(MyList);

  //number of nodes in the list
  printf("No. of nodes: %i\n",countNodes(MyList));

  return 0; 
}

