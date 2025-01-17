//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int product=1,n=arr.size();
        int zero_count=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=0)
                product*=arr[i];
            else
                zero_count++;
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=0 && zero_count==0)
                ans[i]=product/arr[i];
            else if (arr[i]==0 && zero_count==1)
                ans[i]=product;
            else
                ans[i]=0;
        }
        return ans;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends