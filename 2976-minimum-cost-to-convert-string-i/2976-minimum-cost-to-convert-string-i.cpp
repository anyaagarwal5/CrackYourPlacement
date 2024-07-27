class Solution {
public:
    void distra(vector<vector<pair<int,int>>>&g,vector<vector<int>>&tcost, int s)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,s});

        while(!pq.empty())
        {
            auto it= pq.top();
            pq.pop();
            int u=it.second;
            int w= it.first;
            for(auto iti: g[u])
            {
                int v= iti.first;
                int wei= iti.second;
                if(w+wei < tcost[s][v])
                {
                    tcost[s][v]= w+wei;
                    pq.push({tcost[s][v],v});

                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans=0;
        vector<vector<pair<int,int>>>g(26);
        int n=cost.size();
        for(int i=0;i<n;i++)
        {
            g[original[i]-'a'].push_back({(int)changed[i]-'a',cost[i]});
        }
        vector<vector<int>>tcost(26,vector<int>(26,INT_MAX));
        for(int i=0;i<26;i++)
        {
            tcost[i][i]=0;
            if(g[i].size()>0)
                distra(g,tcost,i);

        }
        for(int i=0;i<source.size();i++)
        {
            int s= source[i]-'a';
            int d= target[i]-'a';
            if(tcost[s][d]==INT_MAX) return -1;
            ans+= tcost[s][d];
        }
        return ans;

    }
};