//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &arr) {
        int r=arr.size(), c=arr[0].size();
        int top=0, left=0, bottom=r-1, right=c-1;
        //cout<<bottom<<" "<<right<<endl;
        vector<int> ans;
        while(left<=right && top<=bottom)
        {
            for(int i=left;i<=right;i++)
                ans.push_back(arr[top][i]);
            top++;
            for(int i=top;i<=bottom;i++)
                ans.push_back(arr[i][right]);
            right--;
            if(top<=bottom)
            {
            for(int i=right;i>=left;i--)
                ans.push_back(arr[bottom][i]);
            bottom--;
            }
            if(left<=right)
            {
            for(int i=bottom;i>=top;i--)
                ans.push_back(arr[i][left]);
            left++;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends