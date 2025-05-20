//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int bfs_maxlen(unordered_map<Node*,Node*>& map, Node* target_node)
    {
        int res=0;
        unordered_map<Node*,int> vis;
        queue<Node*> q;
        q.push(target_node);
        vis[target_node]=1;
        
        while(!q.empty())
        {
            int size=q.size(); int fl=0;
            for(int i=0;i<size;i++)
            {
                Node* temp=q.front();
                q.pop();
                
                if(temp->left && !vis[temp->left])
                {
                    fl=1;
                    q.push(temp->left);
                    vis[temp->left]=1;
                }
                
                if(temp->right && !vis[temp->right])
                {
                    fl=1;
                    q.push(temp->right);
                    vis[temp->right]=1;
                }
                
                if(map[temp] && !vis[map[temp]])
                {
                    fl=1;
                    q.push(map[temp]);
                    vis[map[temp]]=1;
                }
            }
            if(fl) res++;
        }
        return res;
    }
    Node* parentMapper(unordered_map<Node*,Node*>& map, int target, Node* root)
    {
        Node* res=NULL;
        if(root->data == target) res= root;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            if(curr->data == target) res= curr;
            if(curr->left)
            {
                map[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                map[curr->right]=curr;
                q.push(curr->right);
            }
        }
        return res;
    }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*> parent_map;
        Node* target_node = parentMapper(parent_map,target,root);
        int res = bfs_maxlen(parent_map,target_node);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends