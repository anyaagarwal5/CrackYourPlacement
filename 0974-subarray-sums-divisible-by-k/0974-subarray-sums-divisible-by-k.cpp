class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
        int sum=0;
        unordered_map<int,int>prefixSum;
        prefixSum[0]=1;
        for(int num:nums)
        {
            sum+=num;
            int mod=sum%k;
            if(mod<0)
            mod+=k;
            if(prefixSum.find(mod)!=prefixSum.end()){
                count+=prefixSum[mod];
                prefixSum[mod]+=1;
            }
            else
            prefixSum[mod]=1;
        }
        return count;
    }
};