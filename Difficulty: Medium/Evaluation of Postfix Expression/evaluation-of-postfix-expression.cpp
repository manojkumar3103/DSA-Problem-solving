//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> st;
        int ans;
        for(int i=0;i<arr.size();i++)
        {
            if(isdigit(arr[i][0]) || (arr[i].size() > 1 && arr[i][0] == '-'))
            {
                st.push(stoi(arr[i]));
            }
            else
            {
                int oper2=st.top();st.pop();
                int oper1=st.top();st.pop();
                switch (arr[i][0]){
                case '+':
                    st.push(oper1+oper2);
                    break;
                case '-':
                    st.push(oper1-oper2);
                    break;
                case '*':
                    st.push(oper1*oper2);
                    break;
                case '/':
                    if(oper2==0) break;
                    st.push(oper1/oper2);
                    //cout<<oper1<<" "<<oper2<<endl;
                    break;
                }
            }
            //cout<<st.top()<<endl;
        }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends