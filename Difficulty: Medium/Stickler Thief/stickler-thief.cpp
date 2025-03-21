//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int alternate_house(vector<int>& arr,int i,vector<int>& dp)
    {
        if(i>=arr.size())
            return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(arr[i]+alternate_house(arr,i+2,dp),
        alternate_house(arr,i+1,dp));
    }
    int findMaxSum(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return alternate_house(arr,0,dp);
        /*int n=arr.size();
        
        dp[0]=arr[0];dp[1]=arr[1];
        for(int i=2;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i]= max(arr[i]+dp[i-2],arr[i-1]);
            }
        }
        return dp[n-1];*/
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
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends