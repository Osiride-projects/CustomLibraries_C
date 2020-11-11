typedef struct n{
  int val;
  struct n* next;
}node;
typedef node* headPtr;

//Insert the element x in the first position of the list l
void listInsertFront(headPtr* l, int x);

//Delete the first element from the list l
void listDeleteFront(headPtr* l);

//Insert the element x in the last position of the list l
void listInsertBottom(headPtr* l, int x);

//Delete the last element from the list l
void listDeleteBottom(headPtr* l);

//Insert the element x in order in the list l
void listInsertSorted(headPtr* l, int x);

//Delete the element x from the list l
void listDeleteElement(headPtr* l, int x);

//Delete all the occurrences of x from the list l
void listDeleteOccurrences(headPtr* l, int x);

//Return the i-th element of the list l
int listGetElement(headPtr l, int i);

//Return the numbers of element inside the list l
int listLength(headPtr l);

//Print the list l
void listPrint(headPtr l);

//Print the list l but reversed
void listPrintReverse(headPtr l);
