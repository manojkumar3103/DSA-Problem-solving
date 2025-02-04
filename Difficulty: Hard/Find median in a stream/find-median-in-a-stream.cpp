//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> g;
    priority_queue<int,vector<int>,greater<int>> smaller;
    void insertHeap(int &x)
    {
        if(g.empty() || x<g.top())
        {
            g.push(x);
        }
        else
        {
            smaller.push(x);
        }
        balanceHeap();
    }
    void balanceHeap()
    {
        if(g.size()>smaller.size()+1)
        {
            smaller.push(g.top());
            g.pop();
        }
        if(g.size()<smaller.size())
        {
            g.push(smaller.top());
            smaller.pop();
        }
    }
    //Function to return Median.
    double getMedian()
    {
        if(g.size()>smaller.size())
         return g.top();
         else
         return (g.top()+smaller.top())/2.0;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends