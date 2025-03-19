//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int stock_buy_sell(vector<int>& prices,int profit, int k, int i, int trans_count)
    {
        if(trans_count==2*k || i==prices.size())
        {
            return profit;;
        }
        if(trans_count%2==0)
        {
            return max(stock_buy_sell(prices,profit -prices[i],k,i+1,trans_count+1),
            stock_buy_sell(prices,profit,k,i+1,trans_count));
        }
        else
        {
            return max(stock_buy_sell(prices,profit+prices[i],k,i+1,trans_count+1),
            stock_buy_sell(prices,profit,k,i+1,trans_count));
        }

    }
    int maxProfit(vector<int>& prices, int k) {
        int n=prices.size();
        if (n == 0) return 0;
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
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends