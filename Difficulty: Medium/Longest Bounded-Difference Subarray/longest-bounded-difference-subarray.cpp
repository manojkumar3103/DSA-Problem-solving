//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        deque<int> max_dq;
        deque<int> min_dq;
        vector<int> ans;
        int max_length=0,start=0,final_start=0;
        
        for(int i=0;i<arr.size();i++)
        {
            while(!max_dq.empty() && arr[i]>=arr[max_dq.back()])
            {
                max_dq.pop_back();
            }
            
            while(!min_dq.empty() && arr[i]<=arr[min_dq.back()])
            {
                min_dq.pop_back();
            }
            
            max_dq.push_back(i);
            min_dq.push_back(i);
            
            while((arr[max_dq.front()]-arr[min_dq.front()])>x)
            {
                start++;
                if(max_dq.front()<start) max_dq.pop_front();
                if(min_dq.front()<start) min_dq.pop_front();
            }
            
            if(i-start+1 > max_length)
            {
                final_start=start;
                max_length=i-start+1;
            }
        }
        
        for(int i=final_start;i<final_start+max_length;i++)
        {
            ans.push_back(arr[i]);
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
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends