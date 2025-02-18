//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static int distance(const vector<int>& a)
    {
        return (a[0]*a[0]+a[1]*a[1]);
    }
    struct compare
    {
        bool operator()(const vector<int>& a,const vector<int>& b)
        {
            return (distance(a)< distance(b));
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pt;
        
        for(int i=0;i<k;i++)
        {
            pt.push(points[i]);
        }
        for(int i=k;i<points.size();i++)
        {
           if(distance(pt.top())>distance(points[i]))
           {
               pt.pop();
               pt.push(points[i]);
           }
        }
        
        vector<vector<int>> ans;
        while (!pt.empty()) {
            ans.push_back(pt.top());
            pt.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends