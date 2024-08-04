class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        int ind=0;
        left--; right--;

        while(ind<=right && pq.size())
        {
            auto it= pq.top();
            int sub= it.first;
            int i=it.second;
            pq.pop();
            if(ind>=left)
            {
                ans= (ans+it.first)%1000000007;

            }
            if(it.second<n-1)
            {
                pq.push({it.first+nums[i+1],i+1});
            }

            ind++;
        }
        return ans;
    }
};