class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>la(n,0);
        for(int i=1;i<n;i++)
        {
            la[i]= la[i-1];
            if(s[i-1]=='b') la[i]++;
        }
        vector<int>rb(n,0);
        for(int i=n-2;i>=0;i--)
        {
            rb[i]= rb[i+1];
            if(s[i+1]=='a') rb[i]++;
        }
        int ans=n;
        for(int i=0;i<n;i++)
        {
            ans= min(ans,la[i]+rb[i]);
        }
        return ans;
    }
};