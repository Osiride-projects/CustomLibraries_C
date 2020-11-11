#include <stdio.h>
#include <stdlib.h>
#include <linked_list.h>


void listInsertFront(headPtr* l, int x){
  node* new = malloc(sizeof(node));
  if(new == NULL)
    fprintf(stderr, "error on malloc");
  new->val = x;
  new->next = *l;
  *l = new;
}


void listDeleteFront(headPtr* l){
  node* del = *l;
  *l = (*l)->next;
  free(del);
}


void listInsertBottom(headPtr* l, int x){
  node* new = malloc(sizeof(node));
  if(new == NULL)
    fprintf(stderr, "error on malloc");
  new->val = x;
  new->next = NULL;

  //if l is empty -> insert in front
  if(*l == NULL){   //head insertion
    new->next = *l;
    *l = new;
    return;
  }

  node* curr = *l;
  while(curr->next != NULL)
    curr = curr->next;
  curr->next = new;
}


void listDeleteBottom(headPtr* l){
  node* prev = NULL;
  node* curr = *l;
  while(curr->next != NULL){
    prev = curr;
    curr = curr->next;
  }
  prev->next = NULL;
  free(curr);
}


void listInsertSorted(headPtr* l, int x){
  node* new = malloc(sizeof(node));
  if(new == NULL)
    fprintf(stderr, "error on malloc");
  new->val = x;
  new->next = NULL;

  node* curr = *l;
  node* prev = NULL;
  while(curr != NULL && curr->val < x){ //sort condition
    prev = curr;
    curr = curr->next;
  }

  if(prev == NULL){
    new->next = *l;
    *l = new;
  }
  else{
    prev->next = new;
    new->next = curr;
  }
}


void listDeleteElement(headPtr* l, int x){

  node* curr = *l;
  node* prev = NULL;
  while(curr != NULL && curr->val != x){
    prev = curr;
    curr = curr->next;
  }
  if(curr == NULL)
    fprintf(stderr, "element not found\n");
  else{
    node* tmp;
    if(prev == NULL){
      tmp = *l;
      *l = (*l)->next;
    }
    else{
      tmp = curr;
      prev->next = curr->next;
      curr = curr->next;
    }
    free(tmp);
  }
}


void listDeleteOccurrences(headPtr* l, int x){

  node* curr = *l;
  node* prev = NULL;
  while(curr != NULL){
    while(curr != NULL && curr->val != x){
      prev = curr;
      curr = curr->next;
    }
    if(curr == NULL)
      fprintf(stderr, "element not found\n");
    else{
      node* tmp;
      if(prev == NULL){
        tmp = *l;
        *l = (*l)->next;
        curr = *l;
      }
      else{
        tmp = curr;
        prev->next = curr->next;
        curr = curr->next;
      }
      free(tmp);
    }
  }
}


int listGetElement(headPtr l, int i){

  int element = -1;
  for (size_t k = 0; l != NULL && k < i; k++) {
    element = l->val;
    l = l->next;
  }
  return element;
}


int listLength(headPtr l){
  int counter = 0;
  while(l != NULL){
    counter++;
    l = l->next;
  }
  return counter;
}


void listPrint(headPtr l){
  while(l != NULL){
    printf("%d-> ", l->val);
    l = l->next;
  }
  printf("End\n");
}


void listPrintReverse(headPtr l){
  if(l == NULL)
    return;
  listPrintReverse(l->next);
  printf("%d-> ", l->val);
}
