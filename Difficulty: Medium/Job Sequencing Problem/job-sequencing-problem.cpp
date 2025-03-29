//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;  // Sort by profit in descending order
    }

    // Custom find function for Disjoint Set (DSU)
    int findParent(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x], parent);  // Path compression
    }

    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        int n = deadline.size();
        vector<pair<int, int>> arr;
        int max_deadline = 0;

        for (int i = 0; i < n; i++) {
            arr.push_back({profit[i], deadline[i]});
            max_deadline = max(max_deadline, deadline[i]);
        }

        sort(arr.begin(), arr.end(), comp);  // Sort jobs by profit

        vector<int> parent(max_deadline + 1);
        for (int i = 0; i <= max_deadline; i++) parent[i] = i;  // Initialize DSU
        
        int jobs = 0, total_profit = 0;

        for (int i = 0; i < n; i++) {
            int d = arr[i].second;
            int available_slot = findParent(d, parent);  // Use custom find function
            
            if (available_slot > 0) {
                parent[available_slot] = findParent(available_slot - 1, parent);  // Merge sets
                jobs++;
                total_profit += arr[i].first;
            }
        }

        return {jobs, total_profit};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends