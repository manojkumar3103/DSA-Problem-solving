//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int recursion_memo(string& s1, string& s2, int n,int m,vector<vector<int>>& dp,int & result)
    {
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s1[n-1]==s2[m-1])
        {
            dp[n][m]=1+recursion_memo(s1,s2,n-1,m-1,dp,result);
            result = max(result, dp[n][m]);
        }
        else
            dp[n][m]=0;
            recursion_memo(s1,s2,n-1,m,dp,result);
            recursion_memo(s1,s2,n,m-1,dp,result);
        return dp[n][m];
    }
    int longestCommonSubstr(string& s1, string& s2) {
        int n=s1.length(),m=s2.length();
        int result=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        recursion_memo(s1,s2,n,m,dp,result);
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends