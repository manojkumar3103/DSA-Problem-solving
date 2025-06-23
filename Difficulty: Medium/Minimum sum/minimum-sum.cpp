// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        string odd="",even="";
        
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                even+=std::to_string(arr[i]);
            }
            else
            {
                odd+=std::to_string(arr[i]);
            }
        }
        
        //addition of two strings
        int n1=odd.size()-1;
        int n2=even.size()-1;
        int carry=0;
        string result="";
        while(n1>=0 || n2>=0)
        {
            int digit1=(n1>=0)? odd[n1--]-'0':0;
            int digit2=(n2>=0)? even[n2--]-'0':0;
            
            int add=(digit1+digit2)+carry;
            result+=std::to_string(add%10);
            carry=add/10;
        }
        if(carry!=0) result+=std::to_string(carry);
        reverse(result.begin(), result.end());
        size_t nonZeroPos = result.find_first_not_of('0');
        return (nonZeroPos != std::string::npos) ? result.substr(nonZeroPos) : "0";
    }
};
