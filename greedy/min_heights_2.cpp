 int getMinDiff(vector<int> &arr, int k) {
        int n=arr.size();
        //sort the array for decision making
        sort(arr.begin(),arr.end());
        //intitially the min defference would be
        //arr[n-1]-k-arr[0]+k = arr[n-1]-arr[0]
        int minimum_difference=arr[n-1]-arr[0];
        /*now check if any element :
        i)on adding k becomes the maximum
        ii)becomes minimum on subtracting k
        */
        int minimum=arr[0]+k;
        int maximum=arr[n-1]-k;
        for(int i=1;i<n;i++){
            if(arr[i]<k)continue;
            int new_minimum=min(arr[i]-k,minimum);
            int new_maximum=max(arr[i-1]+k,maximum);
            minimum_difference=min(new_maximum-new_minimum,minimum_difference);
        }
        return minimum_difference;
    }
