//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        unordered_map<char,int> lastIndex;
        
        for(int i=0;i<s.length();i++)
        {
            lastIndex[s[i]]=i;
        }
        
        int partitions = 0;
        int end = -1, maxEnd = -1;
    
        for (int i = 0; i < s.length(); i++) {
            maxEnd = max(maxEnd, lastIndex[s[i]]);
            if (i == maxEnd) {  
                partitions++;
                maxEnd = -1;
            }
        }
        return partitions;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends