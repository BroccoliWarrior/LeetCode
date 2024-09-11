class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = 0;
        if (nums.size() == 0)
            return res;
        if(nums.size() == 1)
            return nums[0];
        vector<int> s(nums.size() + 1);
        
        for (int i = 0; i < nums.size(); i++) {
            s[i + 1] = s[i] + nums[i];
        }
        res = s[1];
        
        for (int r = 1; r < nums.size() + 1; r++) {
            for (int l = 0; l < r; l++) {
                res = max(s[r]-s[l], res);
            }
        }
        
        return res;
    }
};
