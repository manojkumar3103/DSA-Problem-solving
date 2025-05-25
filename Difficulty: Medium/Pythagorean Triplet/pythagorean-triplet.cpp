class Solution {
  public:
    
    bool triplet(int target, vector<int>& arr,int start,int end)
    {
        while(start<end)
        {
            int sum = arr[start] + arr[end];
            if (sum == target)
                return true;
            else if (sum < target)
                start++;
            else
                end--;
        }
        return false;
    }
    
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        unordered_set<int> squares;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            arr[i] = arr[i] * arr[i];
            squares.insert(arr[i]);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = arr[i] + arr[j];
                if (squares.count(sum))
                    return true;
            }
        }

        return false;
    }
};