//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n = arr.size();

    // Build a min-heap for the first k+1 elements
    for (int i = 0; i <= k && i < n; i++) {
        minHeap.push(arr[i]);
    }

    int index = 0;
    for (int i = k + 1; i < n; i++) {
        arr[index++] = minHeap.top();
        minHeap.pop();
        minHeap.push(arr[i]);
    }

    // Extract the remaining elements from the heap
    while (!minHeap.empty()) {
        arr[index++] = minHeap.top();
        minHeap.pop();
    }
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
        Solution obj;
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends