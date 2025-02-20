//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void balance(priority_queue<int> &max_heap, priority_queue<int,vector<int>,greater<int>> &min_heap)
    {
        if(max_heap.size()>min_heap.size()+1)
        {
            int top=max_heap.top();
            max_heap.pop();
            min_heap.push(top);
        }
        else if (min_heap.size()>max_heap.size())
        {
            int top=min_heap.top();
            min_heap.pop();
            max_heap.push(top);
        }
    }
    vector<double> getMedian(vector<int> &arr) {
        vector<double> ans;
        priority_queue<int> max_heap;
        priority_queue<int,vector<int>,greater<int>> min_heap;
        max_heap.push(arr[0]);
        ans.push_back(double(arr[0]));
        for(int i=1;i<arr.size();i++)
        {
            if(max_heap.empty() || max_heap.top()>arr[i])
            {
                max_heap.push(arr[i]);
            }
            else
            {
                min_heap.push(arr[i]);
            }
        balance(max_heap,min_heap);
        if(i%2==1)
        {
            ans.push_back((max_heap.top()+min_heap.top())/2.0);
        }
        else
        {
            ans.push_back(max_heap.top()/1.0);
        }
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

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends