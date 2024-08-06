class Solution {
 

public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& v) {
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (v[i][j] != -1) {
            return v[i][j];
        }
        int r = 0, l = 0;
        if (i + 1 <= m - 1) {
            r += solve(i + 1, j, m, n, v);
        }
        if (j + 1 <= n - 1) {
            l += solve(i, j + 1, m, n, v);
        }
        return v[i][j] = l + r;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n, -1));

        return solve(0, 0, m, n, v);
    }
};