//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfsUtil(vector<vector<int>>& image,int m,int n, int origColor,
                int newColor,int sr,int sc)
    {
        if(sc<0 || sr<0 || sr>=n || sc>=m) return;
        
        if(image[sr][sc]!=origColor || image[sr][sc]==newColor)
            return;
        
        image[sr][sc]=newColor;
        dfsUtil(image,m,n,origColor,newColor,sr-1,sc);
        dfsUtil(image,m,n,origColor,newColor,sr+1,sc);
        dfsUtil(image,m,n,origColor,newColor,sr,sc-1);
        dfsUtil(image,m,n,origColor,newColor,sr,sc+1);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int n=image.size(),m=image[0].size();
        int origColor = image[sr][sc];
        if (origColor != newColor)
            dfsUtil(image,m,n,origColor,newColor,sr,sc);
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends