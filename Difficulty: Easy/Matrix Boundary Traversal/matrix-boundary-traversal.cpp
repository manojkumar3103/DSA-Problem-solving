//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > arr) 
    {
        int n=arr.size(),m=arr[0].size();
        vector<int> ans;
        if(n==1)
        {
            for(int i=0;i<m;i++)
            {
                ans.push_back(arr[0][i]);
            }
        }
        else if (m==1)
        {
            for(int i=0;i<n;i++)
            {
                ans.push_back(arr[i][0]);
            }
        }
        else
        {
        
        int left=0, right=m-1,top=0,bottom=n-1;
        
        for(int i=top;i<=right;i++)
        {
            ans.push_back(arr[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++)
        {
            ans.push_back(arr[i][right]);
        }
        right--;
        for(int i=right;i>=left;i--)
        {
            ans.push_back(arr[bottom][i]);
        }
        bottom--;
        for(int i=bottom;i>=top;i--)
        {
            ans.push_back(arr[i][left]);
        }
        left++;
        return ans;
        }
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends