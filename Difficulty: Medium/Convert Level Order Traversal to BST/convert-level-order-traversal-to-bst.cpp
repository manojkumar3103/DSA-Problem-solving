//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    
cout << "~" << "\n";
}
	return 0; 
}
// } Driver Code Ends


//User function Template for C++


//Function to construct the BST from its given level order traversal.
Node* constructBst(int arr[], int n)
{
    queue<pair<Node*,pair<int,int>>> q;
    Node* root=new Node(arr[0]);
    q.push({root,{INT_MIN,INT_MAX}});
    
    for(int i=1;i<n;i++)
    {
        auto p=q.front();
        Node* curr=p.first;
        pair<int,int> range=p.second;
        if(arr[i]>range.first && arr[i]<range.second)
        {
            if(arr[i]<curr->data)
            {
                if(curr->left)
                {
                    q.pop();
                    i--;
                    continue;
                }
                //q.pop();
                curr->left=new Node(arr[i]);
                q.push({curr->left,{range.first,curr->data}});
            }
            else
            {
                q.pop();
                curr->right=new Node(arr[i]);
                q.push({curr->right,{curr->data,range.second}});
            }
        }
        else
        {
            q.pop();
            i--;
        }
    }
    return root;
}
