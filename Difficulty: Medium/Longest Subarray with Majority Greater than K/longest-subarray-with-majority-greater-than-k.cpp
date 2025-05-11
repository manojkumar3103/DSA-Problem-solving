//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
           int n = arr.size();
        vector<int> transformed(n);

    // Step 1: Transform the array
    for (int i = 0; i < n; ++i) {
        transformed[i] = (arr[i] > k) ? 1 : -1;
    }

    // Step 2: Find longest subarray with positive sum
    unordered_map<int, int> first_occurrence;
    int sum = 0, max_len = 0;

    for (int i = 0; i < n; ++i) {
        sum += transformed[i];

        // Case 1: sum > 0, subarray from 0 to i is valid
        if (sum > 0) {
            max_len = i + 1;
        }

        // Case 2: sum <= 0, try to find a prefix sum that makes it positive
        if (first_occurrence.find(sum - 1) != first_occurrence.end()) {
            max_len = max(max_len, i - first_occurrence[sum - 1]);
        }

        // Store the first occurrence of current sum
        if (first_occurrence.find(sum) == first_occurrence.end()) {
            first_occurrence[sum] = i;
        }
    }

    return max_len;
        
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
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends