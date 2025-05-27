typedef struct Node{
    int data;
    Node* left,*right;
    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
} Node;

class Solution {
  public:
    Node* buildTree(vector<int>& preorder,int UP,int LOW,int& i)
    {
        if(preorder[i]<LOW || preorder[i]>UP || i>=preorder.size())
            return NULL;
        Node* root=new Node(preorder[i++]);
        root->left=buildTree(preorder,root->data,LOW,i);
        root->right=buildTree(preorder,UP,root->data,i);
        return root;
    }
    void traversal(vector<int>& ans,Node* root)
    {
        if(!root) return;
        if(!root->left && !root->right)
        {
            ans.push_back(root->data);
            return;
        }
        traversal(ans,root->left);
        traversal(ans,root->right);
    }
    vector<int> leafNodes(vector<int>& preorder) {
        if(preorder.size()==0) return {};
        int i=0;
        Node* root = buildTree(preorder,INT_MAX,INT_MIN,i);
        vector<int> ans;
        traversal(ans,root);
        return ans;
    }
};