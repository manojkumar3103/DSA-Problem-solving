/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool inorderTraversal(Node* root,int min,int max)
    {
        if(!root) return false;
          if (!root->left && !root->right) {
            if (min == max) return true;
        }
        return inorderTraversal(root->left, min, root->data - 1) ||
               inorderTraversal(root->right, root->data + 1, max);
    }
    bool isDeadEnd(Node *root) {
        // Code here
        int prev_val=-1;
        return inorderTraversal(root,1,INT_MAX);
    }
};