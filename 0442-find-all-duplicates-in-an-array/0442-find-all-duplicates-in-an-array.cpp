class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int index;
            if(nums[i] > 0)
                index = nums[i] - 1;
            else
                index = -nums[i] - 1;
            
            if(nums[index] < 0)
                ans.push_back(index + 1);
            else
                nums[index] = -nums[index];
        }
        return ans;
    }
};
