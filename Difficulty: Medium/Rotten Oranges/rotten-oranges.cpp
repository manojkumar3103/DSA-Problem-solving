//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        
        queue<pair<int,int>> q;
        int n=mat.size(),m=mat[0].size();
        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==2)
                {
                    q.push({i,j});
                }
                if(mat[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        //cout<<fresh<<endl;
        if(fresh==0) return 0;
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        int count=0;
        while(!q.empty())
        {
            int size=q.size();
            int roten=0;
            for(int i=0;i<size;i++)
            {
                pair<int,int> temp=q.front();
                q.pop();
                
                for(int k=0;k<4;k++)
                {
                    int nrow=temp.first+row[k];
                    int ncol=temp.second+col[k];
                    if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && mat[nrow][ncol]==1)
                    {
                        mat[nrow][ncol]=2;
                        roten=1;
                        fresh--;
                        q.push({nrow,ncol});
                    }
                }
            }
            if(roten) count++;
            
        }
        //cout<<fresh<<endl;
        if(fresh!=0) return -1;
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
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends