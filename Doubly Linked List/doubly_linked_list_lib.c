#include <stdio.h>
#include <stdlib.h>
#include <doubly_linked_list.h>

void listInitialize(list* l){
  l->head = NULL;
  l->tail = NULL;
}

void listInsertFront(list* l, int x){
  node* new = malloc(sizeof(node));
  new->val = x;
  new->next = NULL;
  new->prev = NULL;
  if(l->head == NULL || l->tail == NULL){
    new->prev = l->head;
    l->head = new;
    l->tail = new;
  }
  else{
    new->next = l->head;
    l->head = new;
  }
}

void listDeleteFirst(list* l){
  node* del = l->head;
  l->head = l->head->next;
  l->head->prev = NULL;
  free(del);
}

void listInsertBottom(list* l, int x){
  node* new = malloc(sizeof(node));
  new->val = x;
  new->next = NULL;
  new->prev = NULL;

  //if list is empty
  if(l->head == NULL && l->tail == NULL){
    new->prev = l->head;
    l->head = new;
    l->tail = new;
  }
  else{
    node* last = l->tail;
    last->next = new;
    new->prev = last;
    l->tail = new;
  }
}

void listDeleteLast(list* l){
  node* del = l->tail;
  l->tail = l->tail->prev;
  l->tail->next = NULL;
  free(del);
}

void listInsertSorted(list* l, int x){

  node* head = l->head;

  node* new = malloc(sizeof(node));
  new->val = x;
  new->next = NULL;
  new->prev = NULL;

  if(l->head == NULL || l->tail == NULL){   //if list is empty
    l->head = new;
    l->tail = new;
  }
  else if(head->val >= x){  //insert at the beginning
    new->next = l->head;
    l->head->prev = new;
    l->head = new;
  }
  else{
    node* curr = l->head;
    while(curr->next != NULL && curr->next->val < x)
        curr = curr->next;

    new->next = curr->next;
    if(curr->next != NULL)
      new->next->prev = new;
    else
      l->tail = new;
    curr->next = new;
    new->prev = curr;
  }
}

void listDeleteElement(list* l, int x){

  node* del;
  if(l->head->val == x){
    del = l->head;
    l->head = l->head->next;
    l->head->prev = NULL;
    free(del);
    return;
  }
  if(l->tail->val == x){
    del = l->tail;
    l->tail = l->tail->prev;
    l->tail->next = NULL;
    free(del);
    return;
  }


  node* curr = l->head->next;
  node* prev = l->head;
  while(curr != NULL && curr->val != x){
    prev = curr;
    curr = curr->next;
  }

  if(curr == NULL)
    fprintf(stderr, "Cant find %d\n", x);
  else{
    del = curr;
    prev->next = curr->next;
    curr = curr->next;
    curr->prev = prev;
    free(del);
  }
}

int listGetElement(list l, int i){
  int element = -1;
  node* head = l.head;
  for (size_t k = 0; head != NULL && k < i; k++) {
    element = head->val;
    head = head->next;
  }
  return element;
}

int listLength(list l){
  node* head = l.head;
  int counter = 0;
  while(head != NULL){
    counter++;
    head = head->next;
  }
  return counter;
}

void listPrint(list l){
  node* head = l.head;
  while(head != NULL){
    printf("%d-> ", head->val);
    head = head->next;
  }
  printf("End\n");
}

void listPrintReverse(list l){
  node* tail = l.tail;
  while(tail != NULL){
    printf("%d-> ", tail->val);
    tail = tail->prev;
  }
  printf("End\n");
}
