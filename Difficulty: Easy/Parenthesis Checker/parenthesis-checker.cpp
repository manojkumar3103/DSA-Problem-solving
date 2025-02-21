//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isMatching(char ch1, char ch2)
    {
        if(ch1 == ')' && ch2 == '(')
            return true;
        else if(ch1 == '}' && ch2 == '{')
            return true;
        else if (ch1 == ']' && ch2 == '[')
            return true;
        else
            return false;
    }
    
    bool isBalanced(string& s) {
        stack<char> st;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if(st.empty()) return false;
                if(isMatching(s[i],st.top()))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                st.push(s[i]);
            }
            
        }
        //cout<<"hi"<<endl;
        if(!st.empty()) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends