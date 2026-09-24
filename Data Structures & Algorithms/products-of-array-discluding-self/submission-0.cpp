class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int ct=0;

        for(auto i:nums){
            if(i!=0)    prod*=i;
            else    ct++;
        }

        vector<int>ans(nums.size(),0);
        if(ct>1) return ans;
        for(int i=0;i<nums.size();i++){
            if(ct==1){
                if(nums[i]==0)  {ans[i]=prod;break;}
            }else{
                ans[i]=prod/nums[i];

            }
        }   
        return ans;
    }
};
