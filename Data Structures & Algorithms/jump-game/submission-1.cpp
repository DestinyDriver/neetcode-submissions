class Solution {
public:
    bool canJump(vector<int>& nums) {
        int r=nums[0];

        if(nums.size()==1)  return true;
        // if(nums.size()==2 && nums[0]=0)    return f;


        for(int i=1;i<nums.size();i++){
            if(i>r) return false;
            r=max(r,i+nums[i]);
        }
        return true;
        
    }
};
