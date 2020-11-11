typedef struct n{
  int key;
  struct n* right;
  struct n* left;
}node;

//allocate a new node
node* treeNewNode(int x);

//create a node and insert it in the tree
node* treeInsert(node* root, int x);

//Root - Tree_Left - Tree_Right
void treePrevisit(node* root);

//Tree_Left - Root - Tree_Right
void treeInvisit(node* root);

//Tree_Left - Tree_Right - Root
void treePostvisit(node* root);
