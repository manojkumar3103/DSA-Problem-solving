//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        unordered_map<char, int> freq;
        int left = 0, minLen = str.length();
        int uniqueChars = unordered_set<char>(str.begin(), str.end()).size();
        int count = 0;

        for (int right = 0; right < str.length(); right++) {
            freq[str[right]]++;

            if (freq[str[right]] == 1) count++;

            while (count == uniqueChars) {
                minLen = min(minLen, right - left + 1);
                freq[str[left]]--;
                if (freq[str[left]] == 0) count--;
                left++;
            }
        }

        return minLen;
    }
};



//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends