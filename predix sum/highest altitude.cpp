class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>p(gain.size()+1);
        int sum=0;
        p[0]=0;
        for(int i=1;i<p.size();i++){
            sum+=gain[i-1];  
            p[i]=sum; 
        }
        return *max_element(p.begin(),p.end());
    }
};
