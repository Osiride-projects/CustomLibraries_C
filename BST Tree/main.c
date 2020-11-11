#include <stdio.h>
#include <stdlib.h>
#include <bst.h>

int main(int argc, char const *argv[]) {

  int x;
  node* tree = NULL;

  tree = treeNewNode(150);
  node* next = tree;

  for (size_t i = 0; i < 20; i++) {
    x = rand() % 50;
    next = treeInsert(next, x);
  }
  treePrevisit(tree);
  printf("\n");
  treeInvisit(tree);
  printf("\n");
  treePostvisit(tree);
  printf("\n");


  free(tree);
  return 0;
}
