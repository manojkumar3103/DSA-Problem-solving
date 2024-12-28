//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n=mat.size(),m=mat[0].size();
        unordered_set<int> store_i,store_j;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    store_i.insert(i);
                    store_j.insert(j);
                }
            }
        }

        for(auto &it : store_i)
        {
            for(int i=0;i<m;i++)
            {
                mat[it][i]=0;
            }
        }
        
        for(auto &it : store_j)
        {
            for(int i=0;i<n;i++)
            {
                mat[i][it]=0;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends