class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int mini=min(0,nums[0]);

        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
            ans=max(ans,nums[i]-mini);
            mini=min(mini,nums[i]);
        }
        return ans;

    }
};
