#include <iostream>

#include <iostream>

using namespace std;

typedef struct bin_tree_node {
  int v;
  struct bin_tree_node *left;
  struct bin_tree_node *right;
} BTNode;

BTNode *create_bin_tree_node(int v) {
  BTNode *p = new BTNode;

  if (p != NULL) {
    p->v = v;
    p->left = NULL;
    p->right = NULL;
  }

  return p;
}

void create_balanced_bin_tree(BTNode **root, int arr[], int start, int end) {
  if (start <= end) {
    int mid = (start + end + 1) / 2;

    *root = create_bin_tree_node(arr[mid]);
    create_balanced_bin_tree(&((*root)->left), arr, start, mid - 1);
    create_balanced_bin_tree(&((*root)->right), arr, mid + 1, end);
  }
}

void print_bin_tree(BTNode *root) {
  if (root != NULL) {
    cout << root->v << " ";
    print_bin_tree(root->left);
    print_bin_tree(root->right);
  }
}
void print_bin_tree1(BTNode *root) {
  if (root != NULL) {
    print_bin_tree1(root->left);
    cout << root->v << " ";
    print_bin_tree1(root->right);
  }
}

int main(int argc, char *argv[]) {
  int arr[30];
  for (int i = 0; i < 30; i++) {
    arr[i] = i;
  }
  BTNode *root = NULL;
  create_balanced_bin_tree(&root, arr, 0, 29);
  cout << "Preorder of balanced tree is: ";
  print_bin_tree(root);
  cout << "\nInorder of balanced tree is: ";
  print_bin_tree1(root);
  return 0;
}
