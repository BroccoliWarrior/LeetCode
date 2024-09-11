class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        // if(k == 1){
        //     res = nums;
        //     return res;
        // }
        int maxval = 0;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            maxval = nums[i];
            for (int j = i; j < i + k; j++) {
                maxval = max(nums[j], maxval);
                
            }
            res.push_back(maxval);
        }
        return res;
    }
};
