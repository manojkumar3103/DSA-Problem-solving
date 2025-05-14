//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  string getNextTerm(const string& term) {
    string result;
    int count = 1;

    for (size_t i = 1; i <= term.size(); ++i) {
        if (i < term.size() && term[i] == term[i - 1]) {
            ++count;
        } else {
            result += to_string(count) + term[i - 1];
            count = 1;
        }
    }
    return result;
    }
    string countAndSay(int n) {

        string term="1";
        for(int i=1;i<n;i++)
        {
            term=getNextTerm(term);
        }
        return term;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends