//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
       stack<string> st;
       stack<int> numst;
       string s1="";
       int num=0;
       for(int i=0;i<s.length();i++)
       {
           if(isdigit(s[i]))
           {
               num=num*10+(s[i]-'0');
           }
           else if(s[i]=='[')
           {
               numst.push(num);
               num=0;
               st.push(s1);
               s1="";
           }
           else if(s[i]==']')
           {
               string temp=s1;
               s1=st.top();
               st.pop();
               int rep=numst.top();
               numst.pop();
               for(int i=0;i<rep;i++)
               {
                   s1+=temp;
               }
           }
           else
           {
               s1+=s[i];
           }
       }
       return s1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends