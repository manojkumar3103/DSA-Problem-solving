//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  public:
    
    void minHeapify(vector<int>& arr,int i,int n)
    {
        int ln=2*i+1,rn=2*i+2,smallest=i;
        if(ln<n && arr[ln]<arr[i])
            smallest=ln;
        if(rn<n && arr[rn]<arr[smallest])
            smallest=rn;
        if(smallest!=i)
        {
            swap(arr[i],arr[smallest]);
            minHeapify(arr,smallest,n);
        }
    }
    void buildHeap(vector<int>& arr)
    {
        int n=arr.size();
        for(int i=(n-2)/2;i>=0;i--)
            minHeapify(arr,i,n);
    }
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        buildHeap(arr);
        int n=arr.size();
        for(int i=n-1;i>=1;i--)
        {
            swap(arr[i],arr[0]);
            minHeapify(arr,0,i);
        }
        reverse(arr.begin(),arr.end());
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.heapSort(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends