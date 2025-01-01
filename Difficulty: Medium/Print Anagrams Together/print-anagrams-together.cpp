//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        vector<pair<string,string>> hash_map;
        vector<vector<string>> ans;
        
        for(int i=0;i<arr.size();i++)
        {
            string temp = arr[i];
            string sorted_temp = temp; 
            sort(sorted_temp.begin(), sorted_temp.end());
            hash_map.push_back({sorted_temp, temp});
        }
        
        unordered_map<string, vector<string>> anagram_groups;
        for (const auto& p : hash_map) {
            anagram_groups[p.first].push_back(p.second);
        }

        for (const auto& group : anagram_groups) {
            ans.push_back(group.second);
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

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends