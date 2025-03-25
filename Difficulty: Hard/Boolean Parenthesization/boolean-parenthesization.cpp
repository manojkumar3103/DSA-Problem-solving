//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int recursion(string &s,int i, int j,int istrue,vector<vector<vector<int>>>& dp)
    {
        if(i>j) return 0;
        if(i==j)
        {
            if(istrue) return s[i]=='T';
            else return s[j]=='F';
        }
        if(dp[i][j][istrue]!=-1) return dp[i][j][istrue];
        int ways=0;
        for(int k=i+1;k<j;k+=2)
        {
            int lT=recursion(s,i,k-1,1,dp);
            int lF=recursion(s,i,k-1,0,dp);
            int rT=recursion(s,k+1,j,1,dp);
            int rF=recursion(s,k+1,j,0,dp);
            
            if(s[k]=='&')
            {
                if(istrue==1) 
                {
                    ways= ways + (lT * rT);
                }
                else
                {
                    ways= ways+ (lT*rF) + (rT*lF) + (rF*lF);
                }
            }
            else if(s[k]=='|')
            {
                if(istrue==1) 
                {
                    ways=ways + (lT*rF) + (rT*lF) + (lT * rT);
                }
                else
                {
                    ways = ways + (rF*lF);
                }
            }
            else
            {
                if(istrue==1) 
                {
                    ways=ways+ (lT*rF) + (lF*rT);
                }
                else
                {
                    ways=ways+(lF*rF) + (lT*rT);
                }
            }
        }
        return dp[i][j][istrue]=ways;
    }
    int countWays(string &s) {
        int n=s.length();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return recursion(s,0,n-1,1,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends