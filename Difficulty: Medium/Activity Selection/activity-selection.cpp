//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n=start.size(),m=finish.size();
        //sort(start.begin(),start.end());
        //sort(finish.begin(),finish.end());
        vector<pair<int,int>> volatile_arr;
        
        for(int i=0;i<n;i++)
        {
            volatile_arr.push_back({finish[i],start[i]});
        }
        sort(volatile_arr.begin(),volatile_arr.end());
        int result=1;
        int last_finish=volatile_arr[0].first ;
        
        for(int i=1;i<n;i++)
        {
            if(volatile_arr[i].second > last_finish)
            {
                result++;
                last_finish=volatile_arr[i].first;
            }
        }
        return result;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends