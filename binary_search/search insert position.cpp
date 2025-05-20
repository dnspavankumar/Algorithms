class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        if(arr[0]>target)return 0;
        if(target>arr[arr.size()-1])return arr.size();
        int low=0;int high=arr.size()-1;int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=target){
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
