class Solution {
    string delim=",,";
    string sep="||";
public:

    string encode(vector<string>& strs) {




        string ans="";
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()==0){
                ans+="*";
                ans+=delim;
                continue;
            }

            char prev=strs[i][0];
            int ct=1;

            for(int j=1;j<strs[i].size();j++){
                char curr=strs[i][j];

                if(curr==prev){
                    ct++;
                }else{
                    ans+=prev;
                    ans+=(to_string(ct));
                    ans+=sep;
                    ct=1;
                    prev=curr;
                }
            }
            
            ans+=prev;
            ans+=(to_string(ct));

            ans+=delim;
        }
        cout<<ans;
        return ans;


    }

    vector<string> decode(string s) {
        int i=0;
        int n=s.size();
        vector<string>ans;
        string tmp="";


        while(i<n){
            char ch=s[i];
            i++;
            if(ch==delim[0] && s[i]==delim[1]){
                ans.push_back(tmp);
                cout<<tmp<<endl;
                tmp="";
                i++;
            }else if(ch=='*' && (s[i]=='|' || s[i]==',')){
                tmp="";
            }else{
                // a9|,
                int ct=0;
                while(i<n && s[i]>='0' && s[i]<='9'){
                    ct=ct*10+(s[i]-'0');
                    i++;
                }
                while(ct--){
                    tmp+=ch;
                }
                if(s[i]==sep[0] && s[i+1]==sep[1])
                i+=2;
            }

            
        }
        return ans;

    }
};
