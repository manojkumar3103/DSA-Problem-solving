//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
       
       sort(arr.begin(),arr.end());
       int n=arr.size();
       int i=0,j=n-1;
       long long int sum=0;
       int k=0;
       while(i<j)
       {
           sum+=abs(arr[j]-arr[i]);
           if(k%2==0)
           {
               i++;
           }
           else
           {
               j--;
           }
           k++;
       }
       sum+=arr[j]-arr[0];
       return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends