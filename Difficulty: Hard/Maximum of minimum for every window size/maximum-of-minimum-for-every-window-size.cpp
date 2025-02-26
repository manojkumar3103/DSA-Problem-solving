//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,0);
        vector<int>PG(n,-1);
        vector<int>NG(n,n);
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&& arr[i]<=arr[st.top()])
            {
                st.pop();
            }
            if(!st.empty())
            {
                PG[i]=st.top();
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[i]<=arr[st.top()])
            {
                st.pop();
            }
            if(!st.empty())
            {
                NG[i]=st.top();
            }
            st.push(i);
        }
        
        for(int i=0;i<n;i++)
        {
            int index=NG[i]-PG[i]-1;
            ans[index-1]=max(arr[i],ans[index-1]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            ans[i]=max(ans[i],ans[i+1]);
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
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends