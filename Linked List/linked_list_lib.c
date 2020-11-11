#include <stdio.h>
#include <stdlib.h>
#include <linked_list.h>

//in main declare list l_one = NULL;

/*
  @Overview: insert an element in the first position
*/
void list_insert_front(headPtr* l, int x){
  node* new = malloc(sizeof(node));
  if(new == NULL)
    fprintf(stderr, "error on malloc");
  new->val = x;
  new->next = *l;
  *l = new;
}

/*
  @Overview: delete the first element of the list
*/
void list_delete_front(headPtr* l){
  node* del = *l;
  *l = (*l)->next;
  free(del);
}

/*
  @Overview: insert an element in the last position
*/
void list_insert_bottom(headPtr* l, int x){
  node* new = malloc(sizeof(node));
  if(new == NULL)
    fprintf(stderr, "error on malloc");
  new->val = x;
  new->next = NULL;

  //if l is empty -> insert in front
  if(*l == NULL){
    new->next = *l;
    *l = new;
    return;
  }
  //otherwise read all the elements until the last one
  node* curr = *l;
  while(curr->next != NULL)
    curr = curr->next;
  curr->next = new;
}

/*
  @Overview: delete the last element of the list
*/
void list_delete_bottom(headPtr* l){
  node* prev = NULL;
  node* curr = *l;
  while(curr->next != NULL){
    prev = curr;
    curr = curr->next;
  }
  prev->next = NULL;
  free(curr);
}

/*
  @Overview: insert an element in the right position to make the list sorted
*/
void list_insert_sorted(headPtr* l, int x){
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

/*
  @Overview: delete a specific element of the list
*/
void list_delete_element(headPtr* l, int x){
  node* curr = *l;
  node* prev = NULL;
  while(curr != NULL && curr->val != x){
    prev = curr;
    curr = curr->next;
  }
  if(curr == NULL)
    fprintf(stderr, "element not found\n");
  else{
    node* del = curr;
    prev->next = curr->next;
    curr = curr->next;
    free(del);
  }
}

/*
  @Overview: delete all elements of the list
*/
void list_delete_all(headPtr* l, int x){

  int found = 0;
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
      node* del = curr;
      prev->next = curr->next;
      curr = curr->next;
      free(del);
    }
  }
}

/*
  @Overview: list length
*/
int list_length(headPtr l){
  int counter = 0;
  while(l != NULL){
    counter++;
    l = l->next;
  }
  return counter;
}

/*
  @Overview: print the list
*/
void list_print(headPtr l){
  while(l != NULL){
    printf("%d-> ", l->val);
    l = l->next;
  }
  printf("End\n");
}

/*
  @Overview: print the list reversed
*/
void list_print_reverse(headPtr l){
  if(l == NULL)
    return;
  list_print_reverse(l->next);
  printf("%d-> ", l->val);
}
