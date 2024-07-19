class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        for(int i=0;i<n;i++){
            dp[i+1]=dp[i]+nums[i];
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dp[j]-dp[i]==k) ans++;
            }
        }
        return ans;
    }
};