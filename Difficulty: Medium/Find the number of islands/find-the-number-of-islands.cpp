//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void bfs(pair<int,int>temp,vector<vector<bool>>& bool_mat,vector<vector<char>>& grid)
    {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        q.push(temp);
       int row[8]={0,0,1,1,1,-1,-1,-1};
       int col[8]={-1,1,-1,0,1,-1,0,1};
       int count=0;
       while(!q.empty())
       {
           pair<int,int> temp;
           temp=q.front();q.pop();
           bool_mat[temp.first][temp.second]=true;
           for(int i=0;i<8;i++)
           {
               int nrow=temp.first+row[i];
               int ncol=temp.second+col[i];
               
               if(nrow<n && nrow>=0 && ncol<m && ncol>=0 &&
               grid[nrow][ncol]=='L'&& bool_mat[nrow][ncol]==false)
               {
                   bool_mat[nrow][ncol]=true;
                   q.push({nrow,ncol});
               }
           }
       }
    }
    int countIslands(vector<vector<char>>& grid) {
       int n=grid.size(),m=grid[0].size();
       
       vector<vector<bool>> bool_mat(n,vector<bool>(m,false));
       int count=0;
       
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]=='L' && !bool_mat[i][j])
               {
                   count++;
                   bfs({i,j},bool_mat,grid);
               }
           }
       }
       
       return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends