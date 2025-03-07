//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int longestPalinSubseq(string &s) {
      int n=s.length();
      vector<vector<int>> dp(n,vector<int>(n,0));
      
      for(int i=0;i<n;i++)
      {
          dp[i][i]=1;
      }
      
      for(int i=n-2;i>=0;i--)
      {
          for(int j=i+1;j<n;j++)
          {
              if(s[i]==s[j])
              {
                  dp[i][j]=dp[i+1][j-1]+2;
              }
              else
              {
                  dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
              }
          }
      }
    //   for(int i=0;i<n;i++)
    //   {
    //     for(int j=0;j<n;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    //   }
        return dp[0][n-1];      
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends