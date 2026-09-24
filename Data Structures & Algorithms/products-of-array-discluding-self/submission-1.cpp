class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==0)  return {};
        int  pref=nums[0];
        vector<int>ans(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            ans[i]=pref;
            pref*=nums[i];
        }       
        int post=nums.back();
        for(int i=nums.size()-2;i>=0;i--){
            ans[i]*=post;
            post*=nums[i];
        }
        return ans;

    }
};
