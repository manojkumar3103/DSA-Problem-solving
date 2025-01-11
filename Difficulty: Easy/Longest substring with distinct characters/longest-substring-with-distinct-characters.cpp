//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &S) {
        vector<int> prev(128,-1);
        int j=0,n=S.length(),i=0;
        int result=0;
        while(j<n)
        {
             i=max(i,prev[S[j]]+1);
             int max_end=j-i+1;
             result=max(result,max_end);
             prev[S[j]]=j;
             j++;
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends