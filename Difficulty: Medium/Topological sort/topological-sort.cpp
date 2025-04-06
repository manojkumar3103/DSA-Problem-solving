//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
    
        vector<vector<int>> adj_mat(V);
        vector<int> indegree(V,0);
        for(int i=0;i<edges.size();i++)
        {
            adj_mat[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            int temp=q.front();
            ans.push_back(temp);
            q.pop();
            
            for(auto it: adj_mat[temp])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(V, res, adj);
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