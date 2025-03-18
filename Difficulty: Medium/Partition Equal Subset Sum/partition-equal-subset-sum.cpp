//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    bool subset(vector<int>& arr, int sum)
    {
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        if(arr[0]<sum) dp[0][arr[0]]=true;
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j-arr[i]>=0 && dp[i-1][j-arr[i]])
                {
                    dp[i][j]=true;
                }
            }
        }
        return dp[n-1][sum];
    }
    bool equalPartition(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        if(sum%2==1) return false;
        return subset(arr,sum/2);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends