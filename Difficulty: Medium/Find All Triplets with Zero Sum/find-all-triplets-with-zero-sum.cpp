//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
      set<vector<int>> ans;
      unordered_map<int,vector<pair<int,int>>> hashset;
      int n=arr.size();
      
      for(int i=0;i<n;i++)
      {
         for(int j=i+1;j<n;j++)
         {
             hashset[arr[i]+arr[j]].push_back({i,j});
         }
      }
      
      for(int i=0;i<n;i++)
      {
          int tar=-arr[i];
          if(hashset.find(tar)!=hashset.end())
          {
              for(auto &it : hashset[tar])
              {
                  if(it.first!=i && it.second!=i)
                  {
                      vector<int> curr={i,it.first,it.second};
                      sort(curr.begin(),curr.end());
                      ans.insert(curr);
                  }
              }
          }
      }
      
       vector<vector<int>>out(ans.begin(),ans.end());
       return out;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends