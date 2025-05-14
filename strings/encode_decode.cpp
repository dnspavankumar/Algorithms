class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(string str:strs){
            ans+=str+'.';
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        string temp="";
        for(int i=0;i<s.size();++i){
            if(s[i]=='.'){
                ans.push_back(temp);
                temp="";
                i++;
            }
            temp+=s[i];
        }
        return ans;
    }
};
