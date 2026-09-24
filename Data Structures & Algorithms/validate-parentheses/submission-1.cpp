class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto i:s){
            if(i=='}'){
                if(st.empty() || st.top()!='{') return false;
                st.pop();
            }else if(i==')'){
                if(st.empty() || st.top()!='(') return false;
                st.pop();
            }else if(i==']'){
                if(st.empty() || st.top()!='[') return false;
                st.pop();
            }else   st.push(i);
        }
        return st.empty();
    }
};
