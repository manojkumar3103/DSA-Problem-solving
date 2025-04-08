//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
        int timer=1;
  public:
    bool dfs(int V, vector<vector<int>> &connectors, int node,int parent,int c, int d,
    vector<int>& tin,vector<int>& low,vector<int>& vis)
    {
        tin[node]=low[node]=timer;
        timer++;
        bool found=false;
        vis[node]=1;
        for(auto it: connectors[node])
        {
            if(it==parent) continue;
            
            if(vis[it]==0)
            {
                if (dfs(V, connectors, it, node, c, d, tin, low, vis))
                    found = true;
                low[node]=min(low[node],low[it]);
                
                if((low[it] > tin[node]) && ((node == c && it == d) || (node == d && it == c)))
                    return true;
            }
            else
            {
                low[node]=min(low[node],low[it]);
            }
        }
        return found;
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> connectors(V);
        
        vector<int> vis(V,0);
        vector<int> tin(V,-1);
        vector<int> low(V,-1);
        
        for(int i=0;i<edges.size();i++)
        {
            connectors[edges[i][0]].push_back(edges[i][1]);
            connectors[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(V, connectors, i, -1, c, d, tin, low, vis))
                    return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends