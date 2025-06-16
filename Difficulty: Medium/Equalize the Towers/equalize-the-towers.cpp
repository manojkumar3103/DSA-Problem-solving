class Solution {
  public:
    int getCost(vector<int>& heights, vector<int>& cost,int val)
    {
        int total_cost=0;
        for(int i=0;i<heights.size();i++)
        {
            total_cost+= abs(heights[i]-val)*cost[i];
        }
        return total_cost;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int maxi=INT_MIN,mini=INT_MAX;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,heights[i]);
            mini=min(mini,heights[i]);
        }
        int ans=INT_MAX;
        while(maxi>=mini)
        {
            int mid1=mini + (maxi-mini)/3;
            int mid2=maxi- (maxi-mini)/3;
            
            int cost1=getCost(heights,cost,mid1);
            int cost2=getCost(heights,cost,mid2);
            ans=min(ans,min(cost1,cost2));
            if(cost1<cost2)
            {
                maxi=mid2-1;
            }
            else
            {
                mini=mid1+1;
            }
        }
        return ans;
    }
};
