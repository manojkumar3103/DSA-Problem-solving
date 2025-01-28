//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void perm(string s,unordered_set<string>&hashset,int i)
    {
        if(i==s.size())
        {
            hashset.insert(s);
            return;
        }
        
        for(int k=i;k<s.size();k++)
        {
            swap(s[i],s[k]);
            perm(s,hashset,i+1);
            swap(s[i],s[k]);
        }
    }
    vector<string> findPermutation(string &s) {
      unordered_set<string> hashset;
      perm(s,hashset,0);
      vector<string> ans(hashset.begin(),hashset.end());
      return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends