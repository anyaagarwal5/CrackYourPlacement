class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int Max=0;
        int n=prices.size();
        for(int i=1;i<n;i++)
        {
            int cost=prices[i]-mini;
            Max=max(Max,cost);
            mini=min(mini,prices[i]);
        }
        return Max;
    }
};