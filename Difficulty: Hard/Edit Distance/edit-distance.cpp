
class Solution {
  public:
    // Function to compute the edit distance between two strings
    int f(string& s1, string& s2,vector<vector<int>> &dp,int i,int j)
    {
        if(i==0) return j;
        if(j==0) return i;
        
        if(dp[i][j] > -1) return dp[i][j];
        if(s1[i-1]==s2[j-1])
        {
             return dp[i][j]=f(s1,s2,dp,i-1,j-1);
        }
        else
        {
            return dp[i][j]=1+min(min(f(s1,s2,dp,i-1,j),f(s1,s2,dp,i,j-1)),f(s1,s2,dp,i-1,j-1));
        }
    }
    int editDistance(string& s1, string& s2) {
        int n=s1.length(),m=s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(s1,s2,dp,n,m);
        
    }
};

