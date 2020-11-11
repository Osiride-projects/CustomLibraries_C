#include <stdio.h>
#include <stdlib.h>
#include <doubly_linked_list.h>

int main(int argc, char const *argv[]) {

  int x;
  list listOne;
  listInitialize(&listOne);

  //Insert element in first position
  printf("Insert in the first position: ");
  for (x = 0; x < 10; x++) {
    listInsertFront(&listOne, x);
  }
  listPrint(listOne);

  //delete element in first position
  printf("Delete element in the first position: ");
  listDeleteFirst(&listOne);
  listPrint(listOne);


  //---------------------

  list listTwo;
  listInitialize(&listTwo);

  //Insert element in last position
  printf("Insert in the last position: ");
  for (x = 20; x < 30; x++) {
    listInsertBottom(&listTwo, x);
  }
  listPrint(listTwo);

  //Delete element from last position
  printf("Delete element in the last position: ");
  listDeleteLast(&listTwo);
  listPrint(listTwo);

  //Delete a specified element
  printf("Delete the element 24: ");
  listDeleteElement(&listTwo, 24);
  listPrint(listTwo);


  //---------------------

  list listThree;
  listInitialize(&listThree);

  //Insert element in the correct position
  printf("Insert in the correct position: ");
  for (size_t i = 0; i < 10; i++) {
    x = rand() % 8;
    listInsertSorted(&listThree, x);
  }
  listPrint(listThree);
  //Get a specified element
  printf("Get the 2nd element: %d\n", listGetElement(listThree, 2));
  //Get list length
  printf("Size of that list %d\n", listLength(listThree));
  printf("Reverse: ");
  listPrintReverse(listThree);


  free(listOne.head);
  free(listTwo.head);
  free(listThree.head);
  return 0;
}
