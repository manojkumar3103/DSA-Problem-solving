class Solution {
  public:
    int bfs(vector<vector<int>>& adj_mat, int src, int dest)
    {
        queue<int> q;
        q.push(src);
        int ans=0;
        
        while(!q.empty())
        {
            int curr=q.front();q.pop();
            for(auto i:adj_mat[curr])
            {
                if(i==dest) ans++;
                q.push(i);
            }
        }
        
        return ans;
    }
    
    int countPathsUtil(int node, int dest, vector<vector<int>>& adj, vector<int>& dp) {
        if (node == dest) return 1; 
        if (dp[node] != -1) return dp[node]; 

        int count = 0;
        for (int next : adj[node]) {
            count += countPathsUtil(next, dest, adj, dp);
        }

        return dp[node] = count;
    }
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int>> adj_mat(V);
        for(auto edge : edges)
        {
            adj_mat[edge[0]].push_back(edge[1]);
        }
        vector<int> dp(V,-1);
        int ans = countPathsUtil(src,dest,adj_mat,dp);
        //int ans= bfs(adj_mat,src,dest);
        return ans;
    }
};