

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int freq = nums[0];
        int n = nums.size();
        int c = 1;

        for (int i = 0; i < n; ++i) { 
            if (nums[i] == freq) {
                c++;
            } else {
                c--;
                if (c == 0) {
                    freq = nums[i];
                    c = 1;
                }
             }
        }
        
        return freq;
    }
};
