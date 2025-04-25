//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMajority(vector<int>& arr)
    {
        int res=0,count=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[res]==arr[i])
            {
                count++;
            }
            else
            {
                count--;
            }
            
            if(count==0)
            {
                res=i; count=1;
            }
        }
        return res;
    }
    int majorityElement(vector<int>& arr) {
        // code here
        int cond=arr.size()/2;
        int is_major=findMajority(arr);
        
        int count_occu=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==arr[is_major])
                count_occu++;
        }
        
        return (count_occu > cond)?arr[is_major]:-1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends