class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;

        int i=0;
        int n=s.size();

        int l=0;
        unordered_set<int>st;

        while(i<n){
            char ch=s[i];
            while(!st.empty() && st.find(ch)!=st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(ch);
            len=max(len,(i-l+1));
            i++;
        }
        return len;
    }
};
