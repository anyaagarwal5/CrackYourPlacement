class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>ans;
        int n=matrix.size();
        int m= matrix[0].size();
        for(int i=0;i<n;i++)
        {
            int mi=100001;
            int ind;
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]<mi)
                {
                    mi=matrix[i][j];
                    ind=j;
                }
            }
            int mj=0;
            int in;
            for(int j=0;j<n;j++)
            {
                if(matrix[j][ind]>mj)
                {
                    mj=matrix[j][ind];
                    in=j;
                }
            }
            if(matrix[i][ind]==matrix[in][ind])
            {
                ans.push_back(matrix[i][ind]);
            }


        }
        return ans;
    }
};