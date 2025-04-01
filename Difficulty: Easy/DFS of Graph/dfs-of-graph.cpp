//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfsRecurr(vector<vector<int>>& adj, int src, vector<bool>& visited,vector<int>& ans)
    {
        //if(src==adj.size()) return;
        visited[src]=true;
        ans.push_back(src);
        for(auto val: adj[src])
        {
            if(!visited[val])
                dfsRecurr(adj,val,visited,ans);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
       vector<bool> visited(adj.size(),false);
       vector<int> ans;
       dfsRecurr(adj,0,visited,ans);
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends