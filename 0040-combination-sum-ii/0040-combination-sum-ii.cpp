class Solution {
public:
    void combo(vector<int>& arr, int target, int ind, vector<int>& t, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(t);
            return;
        }

        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;
            t.push_back(arr[i]);
            combo(arr, target - arr[i], i + 1, t, ans);
            t.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> t;
        combo(candidates, target, 0, t, ans);
        return ans;
    }
};
