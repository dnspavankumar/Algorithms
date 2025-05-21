class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>p(nums.size()+1);
        int sum=0;
        p[0]=0;
        for(int i =1;i<=nums.size();i++){
            sum+=nums[i-1];
            p[i]=sum;
        }
        int n=p.size()-1;
        for(int i=1;i<p.size();i++){
            if(p[i-1]==p[n]-p[i])return i-1;
        }
        return -1;
    }
};
