

// User function Template for C++

// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    unordered_map<Node*,int> hashmap;
    int getMaxSum(Node *root) 
    {
        if(root==NULL) return 0;
        
        if(hashmap[root]) return hashmap[root];
        
        int withnode=root->data;
        if(root->left)
        {
        withnode+= getMaxSum(root->left->left);
        withnode+= getMaxSum(root->left->right);
        }
        if(root->right)
        {
        withnode+= getMaxSum(root->right->left);
        withnode+= getMaxSum(root->right->right);
        }
        
        int withoutnode=getMaxSum(root->left)+getMaxSum(root->right);
        
        hashmap[root]=max(withnode,withoutnode);
        return hashmap[root];
    }
};


