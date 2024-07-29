class Solution {
public:
   
    int numTeams(vector<int>& rating) {
        int ans=0;
        int n= rating.size();
        for(int j=1;j<n-1;j++)
        {
            int ls=0,ll=0;
            for(int i=0;i<j;i++)
            {
                if(rating[i]<rating[j]) ls++;
                if(rating[i]>rating[j]) ll++;
            }
            int rl=0,rs=0;

            for(int i=j+1;i<n;i++)
            {
                if(rating[i]<rating[j]) rs++;
                if(rating[i]>rating[j]) rl++;

            }
            ans+= (ls*rl);
            ans+= (ll*rs);
        }
        return ans;
    }
};