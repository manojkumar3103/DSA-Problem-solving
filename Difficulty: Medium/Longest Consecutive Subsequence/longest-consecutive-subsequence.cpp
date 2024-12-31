//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> hashset;
        
        int result=0,maxi=INT_MIN;
        
        for(auto& i:arr)
        {
            hashset.insert(i);
            maxi=max(maxi,i);
        }
        for(auto& i:arr)
        {
            if(hashset.find(i-1)==hashset.end())
            {
                int temp=1;
                for(int j=i+1; j<=maxi;j++)
                {
                    if(hashset.find(j)==hashset.end())
                        break;
                    
                    temp++;
                }
                result=max(result,temp);
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
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends