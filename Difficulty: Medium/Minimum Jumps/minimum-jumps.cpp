//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        
        int n=arr.size();
        int dp[n];
        dp[0]=0;
        
        for(int i=1;i<n;i++)
            dp[i]=INT_MAX;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(j+arr[j]>=i && dp[j]!=INT_MAX)
                {
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
        return (dp[n-1] ==INT_MAX)?-1:dp[n-1];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends