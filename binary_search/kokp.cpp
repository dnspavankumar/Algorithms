class Solution {
  public:
    int feasible(vector<int>& arr , int mid,int given_hours){
        int total_hours=0;
        for(int i:arr){
            total_hours+=ceil((double)i/mid);
        }
        return total_hours<=given_hours;
    }
    int kokoEat(vector<int>& arr, int k) {
        int m=*max_element(arr.begin(),arr.end());
        int low=1;
        int high=m;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(feasible(arr,mid,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
