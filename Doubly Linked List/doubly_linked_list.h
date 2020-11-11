typedef struct n{
  int val;
  struct n* next;
  struct n* prev;
}node;

typedef struct {
  struct n* head;
  struct n* tail;
}list;

void listInitialize(list* l);
void listInsertFront(list* l, int x);
void listDeleteFirst(list* l);
void listInsertBottom(list* l, int x);
void listDeleteLast(list* l);
void listInsertSorted(list* l, int x);
void listDeleteElement(list* l, int x);
int listGetElement(list l, int i);
int listLength(list l);
void listPrint(list l);
void listPrintReverse(list l);
