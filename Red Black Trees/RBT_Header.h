/*				RBT_Header.h					*/
 
enum COLOR  //Color for each node.
{
    Red,
    Black
};

typedef struct tree_node    //Node in RBT.
{
    int data;
    struct tree_node *right;
    struct tree_node *left;
    struct tree_node *parent;
    enum COLOR color;
} tree_node;

typedef struct red_black_tree   //Red Black Tree.
{
    tree_node *root;
    tree_node *NIL;
} red_black_tree;

tree_node *minimum(red_black_tree *t, tree_node *x); //Minimum node
tree_node *new_tree_node(int data);  //Initialize new node.
red_black_tree *new_red_black_tree();    //Initialize new Red-Black Tree.
void left_rotate(red_black_tree *t, tree_node *x);
void right_rotate(red_black_tree *t, tree_node *x);
void insertion_fixup(red_black_tree *t, tree_node *z);
void insert(red_black_tree *t, int val);
void rb_transplant(red_black_tree *t, tree_node *u, tree_node *v);
void rb_delete_fixup(red_black_tree *t, tree_node *x);
void rb_delete(red_black_tree *t, tree_node *z);
int search(red_black_tree *t, int val);
void inorder(red_black_tree *t, tree_node *n);
void postorder(red_black_tree *t, tree_node *n);
void preorder(red_black_tree *t, tree_node *n);
void delete (red_black_tree *t, int val);
