class Solution {
    public:
    int f(int i, int n,int buy,vector<int>& prices,vector<vector<int>>&dp,int fee){
        if(i==n)
        return 0;
        if(dp[i][buy]!=-1)
        return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max((-prices[i]-fee+f(i+1,n,0,prices,dp,fee)),0+f(i+1,n,1,prices,dp,fee));
        }
        else{
            profit=max((prices[i]+f(i+1,n,1,prices,dp,fee)),0+f(i+1,n,0,prices,dp,fee));
        }
        return dp[i][buy]= profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
      int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int ans= f( 0, n, 1, prices,dp,fee);
        return ans;  
    }
};