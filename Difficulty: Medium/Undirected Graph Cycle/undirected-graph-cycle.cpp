//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfsRecurr(int size,int src,vector<bool> &visited, vector<vector<int>>& edges,int parent)
    {
        visited[src]=true;
        for(auto val:edges[src])
        {
            if(visited[val]==false)
            {
                if(dfsRecurr(size,0,visited,edges,src))
                    return true;
            }
            else if(val!=parent)
                return true;
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<bool> visited(V,false);
        return dfsRecurr(V,0,visited,edges,-1);
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
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends