//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int stock_buy_sell(vector<int> &prices,int i, int profit,int trans_count)
    {
        if(trans_count==4 || i==prices.size())
            return profit;
        
        if(trans_count%2==0)
        {
            return max(stock_buy_sell(prices,i+1,profit-prices[i],trans_count+1),
            stock_buy_sell(prices,i+1,profit,trans_count));
        }
        else
        {
            return max(stock_buy_sell(prices,i+1,profit+prices[i],trans_count+1),
            stock_buy_sell(prices,i+1,profit,trans_count));
        }
        
    }
    int maxProfit(vector<int> &prices) {
        // code here
        //return stock_buy_sell(prices,0,0,0);
        int n=prices.size();
        int k=2;
        vector<vector<int>>curr (k+1,vector<int>(2,0));
        vector<vector<int>>after (k+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=k;j>=1;j--)
            {
                curr[j][0]=max(-prices[i] +after[j][1],after[j][0]);
                if(j>0)
                    curr[j][1]=max(prices[i]+after[j-1][0],after[j][1]);
                else
                    curr[j][1]=max(prices[i],after[j][1]);
            }
            after=curr;
        }
       //int res = stock_buy_sell(prices,0,k,0,0); 
       //return res;
       return after[k][0];
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends