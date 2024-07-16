class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0; 
    int n = nums.size();
    int k = 1; 
    
    for (int i = 1; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < k; ++j) {
            if (nums[i] == nums[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            nums[k] = nums[i];
            k++; 
        }
    }
    
    return k; 
}
   
};