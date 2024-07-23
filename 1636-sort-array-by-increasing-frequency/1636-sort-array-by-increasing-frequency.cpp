class Solution {
public:
    static bool sortcol(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.first==b.first) return a.second>b.second;

        return a.first<b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        vector<pair<int,int>>v;
        vector<int>ans;
        for(auto it:mp)
        {
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),sortcol);
        for(auto it:v)
        {
            int t= it.first;

            while(t--)
            ans.push_back(it.second);
        }
        return ans;

    }
};