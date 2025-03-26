//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  //(vec[i].find(target) != string::npos)
     bool wordBreakRec(int i,string &s, vector<string> &dictionary)
     {
        //if(ans==dictionary.size()) return true;
       if (i == s.length())
        return true;
    
        int n = s.length();
        string prefix = "";
    
        for (int j = i; j < n; j++)
        {
            prefix += s[j];
            if (find(dictionary.begin(), dictionary.end(), prefix) != dictionary.end() &&
                wordBreakRec(j + 1, s, dictionary))
            {
                return true;
            }
        }
    
        return false;
     }
    bool wordBreak(string &s, vector<string> &dictionary) {

        int n = s.size();
        vector<bool> dp(n + 1, 0);
        dp[0] = 1;
    
        for (int i = 1; i <= n; i++)
        {
            for (string &w : dictionary)
            {
                int start = i - w.size();
                if (start >= 0 && dp[start] && s.substr(start, w.size()) == w)
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends