//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends

//User function Template for C++
struct data {
    int value,vpos,apos;
    data(int val,int vp,int ap)
    {
        value=val;
        vpos=vp;
        apos=ap;
    }
};

struct mycomp{
bool operator()(const data& temp1,const data& temp2)
{
    return temp1.value>temp2.value;
}
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int>ans;
        priority_queue<data,vector<data>,mycomp> heap;
        for(int i=0;i<arr.size();i++)
        {
            heap.push(data(arr[i][0],0,i));
        }
        
        while(!heap.empty())
        {
            data temp=heap.top();
            heap.pop();
            ans.push_back(temp.value);
            if(temp.vpos+1<arr[temp.apos].size())
            {
                heap.push(data(arr[temp.apos][temp.vpos+1],temp.vpos+1,temp.apos));
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends