int maximumSumSubarray(vector<int>& arr, int k) {
        //window pointers
        int constructor_pointer=0;
        int destructor_pointer=0;
        //caching variables
          //window caching variable
            int window_sum=0;
          //global caching variable
            int max_sum=0;
        /*window expansion
        Taking the constructor pointerto required size and
        caching the required answer
        */
        while(constructor_pointer<k){
            window_sum+=arr[constructor_pointer];
            constructor_pointer++;
        }
        max_sum=window_sum;
        /*window sliding:
        moving constructor and destructor p[ointer by one step
        generating a slide
        */
        while(constructor_pointer<arr.size()){
            window_sum+=arr[constructor_pointer]-arr[destructor_pointer];
            max_sum=max(max_sum,window_sum);
            constructor_pointer++;
            destructor_pointer++;
        }
        return max_sum;
    }
