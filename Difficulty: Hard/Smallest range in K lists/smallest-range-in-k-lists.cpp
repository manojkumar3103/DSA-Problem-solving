//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Element {
    int value;
    int row;
    int col;
};

class Solution {
  public:
    struct min_val {
    bool operator()(Element a, Element b) {
        return a.value > b.value;
        }
    };
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        
        priority_queue<Element,vector<Element>,min_val> minHeap;
        int currentMax = INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            minHeap.push({arr[i][0],i,0});
            currentMax = max(currentMax, arr[i][0]);
        }
        
        int rangeStart = 0, rangeEnd = INT_MAX;
        while(true)
        {
            Element curr = minHeap.top();
            minHeap.pop();
    
            int currentMin = curr.value;
            if (currentMax - currentMin < rangeEnd - rangeStart) {
                rangeStart = currentMin;
                rangeEnd = currentMax;
            }
            
            if (curr.col + 1 < arr[curr.row].size()) {
            int nextVal = arr[curr.row][curr.col + 1];
            minHeap.push({nextVal, curr.row, curr.col + 1});
            currentMax = max(currentMax, nextVal);
            } else {
                break;
            }
        }
        return {rangeStart,rangeEnd};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends