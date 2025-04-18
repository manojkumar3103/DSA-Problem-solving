//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Trie {
  public:
    vector<Trie*> arr;
    bool end;
    Trie() {
        arr.resize(26,NULL);
        end=false;
    }

    void insert(string &word) {
        Trie* root=this;
        for(auto ch: word)
        {
            ch = ch -'a';
            if(!root->arr[ch])
            {
                root->arr[ch]=new Trie();
            }
            root=root->arr[ch];
        }
        root->end=true;
    }

    bool search(string &word) {
        Trie* root=this;
        for(auto ch: word)
        {
            ch = ch -'a';
            if(!root->arr[ch])
            {
                return false;
            }
            root=root->arr[ch];
        }
        return root->end;
    }

    bool isPrefix(string &word) {
        Trie* root=this;
        for(auto ch: word)
        {
            ch = ch -'a';
            if(!root->arr[ch])
            {
                return false;
            }
            root=root->arr[ch];
        }
        return true;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends