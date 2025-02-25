//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        stack<int> st;
        int ans=0,n=arr.size();
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty() && arr[i]<=arr[st.top()])
            {
                int t=st.top();st.pop();
                int val=arr[t]*(st.empty()?i:(i-st.top()-1));
                ans=max(ans,val);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int t=st.top();st.pop();
            int val=arr[t]*(st.empty()?n:(n-st.top()-1));
            ans=max(ans,val);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends