//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int result=0;
        int start=0,end=arr.size()-1;
        
        while(start<end)
        {
            int sum=arr[start]+arr[end];
            //cout<<start<<" "<<end<<endl;
            if(sum>target)
            {
                end--;
            }
            else if(sum<target)
            {
                start++;
            }
            else
            {
                int e1=arr[start],e2=arr[end],c1=0,c2=0;
                while(start<=end && arr[start]==e1)
                {
                    start++;
                    c1++;
                }
                
                while(start<=end && arr[end]==e2)
                {
                    end--;
                    c2++;
                }
                
                if(e1==e2)
                {
                    result+=(c1*(c1-1))/2;
                }
                else
                {
                    result+=(c1*c2);
                }
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
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends