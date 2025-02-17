//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
       priority_queue<int,vector<int>,greater<int>> min_heap;
       
       for(int i=0;i<k;i++)
       {
        min_heap.push(arr[i]);
       }
       
       for(int i=k;i<arr.size();i++)
       {
           if(arr[i]>=min_heap.top())
           {
               min_heap.pop();
               min_heap.push(arr[i]);
           }
       }
       
       vector<int> ans(k,0);
       for(int i=k-1;i>=0;i--)
       {
           ans[i]=min_heap.top();
           min_heap.pop();
       }
       
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.kLargest(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends