class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;

        int i=0;
        int l=0;
        vector<int>freq(26,0);

        while(i<n){
            freq[s[i]-'A']++;
            int tot=i-l+1;
            int maxi=0;
            for(auto i:freq)    maxi=max(maxi,i);
            while(tot-maxi>k){
                freq[s[l]-'A']--;
                maxi=max(freq[s[l]-'A'],maxi);
                l++;
                tot--;
            }
            ans=max(ans,tot);
            i++;

        }
        


        return ans;
        
    }
};
