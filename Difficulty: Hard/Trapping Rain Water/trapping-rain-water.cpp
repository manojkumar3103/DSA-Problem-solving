//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        vector<int> prefixsum;
        vector<int> suffixsum;
        
        int sum=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            sum=max(sum,arr[i]);
            prefixsum.push_back(sum);
        }
        
        sum=INT_MIN;
        for(int i=arr.size()-1;i>=0;i--)
        {
            sum=max(sum,arr[i]);
            suffixsum.push_back(sum);
        }
        reverse(suffixsum.begin(),suffixsum.end());
        int result=0;
        for(int i=0;i<prefixsum.size();i++)
        {
            result+=(min(prefixsum[i],suffixsum[i])-arr[i]);
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
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends