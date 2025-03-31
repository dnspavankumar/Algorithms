 int maxSubarraySum(vector<int> &arr) {
        int n=arr.size();
        int current_sum=0;
        int max_sum=INT_MIN;
        for(int i=0;i<n;i++){
            current_sum+=arr[i];
            max_sum=max(max_sum,current_sum);
            if(current_sum<0){
                current_sum=0;
            }
        }
        return max_sum;
 }
