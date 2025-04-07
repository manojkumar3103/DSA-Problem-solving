//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(vector<vector<int>>& adj_mat,vector<bool>& visited,vector<bool>& re_st,int src)
    {
        visited[src]=true;
        re_st[src]=true;
        
        for(auto it:adj_mat[src])
        {
            if(!visited[it] && dfs(adj_mat,visited,re_st,it))
                return true;
            else if (re_st[it])
                return true;
        }
        re_st[src]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<bool> visited(V,false);
        vector<bool> recursion_st(V,false);
        vector<vector<int>> adj_mat(V);
        
        for(int i=0;i<edges.size();i++)
        {
            adj_mat[edges[i][0]].push_back(edges[i][1]);
        }
        
        for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(adj_mat, visited, recursion_st, i))
                return true;
        }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends