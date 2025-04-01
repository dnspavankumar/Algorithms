class Solution {
  public:
  //construct longest prefix suffix array
    
    vector<int> construct_lps(string& pat)
    {   
        int m=pat.size();
        vector<int> lps(m,0);
        int i=1;
        int j=0;
        while(i<m){
            if(pat[i]==pat[j]){
                lps[i]=j+1;
                i++;
                j++;
            }
            else if(j>0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
        return lps;
    }
    vector<int> search(string& pat, string& txt) {
        vector<int>lps= construct_lps(pat);
        vector<int> ans;
        int i=0;
        int j=0;
        while(i<txt.size()){
            if(txt[i]==pat[j]){
                i++;
                j++;
                if(j==pat.size()){
                    ans.push_back(i-j);
                    j=lps[j-1];
                }
            }
            else if(j>0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
        return ans;
    }
