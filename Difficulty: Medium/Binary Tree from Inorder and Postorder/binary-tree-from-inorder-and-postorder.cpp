//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    
    Node* ctree(vector<int> inorder, vector<int> postorder,int is,int ie,int& post_index)
    {
        if(is>ie) return NULL;
        
        Node* root=new Node(postorder[post_index--]);
        int index;
        for(int i=is;i<=ie;i++)
        {
            if(inorder[i]==root->data)
            {
                index=i;
                break;
            }
        }
        root->right=ctree(inorder,postorder,index+1,ie,post_index);
        root->left=ctree(inorder,postorder,is,index-1,post_index);
        return root;
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        int post_index = postorder.size() - 1; 
        return ctree(inorder,postorder,0,inorder.size()-1,post_index);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> inorder;
        int number;
        while (ss >> number) {
            inorder.push_back(number);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> postorder;
        while (ss2 >> number) {
            postorder.push_back(number);
        }
        Solution obj;
        Node* root = obj.buildTree(inorder, postorder);
        preOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends