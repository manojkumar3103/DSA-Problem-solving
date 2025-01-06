//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        vector<int> ans;
        sort(arr.begin(),arr.end());
        int start=0,end=arr.size()-1,diff=INT_MAX;
        while(start<end)
        {
            int sum=arr[start]+arr[end];
            if(sum==target)
            {
                return {arr[start], arr[end]};
            }
            if(abs(target-sum)<diff)
            {
                diff=abs(target-sum);
                ans={arr[start], arr[end]};
            }
                
            if (sum<target)
                start++;
            else
                end--;
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
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends