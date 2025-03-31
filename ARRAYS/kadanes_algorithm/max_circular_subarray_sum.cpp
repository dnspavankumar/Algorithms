/*we have two possibilities for the maximum circular subarray sum
i) linear maximum subarray sum(kadanes algorithm) is the circular maximum subarray sum
ii)subarray sum obtained by removing the minimum subarray sum
*/


// linear maximum subarray sum
int linear(vector<int>arr){
        int current_sum=0,maximum_subarray_sum=INT_MIN;
        for(int i=0;i<arr.size();i++){
            current_sum+=arr[i];
            maximu_subarray_sum=max(maximum_subarray_sum,current_sum);
            if(current_sum<0){
              current_sum=0;
            }
        }
        return maximum_subarray_sum;
    }

//circular maximum subarray sum
    int circularSubarraySum(vector<int> &arr) {
        int min_sum=arr[0];
        int curr_min=arr[0];
        int total_sum=0;
        for(int i=0;i<arr.size();i++){
            total_sum+=arr[i];
            if(i>0){
            curr_min=min(arr[i],curr_min+arr[i]);
            min_sum=min(curr_min,min_sum);
            }
        }
        return max(total_sum-min_sum,linear(arr));
    }
