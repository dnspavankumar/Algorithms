class Solution {
public:
    bool v(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    int maxVowels(string s, int k) {
        int ans=INT_MIN;
        int count=0;
        int i=0;
        int j=0;
        while(j<k){
            if(v(s[j]))count++;
            j++;
        }
        ans=max(ans,count);
        while(j<s.size()){
            if(v(s[i])){
                count--;
            }
            if(v(s[j])){
                count++;
            }
            i++;
            j++;
            ans=max(count,ans);
        }
        return ans;
    }
};
