typedef struct n{
  int val;
  struct n* next;
}node;
typedef node* headPtr;

void list_insert_front(headPtr* l, int x);
void list_delete_front(headPtr* l);
void list_insert_bottom(headPtr* l, int x);
void list_delete_bottom(headPtr* l);
void list_insert_sorted(headPtr* l, int x);
void list_delete_element(headPtr* l, int x);
void list_delete_all(headPtr* l, int x);
int list_length(headPtr l);
void list_print(headPtr l);
void list_print_reverse(headPtr l);
