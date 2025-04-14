//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& adj_mat) {
    
        vector<int> indegree(V,0);
        queue<int> q;
        
        for (int i = 0; i < V; i++) {
        for (int neighbor : adj_mat[i]) {
            indegree[neighbor]++;
        }
    }

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
        vector<int> ans;
        while(!q.empty())
        {
            int temp=q.front();
            ans.push_back(temp);
            q.pop();
            
            for(auto it: adj_mat[temp])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if(ans.size()!=V) return {};
        return ans;
    }
    string findOrder(vector<string> &words) {
        // code here
       unordered_set<char> unique_chars;
        for (string word : words) {
            for (char c : word)
                unique_chars.insert(c);
        }

        int V = unique_chars.size();
        unordered_map<char, int> char_to_index;
        unordered_map<int, char> index_to_char;

        int idx = 0;
        for (char c : unique_chars) {
            char_to_index[c] = idx;
            index_to_char[idx] = c;
            idx++;
        }

        vector<vector<int>> adj(V);
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.length(), w2.length());
            bool found_diff = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[char_to_index[w1[j]]].push_back(char_to_index[w2[j]]);
                    found_diff = true;
                    break;
                }
            }

            // Invalid case: prefix problem
            if (!found_diff && w1.length() > w2.length())
                return "";
        }

        vector<int> topo = topoSort(V, adj);
        if (topo.empty()) return "";

        string result = "";
        for (int i : topo) {
            result += index_to_char[i];
        }
        //cout<<result<<endl;
        return result;
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends