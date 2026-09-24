class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        unordered_set<int>st;
        for(auto i:nums){
            st.insert(i);
        }
        int ans=1;
        for(int i=0;i<nums.size();i++){
            int stt=nums[i];
            if(st.find(stt-1)!=st.end()) continue;
            int ct=1;
            while(st.find(stt+1)!=st.end()){
                ct++;
                stt++;
            }
            ans=max(ans,ct);
        }
        return ans;
        
    }
};
