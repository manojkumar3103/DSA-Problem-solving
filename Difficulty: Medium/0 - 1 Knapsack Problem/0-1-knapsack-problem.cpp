//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(wt.size(),vector<int>(W+1,0));
        
        for(int j=0;j<=W;j++)
        {
            if(wt[0]<=j)
            {
                dp[0][j]=val[0];
            }
        }
        
        for(int i=1;i<wt.size();i++)
        {
            for(int j=1;j<=W;j++)
            {
                int includingWT=0;
                
                if(wt[i]<=j)
                {
                    includingWT=val[i]+dp[i-1][j-wt[i]];
                }
                dp[i][j]=max(includingWT,dp[i-1][j]);
            }
        }
        /*
        for(int i=0;i<wt.size();i++)
        {
            for(int j=0;j<=W;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        return dp[wt.size()-1][W];
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends