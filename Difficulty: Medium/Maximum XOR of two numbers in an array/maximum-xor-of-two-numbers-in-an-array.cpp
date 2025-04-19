//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int maxXor(vector<int> &arr) {
        int mask=0, max=0;
        
        for(int i=31;i>=0;i--)
        {
            mask=mask|(1<<i);
            unordered_set<int> hashset;
            for(int i: arr)
            {
                hashset.insert(mask&i);
            }
        
        int tmp=max|(1<<i);
        
        for(int prefix : hashset)
        {
            if(hashset.find(tmp^prefix)!=hashset.end())
            {
                max=tmp;
                break;
            }
        }
        }
        return max;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends