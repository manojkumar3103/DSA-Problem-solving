//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
       priority_queue<int,vector<int>,greater<int>> min_heap;
    	
    	for(int i=0;i<n;i++)
    	{
    	    min_heap.push(arr[i]);
    	    
    	    if(min_heap.size()>k)
    	        min_heap.pop();
    	    
    	    if(min_heap.size()<k)
    	    {
    	        cout<<-1<<" ";
    	    }
    	    else
    	    {
    	        cout<<min_heap.top()<<" ";
    	    }
    	}
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends