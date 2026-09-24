class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i-1>=0 && nums[i]==nums[i-1])  continue;

            int l=i+1;
            int r=n-1;

            while(l<r){
                

                if(nums[l]+nums[r]+nums[i]==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;r--;
                    while(l<r && nums[l]==nums[l-1])    l++;
                    while(l<r && r+1<n&& nums[r]==nums[r+1])    r--;
                }else if(nums[l]+nums[r]+nums[i]<0){
                    l++;

                }else{
                    r--;
                } 

                

            }
        }
        return ans;

        
    }
};
