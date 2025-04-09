//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int timer=1;
  public:
  
    void dfs(int V,int node, int parent, vector<vector<int>>& connectors,
      vector<int>& tin,vector<int>& low,vector<bool>& visited, vector<int>& mark)
     {
          low[node]=tin[node]=timer++;
          visited[node]=true;
          int child=0;
          for(auto it: connectors[node])
          {
              if(it==parent) continue;
              
              if(!visited[it])
              {
                  dfs(V,it,node,connectors,tin,low,visited,mark);
                  
                  low[node]=min(low[it],low[node]);
                  
                  if(low[it]>=tin[node] && parent!=-1)
                  {
                      //cout<<"pushing "<<it<<" "<<parent<<endl;
                      mark[node]=1;
                  }
                  child++;
              }
              else
              {
                  low[node]=min(low[node],tin[it]);
              }
              
              if(child>1 && parent==-1)
              {
                  mark[node]=1;
              }
          }
     }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<bool> visited(V,false);
        vector<vector<int>> connectors(V);
        vector<int> tin(V,-1);
        vector<int> low(V,-1);
        vector<int> mark(V,0);
        for(int i=0;i<edges.size();i++)
        {
            connectors[edges[i][0]].push_back(edges[i][1]);
            connectors[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(V,i,-1,connectors,tin,low,visited,mark);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(mark[i]==1)
                ans.push_back(i);
        }
        
        return (ans.size()==0)?vector<int>{-1}:ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends